/* Danielle, Dr. Lehr, and
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created: December 17, 2023, 2 PM
 * Purpose:  cis 17c final prb 5 avl tree vs hash v1
 * Code is based off AVL_binaryTree_3 and combines final>prb1_hash_v3
 * 
 * v1:
 * Pushed indx = hash%512 into linked list AND AVL tree,
 * but i think i was supposed to only push hash into AVL tree.
 * 
 * Removed dupe hash%SIZE nodes before inserting it into AVL tree
 * 
 * To do: 
 * 
 * Notes: Hash has dupe nodes and a binary tree isn't supposed to have any
 *        dupe nodes.
 */

//System Libraries
#include<iostream>
#include<iomanip>
#include<algorithm>
#include <vector>
using namespace std;
 
//User Libraries
#include "AVLTree.h"      // AVL binary tree
#include "SimpleVector.h" // Hash using array of linked list
//Global Constants


// Hash Function Prototypes
int h1(string); // Switch converts string to corresponding phone numbers
string h2(string);
//int h3(string);
void setHashes(const vector<string>, vector<int> &);
void setInitials(string &);
void setLetters(vector<string>&);//Generate container of random 3 letter strings
void askUser4Hash(const vector<string>, const vector<int>);
void prntHashes(const vector<string>, const vector<int>);
void prntVecStr(vector<string>);
void prntVecInt(vector<int> &, int perLine=10);//Prints indices used in simple vector


//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers    
    
    //***************************************************************************
    // Create container of 512 strings that represent a person's 3-lettered initials
    //***************************************************************************
    const int SIZE=512;     // size of linked list array   
    string str=" ";         // User's initials      
    vector<string> vecStr;  // Container of random 3 letter strings
    vector<int>    vecHash; // Container of hashed 3 letter strings
    setLetters(vecStr);   // Generate container of random 3 letter strings 
    setInitials(str); //  Prompt for user's initials
    vecStr.push_back(str); // Push user's initials into container
    setHashes(vecStr,vecHash); // Hash the container of 3 letter strings  
    
    //***************************************************************************
    //              Hash the container of 3 letter strings     
    //***************************************************************************
  
    setHashes(vecStr,vecHash);      
    
    //**************************************************************************
    //              PUSHING MOD HASHES INTO LINKED LIST
    //**************************************************************************
   
    int n=SIZE+1,// +1 compensates for the [0]=0 created in constructor
        num=0, 
        indx=0;  
    SimpleVector<int> *sv;// Allocating  memory for a static array of Linked Lists
    
    // Can't figure out how to initialize static array of linked list 
    // without setting linkedListHead->data=0, so
    // +1 compensates for the [0]=0 created in constructor
    sv = new SimpleVector<int>[SIZE];//SimpleVector<int> sv(size);
    vector<int>::iterator it;
    
    //cout<<"\nSetting Hashes in Simple Vector's Array of Linked List...\n";
    for(int i=0;i<SIZE;i++){
        
        num = vecHash[i]; // Get hashed number. // num = rand()%26+65;
        indx=num%SIZE;   // indx for Simple Vector static array
        sv[indx].pushBack(num);// Save hash to linked list    
            
        //cout << setw(3) << i << ". ["<< num <<"%512] = "
             //<< setw(2) << sv[indx].size()-1 << " crashes = ";
            //sv[indx].prntSV(); // print hashes that were stored in linked list 
    }
    
    // Print results
    //cout<<"\tVector of hashed initials:\n";
    //prntVecStr(vecStr);   // Print vector of all random 3-lettered initials
    //prntVecInt(vecHash);  // Print vector of all hashed initials
    cout<<"\n\n  Initials Hashed and hash%512:\n";
    prntHashes(vecStr,vecHash); // Prints each string and its hash
    
    
    //***************************************************************************
    //              AVL Tree Section of 3 letter strings     
    //***************************************************************************
    
    AVLTree avl;
    int num2=0;  
    vector<int> indxUsed1x;
    
    // Get rid of any dupe nodes before pushing it into the binary tree
    // Save single instance of the indx hashes that were used to a vector
    for(int i=0;i<SIZE;i++){
        num2 = vecHash[i]; // Get hashed number. //num = rand()%26+65;
        indx=num2%SIZE;   // node indx for AVL Tree
        it = std::find(indxUsed1x.begin(), indxUsed1x.end(), indx);
        if(it==indxUsed1x.end()){indxUsed1x.push_back(indx);} // keep track of indices used
         
    }   
        
    // Fill tree with container of hashes that have to dupe nodes
    for(int i=0;i<indxUsed1x.size();i++){     
        num2 = indxUsed1x[i]; // Get hashed number. //num = rand()%26+65;
        indx=num2%SIZE;      // node indx for AVL Tree
        avl.root = avl.insert(avl.root, indx); // Push modIndx node into tree
    } 
    
    // Print results  
    cout<<endl<<endl<<"Duep nodes removed.\nIn-order Traversal:"<<endl;
    avl.inorder(avl.root);    
    
    
    
    
    //******************************************************************************
    //                  Delete Random node from Tree  
    //******************************************************************************   
    //    // Delete nodes from tree
    //    vector<int>::iterator it2;
    //    vector<int> deleted;
    //    for(int i=0;i<4;i++){ 
    //        int num1 = rand()%vecHash.size();// [0,15)
    //        it2 = vecHash.begin()+num1;
    //        deleted.push_back(vecHash[num1]);
    //        avl.deleteBNT(avl.root,vecHash[num1]);
    //        vecHash.erase(it2);
    //    }
    //cout<<endl<<endl<<"In-order Traversal after Deletion:"<<endl;
    //avl.inorder(avl.root); cout<<endl;    
    //cout<<endl<<deleted.size()<<" Nodes Randomly Deleted:\n";
    //for(int i=0;i<deleted.size();i++){cout<<deleted[i]<<" ";}cout<<endl;
    
    //Exit stage right!
    return 0;
}

//******************************************************************************
//                  Hash Function Implementations  
//******************************************************************************


//******************************************************************************
//         Converts a 3 letter string into a 3 digit string based on 
//          the buttons on a phone. Returns a number. "MEL" -> 635 
//******************************************************************************
int h1(string str){
    int seed;
    int hash=0;
    for(int i=0;i<str.size();i++){    
        switch(str[i]){
            case 'A': case 'B': case 'C':{ seed=2; break;}
            case 'D': case 'E': case 'F':{ seed=3; break;}
            case 'G': case 'H': case 'I':{ seed=4; break;}   
            case 'J': case 'K': case 'L':{ seed=5; break;}
            case 'M': case 'N': case 'O':{ seed=6; break;}
            case 'P': case 'Q': case 'R': case 'S':{ seed=7; break;}
            case 'T': case 'U': case 'V': { seed=8; break;}
            case 'W': case 'X': case 'Y': case 'Z':{ seed=9; break;}
        }         
        hash = (hash * 10) + seed;
    }    
    return hash;
}


//******************************************************************************
//              Hash the container of 3 letter strings
//******************************************************************************

void setHashes(const vector<string> vecStr, vector<int> &vecHash){
    int hash=0;
    vector<int>::iterator it;
    for(int i=0;i<vecStr.size();i++){   
        hash=h1(vecStr[i]);// Calls hash1 function
        //cout<<left<<setw(2)<<i<<". Hash: "<<hash<<" %512 = "<<hash%512<<endl;
        vecHash.push_back(hash); 
    }
}

//******************************************************************************
//              Generate container of random 3 letter strings
//******************************************************************************

void setLetters(vector<string> &vecStr){
    const int SIZE=511;
    char ch1,ch2,ch3;
    string letters="";
    vector<int>::iterator it;
    for(int i=0;i<SIZE;i++){   
        for(int j=0;j<3;j++){
            ch1 = 65+(rand()%26); //A-Z[65,90]  
            letters+=ch1;
            //cout<<ch1<<" ";
        }//cout<<letters<<" "<<endl;
        vecStr.push_back(letters); 
        letters="";
    }
}

//******************************************************************************
//              Get user's 3 initials
//******************************************************************************

void setInitials(string &str){
    str="MEL";
    //cout<<"Input 3 letters that represent your initials.\n";
    //cin>>str;
}

//******************************************************************************
//              Print container of strings and hashes
//******************************************************************************

void prntHashes(const vector<string> vecStr, const vector<int> vecHash){
    int index=0, hash=0;
    
    // Notice: vecHash is bigger than vecStr cause there's dupe nodes
    //cout<<"\tvecHash.size() = "<<vecHash.size() <<endl;
    
                   cout<<setw(3)<<"cnt"<<". Str "<<" = "<<"hash %512 = modIndex"<<endl;
    for(int i=0;i<vecStr.size();i++){   
        hash = h1(vecStr[i]);// Calls hash1 function
        cout<<right<<setw(3)<<i<<".  "<<vecStr[i]<<" = "<<hash<<" %512 = "<<hash%512<<endl;
    }  
}

void askUser4Hash(const vector<string> vecStr, const vector<int> vecHash){
    int index=0, hash=0;
    do{
        cout<<endl<<"Enter a number between 0 and "<<vecHash.size()-1
            <<". To exit enter: -66\n";
        cin>>index;
        if(index>=0 && index<=vecHash.size()-1){
            hash=vecHash[index];
            cout<<"["<<index<<"] = "<<vecStr[index]<<" = "<<hash<<" % 512 = "<<hash%512<<endl;
        }
    } while(index!=-66 || (index>=0 && index<=vecHash.size()-1));
}
    
//******************************************************************************
//              Print container of random 3 lettered strings
//******************************************************************************

void prntVecStr(vector<string> vecStr){        
    cout<<"\n\n\tVector of random 3 initials:\n";
    for(int i=0;i<vecStr.size();i++){ 
        cout<<vecStr[i]<<" ";
        if(i%10==9){cout<<endl;}
    } cout<<endl<<endl<<endl;
}

//******************************************************************************
//              Print container of hashed integers
//******************************************************************************

void prntVecInt(vector<int> &vecStr, int perLine){  
    cout<<"vector size: "<<vecStr.size()<<endl;
    for(int i=0;i<vecStr.size();i++){
        cout<<setw(3)<<vecStr[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    } cout<<"}"<<endl;
}
/* Danielle, Dr. Lehr, and
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created: December 17, 2023, 2 PM
 * Purpose:  cis 17c final prb 5 avl tree vs hash v3
 * Code is based off AVL_binaryTree_3 and combines final>prb1_hash_v3
 * 
 * v3:
 * Changed search for node to a static node that is in the hash container.
 * return number of nodes it took to find it using hash versus AVL.
 * 
 * To do: 
 * Add reverse hash function
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
//int nodeCount;

// Hash Function Prototypes
int h1(string); // Switch converts string to corresponding phone numbers
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
    sv = new SimpleVector<int>[SIZE]();//SimpleVector<int> sv(size);
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
    int hash=0;  
//    vector<int> indxUsed1x;
//       
//    
//    // Get rid of any dupe nodes before pushing it into the binary tree
//    // Save single instance of the indx hashes that were used to a vector
//    for(int i=0;i<SIZE;i++){
//        hash = vecHash[i]; // Get hashed number. 
//        it = std::find(indxUsed1x.begin(), indxUsed1x.end(), hash);
//        if(it==indxUsed1x.end()){indxUsed1x.push_back(hash);} // keep track of indices used
//         
//    } 
//    
//    //cout<<"\n\nUnique indices used in hash"<<endl;
//    sort(indxUsed1x.begin(), indxUsed1x.end());
//    //prntVecInt(indxUsed1x);  // Print vector of all hashed initials
//    
    // Sort hashes before inserting into binary tree
    sort(vecHash.begin(), vecHash.end());
    //prntVecInt(vecHash);  // Print vector of all hashed initials
    
    
    // Fill tree with container of hashes that have to dupe nodes
    for(int i=0;i<vecHash.size();i++){     
        hash = vecHash[i]; // Get hashed number. //num = rand()%26+65;
        avl.root = avl.insert(avl.root, hash); // Push modIndx node into tree
    } 
    
    
    
    //***************************************************************************
    //          Compare number of nodes to find an index 
    //          in a hash Linked List versus an AVL tree 
    //***************************************************************************
    // Hashed Linked List Search
    int rNum = rand()%SIZE; // indxUsed1x.size();
    string fndStr = vecStr[511];
    int findNode = h1(fndStr); 
    int modIndx = findNode%SIZE;
    
    cout<<endl<<endl;
    cout<<"Locating "<< fndStr << " = " << findNode << endl;
    cout<<"Number of Hashes: "<<vecHash.size()<<endl<<endl;
    cout<<"Searching hash for node: "<< findNode <<endl;    
    bool findIndx = false;
    for(int i=0;i<SIZE;i++){
        findIndx = sv[i].find(findNode); // (modIndx);
        if(findIndx){
            cout << "Hash node " << findNode << " was found.\n";
            cout<<sv[i].getElementAt(1)<<" = "; //sv[i].getElementAt(1);
            sv[rNum].prntSV(); // print hashes that were stored in linked list 

            cout<<"*Couldn't figure out how to initialize static array of linked list" 
                <<"\nwithout setting linkedListHead->data=0\n";
            break;
        } 
    }
    if(!findIndx){cout << findNode << " was not found. Searched ";} 
    
    
    // AVL Tree Search
    cout<<endl<<endl;
    cout<<"Searching AVL Tree for node: "<< findNode <<endl;
    cout<<"Tree height: "<<avl.height(avl.root)<<endl;
    
    bool isFound = avl.AVLsearch(avl.root, findNode);//(avl.root, vecHash[rNum]);
    if(isFound){
        cout << findNode << " was found in AVL tree in " << avl.nodeCount << " nodes.\n";        
    } else {
        cout << findNode << " was not found in AVL tree. Searched " << avl.nodeCount << " nodes.\n";
    }
    
    
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
    
    // Sort hashes before inserting into binary tree
    //sort(vecHash.begin(), vecHash.end());
    //prntVecInt(vecHash);  // Print vector of all hashed initials
    
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
    cout<<"Hash vector size: "<<vecStr.size()<<endl;
    for(int i=0;i<vecStr.size();i++){
        cout<<setw(3)<<vecStr[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    } cout<<"}"<<endl;
}
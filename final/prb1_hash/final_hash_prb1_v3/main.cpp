/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-07-2023 @ 6 PM
 * Purpose: CIS-17C Final problem 1 v3
 * 
 * v3:
 * 
 * To do:
 * Push vector of hashes into a linked list.
 * Count number of collisions.
 * Make h2() hash with the map('A',2) instead of h1()'s switch case.
*/

//System Libraries
#include <bits/stdc++.h> 
//#include <fstream>
//#include <cmath>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
int h1(string); // Switch converts string to corresponding phone numbers
string h2(string);
//int h3(string);
void setHashes(const vector<string>, vector<int> &);
void setInitials(string &);
void setLetters(vector<string>&);//Generate container of random 3 letter strings
void prntVec(vector<string>);
void prntVec(vector<int>);
void prntHashes(const vector<string>, const vector<int>);


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
        
    srand(static_cast<unsigned int>(time(0))); //Set random number seed once here
    //rand()%90+10;//2 digit numbers    
    
    //Declare & initialize variables    
    const int SIZE=512;  // size of linked list array   
    string str=" ";      // User's initials      
    vector<string> vec; // Container of random 3 letter strings
    vector<int> vInt;   // Container of hashed 3 letter strings
    int collsn0,collsn1,collsn2,collsn3;
    collsn0=collsn1=collsn2=collsn3=0;
    
    // Map inputs to outputs
    setLetters(vec);   // Generate container of random 3 letter strings 
    setInitials(str); //  Prompt for user's initials
    vec.push_back(str); // Push user's initials into container
    setHashes(vec,vInt); // Hash the container of 3 letter strings
    
        
    // Outputs
    cout<<"You entered: "<<str<<endl;
    cout<<"["<<SIZE-1<<"]="<<vec[SIZE-1]<<"="<<vInt[SIZE-1]<<" %512 = "<<vInt[SIZE-1]%512<<endl<<endl;
    //prntVec(vec); // Print vector of random 3 letter initials
    //prntVec(vInt);  // Print vector of  hashed initials
    prntHashes(vec,vInt);
    
    
    // Linked List Report
//    cout<<endl<<endl<<"Linked List Collision Report:\n";
//    cout<<"No collisions: "<<collsn0<<endl;
//    cout<<"1  collisions: "<<collsn1<<endl;
//    cout<<"2  collisions: "<<collsn2<<endl;
//    cout<<"3  collisions: "<<collsn3<<endl;
    
    return 0;
}

//******************************************************************************
//                  Function Implementations  
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
//         Hash a 3 letter string into a 3 digit string based on 
//          the buttons on a phone. Returns a number. "MEL" -> 635 
//******************************************************************************

string h2(string str){
    string temp="h2";    
    unordered_map<char, int> phone = {
        {'A', 2}, {'B', 2}, {'C', 2},
        {'D', 3}, {'E', 3}, {'F', 3},
        {'G', 4}, {'H', 4}, {'I', 4},
        {'J', 5}, {'K', 5}, {'L', 5},
        {'M', 6}, {'N', 6}, {'O', 6},
        {'P', 7}, {'Q', 7}, {'R', 7}, {'S', 7},
        {'T', 8}, {'U', 8}, {'V', 8},
        {'W', 9}, {'X', 9}, {'Y', 9}, {'Z', 9}
    };
    
    //for(int i=0;i<str.size();i++){ 
        
    //}
   return temp;  
}


//******************************************************************************
//              Hash the container of 3 letter strings
//******************************************************************************

void setHashes(const vector<string> vec, vector<int> &vInt){
    int hash=0;
    vector<int>::iterator it;
    for(int i=0;i<vec.size();i++){   
        hash=h1(vec[i]);
        //cout<<left<<setw(2)<<i<<". Hash: "<<hash<<" %512 = "<<hash%512<<endl;
        vInt.push_back(hash); 
    }
}

//******************************************************************************
//              Generate container of random 3 letter strings
//******************************************************************************

void setLetters(vector<string> &vec){
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
        vec.push_back(letters); 
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

void prntHashes(const vector<string> vec, const vector<int> vInt){
    int index=0, hash=0;
    do{
        cout<<endl<<"Enter a number between 0 and "<<vInt.size()-1
            <<". To exit enter: -66\n";
        cin>>index;
        if(index>=0 && index<=vInt.size()-1){
            hash=vInt[index];
            cout<<"["<<index<<"] = "<<vec[index]<<" = "<<hash<<" % 512 = "<<hash%512<<endl;
        }
    } while(index!=-66 || (index>=0 && index<=vInt.size()-1));
}
    
//******************************************************************************
//              Print container of random 3 lettered strings
//******************************************************************************

void prntVec(vector<string> vec){        
    cout<<"\n\n\tVector of random 3 initials:\n";
    for(int i=0;i<vec.size();i++){ 
        cout<<vec[i]<<" ";
        if(i%10==9){cout<<endl;}
    } cout<<endl<<endl<<endl;
}

//******************************************************************************
//              Print container of hashed integers
//******************************************************************************

void prntVec(vector<int> vec){    
    cout<<"\tVector of hashed initials:\n";
    for(int i=0;i<vec.size();i++){ 
        cout<<vec[i]<<" ";
        if(i%10==9){cout<<endl;}
    } cout<<endl<<endl<<endl;
}
/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-07-2023 @ 6 PM
 * Purpose: CIS-17C Final problem 1 v2
 * 
 * v2:
 * hashed vector of random initials using h1()'s switch case.
 * 
 * To do:
 * Push vector of hashes into a linked list.
 * Count number of collisions.
 * Make h2() hash with the map('A',2) instead of h1()'s switch case.
*/

//System Libraries
#include <bits/stdc++.h> 
//#include <fstream>
//#include <climits> // char and int maximums
//#include <cfloat>  //float maximum
//#include <cmath>
#include <algorithm>
#include <vector>
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
    cout<<"Vector of random 3 letter initials:\n";
    prntVec(vec); // Print vector
    cout<<"Vector of hashed initials:\n";
    prntVec(vInt); 
    cout<<"You entered: "<<str<<endl;
    cout<<"Hash:     "<<h1(str)<<" %512 = "<<h1(str)%512<<endl;
    cout<<"["<<SIZE-1<<"]="<<vec[SIZE-1]<<"="<<vInt[SIZE-1]<<" %512 = "<<vInt[SIZE-1]%512<<endl<<endl;
            
    // Linked List Report
    cout<<endl<<endl<<"Linked List Collision Report:\n";
    cout<<"No collisions: "<<collsn0<<endl;
    cout<<"1  collisions: "<<collsn1<<endl;
    cout<<"2  collisions: "<<collsn2<<endl;
    cout<<"3  collisions: "<<collsn3<<endl;
    
    return 0;
}

//******************************************************************************
//                  Function Implementations  
//******************************************************************************


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
//              Print container of random 3 lettered strings
//******************************************************************************

void prntVec(vector<string> vec){
    cout<<endl;
    for(int i=0;i<vec.size();i++){ 
        cout<<vec[i]<<" ";
        if(i%10==9){cout<<endl;}
    } 
    cout<<endl<<endl<<endl;
}

//******************************************************************************
//              Print container of hashed integers
//******************************************************************************

void prntVec(vector<int> vec){
    for(int i=0;i<vec.size();i++){ 
        cout<<vec[i]<<" ";
        if(i%10==9){cout<<endl;}
    } cout<<endl;    
    cout<<endl<<endl;
}

//******************************************************************************
//         Converts a 3 letter string into a 3 digit string based on 
//          the buttons on a phone. Returns a number. "MEL" -> 635 
//******************************************************************************
int h1(string str){
    char ch=' ';
    string temp="";
    for(int i=0;i<str.size();i++){  
        ch=' ';   
        switch(str[i]){
            case 'A': case 'B': case 'C':{ ch=50; break;}
            case 'D': case 'E': case 'F':{ ch=51; break;}
            case 'G': case 'H': case 'I':{ ch=52; break;}   
            case 'J': case 'K': case 'L':{ ch=53; break;}
            case 'M': case 'N': case 'O':{ ch=54; break;}
            case 'P': case 'Q': case 'R': case 'S':{ ch=55; break;}
            case 'T': case 'U': case 'V': { ch=56; break;}
            case 'W': case 'X': case 'Y': case 'Z':{ ch=57; break;}
        }         
        temp += ch;
    } //cout<<"temp = "<<temp<<endl;    
    return stoi(temp);
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

/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-07-2023 @ 6 PM
 * Purpose:  CIS-17C Final problem 1 v1
 * 
 * v1:
 * h1(string) converts a 3 letter string into a 3 digit string based on 
 * the buttons on a phone. Returns a number. "MEL" -> 635 
 * 
 * Created a function to fill a vector with 511 random 3 letter strings, then
 * pushed user's initials into it.
 * 
 * Created linked list collision outputs with empty values.
*/

//System Libraries
#include <bits/stdc++.h> 
//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <iomanip>
//#include <cctype>
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
int h1(string);
string h2(string);
int h3(string);
void setLetters(vector<string>&);//Generate container of random 3 letter strings
void setInitials(string &);
void prntVec(vector<string>);
void prntVec(vector<int>);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    
    srand(static_cast<unsigned int>(time(0))); //Set random number seed once here
    //rand()%90+10;//2 digit numbers    
    
    //Declare variables here   
    //int num=0;     
    string str=" ";        
    vector<string> vec; // Container of random 3 letter strings
    setLetters(vec);   // Generate container of random 3 letter strings 
    setInitials(str);
    vec.push_back(str); // Push user's initials into container
    prntVec(vec); // Print vector
    cout<<endl<<"You entered: "<<str<<endl;
    cout<<endl<<"Hash: "<<h1(str)<<" %512 = "<<h1(str)%512<<endl<<endl;

    // Linked List Report
    int collsn0,collsn1,collsn2,collsn3;
    collsn0=collsn1=collsn2=collsn3=0;
    cout<<"Linked List Collision Report:\n";
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
//              
//******************************************************************************

void prntVec(vector<string>vec){
    for(int i=0;i<vec.size();i++){ 
        cout<<vec[i]<<" ";
        if(i%10==9){cout<<endl;}
    } cout<<endl;
}

//******************************************************************************
//              
//******************************************************************************

void prntVec(vector<int>vec){
    for(int i=0;i<vec.size();i++){ 
        cout<<vec[i]<<" ";
        if(i%10==9){cout<<endl;}
    } cout<<endl;
}

//******************************************************************************
//
//******************************************************************************
//string h1(string str){
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
    } 
    //cout<<"temp = "<<temp<<endl;    
    return stoi(temp);
}

//******************************************************************************
//
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

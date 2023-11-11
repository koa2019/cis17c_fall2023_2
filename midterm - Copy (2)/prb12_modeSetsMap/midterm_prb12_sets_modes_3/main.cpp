/* 
 * File:   main.cpp
 * Author: Danielle F
 * Purpose: CIS 17C midterm problem 12
 * Converts arrays to sets.
 * version 3 I deleted all the unnecessary couts. 
 * See previous version for couts
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
//#include <set>
//#include <iterator> 
//#include <algorithm> 
#include <unordered_set>
#include <bits/stdc++.h> 
using namespace std;

//No Global Constants
typedef unordered_multiset<int>::iterator umit;
 
//Function Prototypes
unordered_multiset<int> fillSet(int,int);
void prntSet(unordered_multiset<int>&,int);
void prntMod(unordered_multiset<int>&);
unordered_multiset<int> mode(unordered_multiset<int>&);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=15;
    int modNum=10;
    unordered_multiset<int> set1=fillSet(arySize,modNum);
    
    //Print the initial array  
    cout<<"Filled ary: ";
    prntSet(set1,10);
    
    //Calculate the mode array
    unordered_multiset<int> modeSet = mode(set1);
    
    //Print the modal information of the array
    prntMod(modeSet);
    
    //Delete allocated memory
    set1.clear();
    modeSet.clear();
    
    //Exit stage right
    return 0;
}


unordered_multiset<int> mode(unordered_multiset<int> &set1){
    
    //Copy and Sort the copy
    unordered_multiset<int> ary=(set1);//set<int, less<int>> ary=(set1);
   
    //Find the max Freq
    int count=0, maxFreq=0;
    
    // Defining iterator for the set
    umit i1 = ary.begin();  
    umit i2 = next(i1,1); 
    for(int i=0;i<ary.size()-1;i++,i1++,i2++){                
        if(*i1==*i2){
            count++;           
            if(maxFreq<count){maxFreq=count;}
        } else{count=0;}
    }  
    cout<<"maxFreq: "<<maxFreq<<endl;
    
    //Find the number of modes
    count=0;
    int nModes=0;        

    //Reset iterators
    i1=ary.begin();
    i2=next(i1,1); 
    
    //Printing a set using for loop – (1)
    for(int i=0;i<ary.size()-1;i++,i1++,i2++){  
        if(*i1==*i2){
            count++;
            if(maxFreq==count)nModes++;    
        } else{count=0;}
    }
    
    
    //Allocate the mode array
    unordered_multiset<int> modeAry={};
    
    //BUG!! inserting at front and pushes previous to the back
    //Fill the mode array
    modeAry.insert(nModes);//5
    modeAry.insert(maxFreq+1);//2

    
    count=0;
    i1=set1.begin();
    i2=next(i1,1);
    
    for(int i=0;i<ary.size()-1;i++,i1++,i2++){     
        if(*i1==*i2){          
            count++;
            if(maxFreq==count){modeAry.insert(*i1); } 
        } else{count=0;}
    }    
        
    //Delete the allocated copy and return 
    return modeAry;
}

/******************************************************************/
//                  PRINT MODE SET
/******************************************************************/
void prntMod(unordered_multiset<int> &modeSet){
      
    auto rit = modeSet.begin(5);//end(n) n is the bucket no which should be less than bucket count. 
    cout<<endl;
    cout<<"The number of modes = ";
    cout<<*rit<<endl;//should modeSet[0]
 
    rit = modeSet.begin(1);//end(n) n is the bucket no which should be less than bucket count. 
    cout<<"The max Frequency = ";
    cout<<*rit<<endl;//should print modeSet[1]    
    
    if(modeSet.empty()){ 
        cout<<"The mode set = {null}"<<endl;
        return;
    }

    cout<<"The mode set = {";
    auto n=5;
    for (auto i=0; i<n; ++i) {
        for (auto it=modeSet.begin(i); it!=modeSet.end(i); it++) {   
            cout << *it << ' ';            
        }
    }    
    cout<<"}"<<endl;
}

unordered_multiset<int> fillSet(int n, int modNum){    
    unordered_multiset<int> array;
    
    //Fill the array with 2 digit numbers
    for(auto i=0,cnt=0;cnt<n;i++,cnt++){
        array.insert(i%modNum);
    }    
    return array;
}

void prntSet(unordered_multiset<int>& set1,int perLine){
    unordered_multiset<int>::iterator it=set1.begin();
    cout<<endl;
    for (int i=0; i<set1.size();i++, it++) {
        cout << *it << ' ';
        if(i%perLine==(perLine-1))cout<<endl;
    } cout<<endl;    
}

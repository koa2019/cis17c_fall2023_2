/*  File:   main.cpp
 * Author: Danielle F
 * Purpose: CIS 17C midterm problem 12
 * Converts arrays to sets.
 * Version 3:
 * Has all the couts to help convert it
 * from an array to sets
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
//    cout<<"\nmain(). modeSet: ";
//    for (int i : modeSet) {
//        cout << i << ' ';
//    } cout<<endl;    
    //prntSet(modeSet,10);
    
//    //Print the modal information of the array
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
    //cout<<"\nCopied ary: ";
    //prntSet(ary,10);
     
    //Find the max Freq
    int count=0, maxFreq=0;
    
    // Defining iterator for the set
    umit i1 = ary.begin();  //multiset<int>::iterator i1=ary.begin();

    umit i2 = next(i1,1); //i2 = v1.begin()+1  //multiset<int>::iterator i2=next(i1,1); //i2 = v1.begin()+1        

    for(int i=0;i<ary.size()-1;i++,i1++,i2++){                
        if(*i1==*i2){
            count++;
            //cout<<*i1<<"=="<<*i2<<"  \n";            
            if(maxFreq<count){maxFreq=count;}
        } else{count=0;}
    }  
    
    //Find the number of modes
    count=0;
    int nModes=0;        

    //Reset iterators
    i1=ary.begin();
    i2=next(i1,1); //i2=v1.begin()+1
    
    //Printing a set using for loop – (1)
    for(int i=0;i<ary.size()-1;i++,i1++,i2++){     
        //cout<<*i1<<"=="<<*i2<<"  \n";   
        if(*i1==*i2){
            count++;
            if(maxFreq==count)nModes++;
            //cout<<*i1<<"=="<<*i2<<" nModes="<<nModes<<"  \n";    
        } else{count=0;}
    }
    
    cout<<"\nmaxFreq: "<<maxFreq<<"  nModes: "<<nModes<<endl;
    
    //Allocate the mode array
    unordered_multiset<int> modeAry={};
    
    //BUG!! inserting at front and pushes previous to the back
    //Fill the mode array
    modeAry.insert(nModes);//5
    modeAry.insert(maxFreq+1);//2
    cout<<"modeAry: ";
    prntSet(modeAry,10);
    //cout<<"\tsize = "<<modeAry.size()<<endl;
    
    count=0;
    int indx=2;//insert modes starting at index 2
    i1=set1.begin();
    i2=next(i1,1); //i2=v1.begin()+1
    
    for(int i=0;i<ary.size()-1;i++,i1++,i2++){     
        if(*i1==*i2){          
            count++;
            if(maxFreq==count){   
                modeAry.insert(*i1); 
                prntSet(modeAry,10);
            } 
        } else{count=0;}
    }    
    
    auto  n = modeAry.bucket_count();
    cout<<"\tLeaving fill() size = "<<modeAry.size()<<endl;
    cout<<n<<" buckets\n";  
    
    //Delete the allocated copy and return 
    return modeAry;
}

/******************************************************************/
//                  PRINT MODE SET
/******************************************************************/
void prntMod(unordered_multiset<int> &modeSet){
    
    auto  n = modeSet.bucket_count();
    cout<<endl<<endl<<"Inside prntMod.\n"
        <<"modeSet.size = " <<modeSet.size()<<endl;
    cout<<n<<" buckets\n"; 
    
    for (auto i=0; i<n; ++i) {
        cout<< "bucket "<< i << " contains:";
        for (auto it = modeSet.begin(i); it!=modeSet.end(i); ++it){
            cout << " " << *it <<"  i="<<i;
        }
        cout<<endl;
        
    }
    
    auto rit = modeSet.begin(5);//end(n) n is the bucket no which should be less than bucket count. 
    cout<<endl;
    cout<<"The number of modes = \n";
    cout<<*rit<<endl;//modeSet[0]
 
    rit = modeSet.begin(1);//end(n) n is the bucket no which should be less than bucket count. 
    cout<<"The max Frequency = \n";
    cout<<*rit<<endl;//modeSet[1]    
    
    if(modeSet.empty()){ //if(*rit==NULL){//
        cout<<"The mode set = {null}"<<endl;
        return;
    }

    cout<<"The mode set = {";
    //umit it=next(modeSet.begin(),2);
    n=5;
    for (auto i=0; i<n; ++i) {
        for (auto it=modeSet.begin(i); it!=modeSet.end(i); it++) {   
            cout << *it << ' ';            
        }
    }
    
    cout<<"}"<<endl;
}

unordered_multiset<int> fillSet(int n, int modNum){    
    unordered_multiset<int> array;
    //cout<<"\tn="<<n<<endl;
    
    //Fill the array with 2 digit numbers
    for(auto i=0,cnt=0;cnt<n;i++,cnt++){
        //cout<<"cnt="<<cnt<<"  "<<i%modNum<<" \n";
        array.insert(i%modNum);
        //array.insert(rand()%modNum*2);
    }    
    //cout<<"\tarray.size="<<array.size()<<endl;
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

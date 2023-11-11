/* 
 * File:   main.cpp
 * Author: Danielle
 * Purpose: CIS 17C midterm problem 12
 * Converts arrays to sets.
 * Version 1:
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <set>
#include <iterator> 
#include <algorithm> 
#include <unordered_set>
using namespace std;

//No Global Constants

//Function Prototypes
multiset<int> fillSet(int,int);
void prntSet(multiset<int>&,int);
void prntMod(unordered_set<int>&);
unordered_set<int> mode(const multiset<int>&);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=15;
    int modNum=10;
    multiset<int> set1=fillSet(arySize,modNum);
    
    //Print the initial array  
    prntSet(set1,10);
    
    //Calculate the mode array
    unordered_set<int> modeSet=mode(set1);
    cout<<"\nmain(). modeSet: ";
    for (int i : modeSet) {
        cout << i << ' ';
    } cout<<endl;    
    //prntSet(modeSet,10);
    
    //Print the modal information of the array
    //prntMod(modeSet);
    
    //Delete allocated memory
    set1.clear();
    modeSet.clear();
    
    //Exit stage right
    return 0;
}


unordered_set<int> mode(const multiset<int> &set1){
    
    //Copy and Sort the copy
    multiset<int, less<int>> ary=(set1); 
  
    //Find the max Freq
    int count=0,maxFreq=0;
    
    // Defining iterator for the set
    multiset<int>::iterator i1=ary.begin();
    multiset<int>::iterator i2=next(i1,1); //i2 = v1.begin()+1        

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
    i2=next(i1,1); //i2 = v1.begin()+1
    
    //Printing a set using for loop – (1)
    for(int i=0;i<ary.size()-1;i++,i1++,i2++){     
        //cout<<*i1<<"=="<<*i2<<"  \n";   
        if(*i1==*i2){
            count++;
            if(maxFreq==count)nModes++;
            //cout<<*i1<<"=="<<*i2<<" nModes="<<nModes<<"  \n";    
        } else{count=0;}
    }
    //cout<<"maxFreq: "<<maxFreq<<"  nModes: "<<nModes<<endl;
    
    //Allocate the mode array
    unordered_set<int> modeAry={};
    
    //BUG!! inserting at the back
    //Fill the mode array
    modeAry.insert(nModes);
    modeAry.insert(maxFreq+1);

    count=0;
    int indx=2;//insert modes starting at index 2
    i1=set1.begin();
    i2=next(i1,1); //i2 = v1.begin()+1
    
    for(int i=0;i<ary.size()-1;i++,i1++,i2++){     
        if(*i1==*i2){          
            count++; //cout<<*i1<<"=="<<*i2<<"  \n";
            if(maxFreq==count){                  
                //cout<<"insert "<<*i1<<"  \n"; 
                modeAry.insert(*i1); //modeAry[indx++]=i1;
            } 
        } else{count=0;}
    }    
    //Delete the allocated copy and return 
    return modeAry;
}

void prntMod(unordered_set<int>& modeSet){
    //cout<<"\n\tsize = "<<modeSet.size()<<endl;
    // Defining iterator for the set
    //std::unordered_set<int>::iterator i1=modeSet.begin();
    //std::unordered_set<int>::iterator i2=next(modeSet,1); //i2 = v1.begin()+1
    

    //for(int i=0;i<modeSet.size();i++){//,i1++,i2++){ 
        //cout<<*i1<<endl;

    cout<<endl;
    cout<<"The number of modes = \n";
    //cout<<modeSet[0]<<endl;

    cout<<"The max Frequency = \n";
    //cout<<modeSet[1]<<endl;
    
    if(modeSet.empty()==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }

    //cout<<"*modeSet.begin()+1 = "<<modeSet.begin()+1<<endl;
    cout<<"The mode set = {";
    //for(int i=2;i<ary[0]+1;i++){//index 0 holds the size of the mode set
        //cout<<modeSet[i]<<",";//cout<<ary[i]<<",";        
    //}
    
    //cout<<modeSet.begin()<<"}"<<endl; // ary[ary[0]+1] 
    //}
}

multiset<int> fillSet(int n, int modNum){    
    multiset<int> array;
    //cout<<"\tn="<<n<<endl;
    
    //Fill the array with 2 digit numbers
    for(int i=0,cnt=0;cnt<n;i++,cnt++){
        //cout<<"cnt="<<cnt<<"  "<<i%modNum<<" \n";
        array.insert(i%modNum);
        //array.insert(rand()%modNum*2);
    }    
    //cout<<"\tarray.size="<<array.size()<<endl;
    return array;
}

void prntSet(multiset<int>& set1,int perLine){
    set<int>::iterator it=set1.begin();
    cout<<endl;
    for (int i=0; i<set1.size();i++, it++) {
        cout << *it << ' ';
        if(i%perLine==(perLine-1))cout<<endl;
    } cout<<endl;    
}

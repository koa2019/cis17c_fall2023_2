/*  File:   main.cpp
 * Author: Danielle F
 * Purpose: midterm problem 12 
 * Convert arrays to sets then to maps
 * version 1:
 * Based off midterm_prb12_sets_modes_2
 * Has all the couts to help convert it
 * from an array to sets to maps
 * 
 * To do:
 * BUG if(maxFreq<count)
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
//#include <set>
//#include <iterator> 
//#include <algorithm> 
//#include <unordered_set>
#include <map>
#include <bits/stdc++.h> 
using namespace std;

//No Global Constants
//typedef unordered_multiset<int>::iterator umit;
 
//Function Prototypes
int *fillArry(int,int);
map<int, int>fillMapMode(int[],int);
//void prntSet(unordered_multiset<int>&,int);
//void prntMod(unordered_multiset<int>&);
//unordered_multiset<int> mode(unordered_multiset<int>&);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=15;
    int modNum=10;    
    int i=0;
    int *array=fillArry(arySize,modNum);
   
    // Create map container
    map<int, int> map={};
   
    int count=0, maxFreq=0,nModes=0;    
    
    //Initialized map container    
    for(i=0;i<arySize-1;i++){
        map[i]=array[i];
    }    
    
    //Print map
    //cout<<"map.size = "<<map.size()<<endl;
    cout<<endl<<"Sorted map\n";
    for(i=0;i<map.size();i++){
        cout<<map[i]<<" ";
        if(i%10==9)cout<<endl;
    }cout<<endl<<endl;
    
     //Find the max Freq;
    //Need to make this work with an iterator
    for(i=0;i<arySize;i++){
        if(map[i]==map[i+1]){
            count++;           
            if(maxFreq<count){
                maxFreq=count;
                //cout<<map[i]<<"=="<<map[i+1]<<"\n";//BUG HERE
                //cout<<"maxFreq = "<<maxFreq<<endl;
            }
        } else{count=0;}   
    }cout<<endl;
       
    count=0;
    std::map<int, int> mode={};//modes container
    mode.insert(pair<int,int>(1,maxFreq));   
    std::map<int, int>::iterator it = map.begin();
    std::map<int, int>::iterator next = map.begin();
    next++;
    
    //BUG in this loop
    //cout<< "(key,value)"<<endl;
    int indx=2;
    for (it=map.begin(); it!=map.end(); it++,next++){
        
        //cout<<"("<< it->first << "," << it->second <<") == ";
        //cout<<"("<< next->first << "," << next->second << ") ?\n";
        //cout<<"("<< it->second << "==" << next->second << ") ?\n";

        if(it->second==next->second){
            count++;           
            if(count==maxFreq){
               //cout<<"("<< it->second << "==" << next->second << ") \n";
               nModes++;
               mode.insert ( std::pair<int,int>(indx,it->second) );
               indx++;
           }
       } else{count=0;}
        
    }  
    mode.insert(pair<int,int>(0,nModes)); 
    //cout<<"nModes: "<<nModes<<"  maxFreq: "<<maxFreq<<endl;
    cout<<"nModes: "<<nModes<<"  maxFreq: "<<maxFreq<<endl;
     
    //Print mode array
    cout<<"\nMode Map:\n";
    cout<< "(key,value)"<<endl;
    it=mode.begin();
    for (it=mode.begin(); it!=mode.end(); it++,next++){
       cout<<"("<< it->first << "," << it->second <<")\n";
    } cout<<endl;    

    
    //Exit stage right
    return 0;
}

 int *fillArry(int arySize, int modNum){
    int i=0;
    //Initialize int array
    int *array = new int[arySize];
    for(i=0;i<arySize;i++){
        array[i]=i%modNum; 
    }
    //Print array
    cout<<endl<<endl<<"Int array: \n";
    for(i=0;i<arySize;i++){
        cout<<array[i]<<" ";
        if(i%10==9)cout<<endl;
    }
    
    
    //Sort array
    cout<<endl<<endl<<"Sorted array\n";
    sort(array,array+arySize);
    for(i=0;i<arySize;i++){
        cout<<array[i]<<" ";
        if(i%10==9)cout<<endl;
    }cout<<endl;
    return array;
}


/* File:    main.cpp
 * Author:  Danielle 
 * Created: 12-10-2023 @2 AM
 * Purpose: Lab 4 simple vector linked list v6
 * Input: 10
 * Output:  M N Q N A N I R. See expectedOutput.PNG
  
 * V6: 
 * Copied LinkedList.h from LinkedList_v5
 * I replaced simple vector's array (T *aptr) with LinkedList class object.
 * Figured out how to make simple vector functions work with LinkedList.h
 * AND NOT with Object.h
 
 * To do:
 * Reference Lehr's midterm>SimpleVectorUsingLinkedList
 */

//System Libraries
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
//User Libraries for .h file
#include "SimpleVector.h"

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
     //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers    
    //char ch = 65+(rand()%26); //A-Z[65,90]
    
    //Declare Variables
    int size=0, num=0;
    size=10;
    //cout<<"Input the Size of the Array 10-100"<<endl; cin>>size;   
    SimpleVector<int> sv(size);
    cout<<"Simple Vector Front Object =  "<<sv[0];
    sv.prntSV(); //Print the Simple Vector
    
    num=rand()%26+65;  
    cout<<"\nThe value added to the front is = "<<num<<endl;
    sv.pushFrnt(num);
    sv.prntSV();       
    
    //Add 5 links to Simple vector
    cout<<"\nAdded 5 numbers to the back";
    for(int i=0;i<5;i++){
        num=rand()%26+65;
        sv.pushBack(num);        
    }
    sv.prntSV();  
    cout<<endl<<"Front Removed = "<<sv.popFront();
    sv.prntSV(); //Print the Simple Vector
    cout<<"Back  Removed = "<<sv.popBack();
    sv.prntSV(); //Print the Simple Vector    
     
    return 0;
}
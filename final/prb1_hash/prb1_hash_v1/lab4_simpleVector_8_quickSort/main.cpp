/* File:    main.cpp
 * Author:  Danielle 
 * Created: 12-10-2023 @2 AM
 * Purpose: Lab 4 simple vector linked list v8 
 * Output: random numbers that represents a single link/node in linked list
  
 * BUG: sv[indx].getQuickSort(). I wanted to use it in cis17c project 2
 * 
 * v8:
 * Adding a quick sort function, so i can use it in cis17c project 2
 * 
 * V7:
 * Created static array of LinkedList, so i can use it in the final for
 * problem 1. Problem 1 will hash  512 elements, there will  be collisions,
 * more than 1 element in Simple Vector's static array.
 * 
 * To do:
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
int mrkRand(int seed=0);
void fillVec(vector<int> &);
void prntVec(vector<int> &, int perLine=10);

//Execution Begins Here
int main(int argc, char** argv) {
     //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers    
    //char ch = 65+(rand()%26); //A-Z[65,90]
    
    //Declare Variables
    int size=0, num=0, indx=0;
    size=26+65+1;  
    vector<int> indxUsed;
    
    // Allocating  memory for a static array of Linked Lists
    SimpleVector<int> *sv;
    sv = new SimpleVector<int>[size];//SimpleVector<int> sv(size);
    sv[indx].pushBack(9);    
    cout<<"indx["<<setw(2)<<indx<<"] = ";
    sv[indx].prntSV(); // Prints 0 9   
    // Print Index's used in SimpleVector 
    indxUsed.push_back(indx); // keep track of indices used
    prntVec(indxUsed,10);

    indx=rand()%26+65;
    indxUsed.push_back(indx); // keep track of indices used
    num=rand()%26+65;  
    
    // Add random number to random linked list index
    cout<<"indx["<<setw(2)<<indx<<"] = ";
    sv[indx].prntSV(); // Prints 0 
    cout<<"indx["<<indx<<"] Push front = "<<num<<endl;
    sv[indx].pushFrnt(num);
    sv[indx].prntSV();   
    
    indx=rand()%26+65;
    indxUsed.push_back(indx); // keep track of indices used
    cout<<"\nAdding 5 numbers to the back.\n";
    cout<<"indx["<<setw(2)<<indx<<"] = \n";    
    //Add 5 links to Simple vector
    for(int i=0;i<5;i++){
        //cout<<"Pushing: "<<num<<".  ";
        num=rand()%26+65;
        sv[indx].pushBack(num);         
        sv[indx].prntSV();  
    }
    cout<<endl;
    
    //sv[indx].getQuickSort();
    //Print Index's used in SimpleVector 
    prntVec(indxUsed,10);
    
    
//    cout<<endl<<"Front Removed = "<<sv[indx++].popFront();
//    sv[indx].prntSV(); //Print the Simple Vector
//    cout<<"Back  Removed = "<<sv[indx++].popBack();
//    sv[indx].prntSV(); //Print the Simple Vector    
     
    return 0;
}


void prntVec(vector<int> &vec, int perLine){     
    cout<<"Index's used in SimpleVector = ";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }     cout<<endl;
}


void fillVec(vector<int> &vec){
    for(int i=0;i<5;i++){
        vec[i]=mrkRand(5)%26+65;
        //vec[i]=sv[i];
    }
}

int mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}
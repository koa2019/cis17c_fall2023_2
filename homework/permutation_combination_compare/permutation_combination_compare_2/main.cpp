/* File:    main.cpp
 * Author:  Danielle F
 * Created: 10-26-2023 @ 6 PM
 * Purpose:  Permutation and Combinations for 
 *           n=[2,26] AND m=[0,26]
 * v2:
 * permNoRep(int,int);//without replacement. nPm = n!/(n-m)!
*/

//System Libraries
#include <bits/stdc++.h> 
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <climits> // char and int maximums
#include <cfloat>  //float maximum
#include <cmath>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
float powRec(int,int);
double factFor(int);
double factRec(int);

double permNoRep(int,int);//without replacement. nPm = n!/(n-m)!
double permRecur(int,int);//replace recursive. nPm R = n^m
double permFor(int,int); //replace for loop
double permFor(int nMax);//replace for loop


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers
        
    //Declare variables here
    int nMax=10,n=8, m=8;
    double nPm=0, nPmR=0;   
    
    
    //Map inputs to outputs -> i.e. process the inputs  
    cout<<"n    m    Permutation    Permutation    Combination     Combination\n";
    cout<<left<<setw(10)<<" "<<setw(30)<<"Replacement"
        <<setw(26)<<"Replacement"<<endl;
    
      for(n=2; n<=nMax; n++){
        for(m=0; m<=nMax; m++){  
            
            //if(m==nMax){
                cout<<left<<setw(5)<<n<<setw(5)<<m
                    <<right<<setw(11)<<permRecur(n,m)
                    <<setw(13)<<permNoRep(n,m)
                    <<endl;   
              
            //}
        }
        cout<<endl;
    }
    
    
    
    //cout<<endl<<endl<<"permRecur: "<<n<<"^"<<m<<" = "<<permRecur(n,m)<<endl;
    //cout<<setw(11)<<"permFor: "<<n<<"^"<<m<<" = "<<permFor(nMax)<<endl;     
        
    //cout<<"Factorial with a for-loop  "<<n<<"! = "<<factFor(n)<<endl;
    //cout<<"Factorial with a Recursion "<<n<<"! = "<<factRec(n)<<endl<<endl;
    
    return 0;
}

/******************************************************************************/
/*                           Function Implementations                         */
/******************************************************************************/





/******************************************************************************/
//                      Perm with No Replacement 
//                          nPm = n!/(n-m)!
/******************************************************************************/

double permNoRep(int n,int m){

    //Base Condition
    if(m>=n)return 0; //denominator can't be zero
    
    int d=n-m;    
    
    double numratr = factRec(n);
    double denom = factRec(d);
    
    //cout<<"n="<<n<<" d="<<d<<"  ";
    //cout<<numratr<<" / "<<denom<<"  = ";
    
    return numratr/denom;//permNoRep();
}

/******************************************************************************/
//                      Helper Functions
/******************************************************************************/


float logFact(int n){
    //Base Condition
    if(n<=1)return 0;
    //Recursion
    return logFact(n-1)+log(n);
}

//power recursion
float powRec(int base,int n){
    //Base Condition
    if(n<=0)return 1; // base^n. base^0=1
    //Recursion
    return powRec(base,n-1)*base;
}

double factRec(int n){
    //Base Case
    if(n<=1)return 1;  //if(n<=0)return 1;
    //Recursive Representation
    return factRec(n-1)*n;
}

double factFor(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}

/******************************************************************************/
//                      Permutation With Replacement      
//                              nPm R = n^m
/******************************************************************************/

// Its basically a power recursion     
double permRecur(int n,int m){    
    //Base Condition
    if(m<=0)return 1; // n^m AND m==0. n^0=1
    //Recursion
    return permRecur(n,m-1)*n;
}

//Perm with Replacement using for loop 
//Breaks at 11^11
double permFor(int n,int m){    
    //Base Condition
    if(m<=0)return 1; // n^m AND m==0. n^0=1
    //Recursion
    return pow(n,m);
}

//Perm with Replacement using for loop 
//Breaks at 11^11
double permFor(int nMax){

    int n,m,nPmR;
    n=m=nPmR=0; 
    
    for(n=2; n<=nMax; n++){
        for(m=0; m<=nMax; m++){           
        
            // nPmR = n^m
            nPmR=pow(n,m);            
            //cout<<n<<"^"<<m<<" = ";
            //cout<<pow(n,m)<<endl;            
        }
        //cout<<endl;
    }
    //cout<<endl;
    return nPmR;
}
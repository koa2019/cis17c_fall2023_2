/* File:    main.cpp
 * Author:  Danielle F
 * Created: 10-26-2023 @ 6 PM
 * Purpose:  Permutation and Combinations for 
 *           n=[2,26] AND m=[0,26]
 * v3:
 * comboRep(). Combination with replacement. 
 * nCm R = (n+m-1)!/(n-1)!*m!
 * 
 * comboNoRep(). Combination without replacement. 
 * nCm = n!/(n-m)!/m!
*/

//System Libraries
#include <bits/stdc++.h> //<bits/stdc++.h> 
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

double comboNoRep(int,int);     //NO replacement. nCm = n!/(n-m)!/m!
double comboRep(int,int);      //nCm R = (n+m-1)!/(n-1)!/(m)!
double permNoRep(int,int);    //NO replacement. nPm = (n+m-1)!/(n-1)!*m!
double permRepRecur(int,int);//replace recursive. nPm R = n^m
double permFor(int,int);    //replace for loop
double permFor(int nMax);  //replace for loop


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers
        
    //Declare variables here
    int nMax=10, // permFor() uses it
        n=8, 
        m=8; 
    
    
    //Map inputs to outputs -> i.e. process the inputs  
    cout<<setprecision(3);
    cout<<"n    m    Permutation    Permutation    Combination     Combination\n";
    cout<<left<<setw(10)<<" "<<setw(30)<<"Replacement"
        <<setw(26)<<"Replacement"<<endl;
    
      for(n=2; n<=nMax; n++){
        for(m=0; m<=nMax; m++){  
            
            //cout<<left<<setw(5)<<n<<setw(5)<<m
                    //<<right<<setw(10)<<comboNoRep(n,m)<<endl;
            //if(m==nMax){
                cout<<left<<setw(5)<<n<<setw(5)<<m
                    <<right<<setw(11)<<permRepRecur(n,m)
                    <<setw(13)<<permNoRep(n,m)
                    <<setw(13)<<comboRep(n,m)
                    <<setw(13)<<comboNoRep(n,m)
                    <<endl;                 
            //}
        }
        cout<<endl;
    }
    
    
    
    //cout<<endl<<endl<<"permRepRecur: "<<n<<"^"<<m<<" = "<<permRepRecur(n,m)<<endl;
    //cout<<setw(11)<<"permFor: "<<n<<"^"<<m<<" = "<<permFor(nMax)<<endl;     
        
    n=10;
    //cout<<"Factorial with a for-loop  "<<n<<"! = "<<factFor(n)<<endl;
    //cout<<"Factorial with a Recursion "<<n<<"! = "<<factRec(n)<<endl<<endl;
    
    return 0;
}

/******************************************************************************/
//                          Combinations                          
/******************************************************************************/    

//Combination NO Replacement. nCm     = n!/(n-m)!/m!
double comboNoRep(int n,int m){    
    //Base Condition
    if(m<=0)return 0; //denominator can't be zero
    if(m>=n)return 0; //denominator can't be zero

    //Recursions    
    //double numratr = permNoRep(n,m);
    int d=n-m;  
    double numratr = factRec(n);
    double denom1 = factRec(d);
    double denom2 = factRec(m);
    //cout<<"d="<<d<<"  "<<numratr<<" / "<<denom1<<" * "<<denom2;
    denom1 *= denom2;
    //cout<<"  denom2 "<<denom1<<"  = ";
    
    return numratr/denom1;
}

//Combination With Replacement. nCm R = (n+m-1)!/(n-1)!*m!
double comboRep(int n,int m){    
    //Base Condition
    if(m<=0)return 0; //denominator can't be zero
    //if(m>=n)return 0; //denominator can't be zero
    int d=n-1;    
    //Recursions    
    double numratr = factRec(n+m-1);
    double denom = factRec(d);
    double mFact = factRec(m);
    denom *=mFact;
    //cout<<"n="<<n<<" d="<<d<<"  ";
    //cout<<numratr<<" / "<<denom<<"  = ";
    
    return numratr/denom;
}





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
    
    return numratr/denom;
}

/******************************************************************************/
//                      Permutation With Replacement      
//                              nPm R = n^m
/******************************************************************************/

// Its basically a power recursion     
double permRepRecur(int n,int m){    
    //Base Condition
    if(m<=0)return 1; // n^m AND m==0. n^0=1
    //Recursion
    return permRepRecur(n,m-1)*n;
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

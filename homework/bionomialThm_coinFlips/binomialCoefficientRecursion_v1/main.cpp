/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 21st, 2021, 11:51 AM
 * Purpose: Pascal Triangle
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <iomanip>
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow

//Function Prototypes
float factFor(float);//Factorial Product
float factRec(float);//Factorial Recursive 
float bCoeff(float,float);//Recursive Binomial Coefficent

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    float n,j;
    float sumHeads=0, sumTails=0;
    bool coin1;
    
    //Compare with the factorial Definition
    int nFaces=2;
    int nCoins=1;
    n=nCoins*nFaces;//number of coins multiplied by faces on 1 coin
    j=1/2.0;       //number of possible heads
    //cout<<"j="<<j<<endl;
    float a,b,c,d,bioN,p;
    for (int i = 0; i < 10000; i++) {
        a=factRec(n);   // numerator
        b=factRec(n-j); //previous element
        c=factRec(j);  //current element
        d = b*c;      // denom
        bioN = a/d;  //bioN formula
        p = 1/d*100; //probability    
    }
    //BCoeff breaks
    //cout<<"Using Recursion "<<n<<"C"<<showpoint<<j<<" = "<<bCoeff(n,j)<<endl;
    cout<<showpoint<<setprecision(4);
    cout<<"Using formula:\n"
        << n << "C" << j << " = "
        << a << "/" << b << "*" << c << " = "
        << d << " = " << p <<"%\n";
    
    //Original output from lehr's example in pascallTriangleBinomialCoefficientRecur
    //cout<<"Using formula   "<<n<<"C"<<j<<" = "
            //<<factRec(n)/(factRec(n-j)*factRec(j))<<endl;

    return 0;
}

//Function Implementations
float bCoeff(float n,float j){
    //Base conditions for the recursion
    if(j==0)return 1;
    if(n==j)return 1;
    //Recursive Form
    return bCoeff(n-1,j-1)+bCoeff(n-1,j);
}

float factFor(float n){
    float fact=1;
    for(float i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}

float factRec(float n){
    //Base Case
    if(n<=1)return 1;
    //Recursive Representation
    return factRec(n-1)*n;
}
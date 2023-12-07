/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 21st, 2021, 11:51 AM
 * Purpose: Pascal Triangle
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
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
    
    //Initialize Variables
    //n=12;
    
    //Map inputs to outputs -> i.e. process the inputs
    //cout<<"Factorial with a for-loop  "<<n<<"! = "<<factFor(n)<<endl;
    //cout<<"Factorial with a Recursion "<<n<<"! = "<<factRec(n)<<endl;
    
    //Display the outputs
    //float stop=12;
    //cout<<"Pascal's Triangle"<<endl;
    //for(float n=0;n<=stop;n++){
    //    for(float j=0;j<=n;j++){
    //        cout<<bCoeff(n,j)<<" ";   
        //}
        //cout<<endl;
    //}
    
    //Compare with the factorial Definition
    int nFaces=2;
    int nCoins=2;
    n=nCoins*nFaces;//number of coins multiplied by faces on 1 coin
    j=n/2;//number of possible heads
    float a,b,c,d,p;
    a=factRec(n);
    b=factRec(n-j);
    c=factRec(j);
    d=a/(b*c);
    p=1/d*100;
    cout<<"Using Recursion "<<n<<"C"<<j<<" = "<<bCoeff(n,j)<<endl;
    cout<<"Using formula   "<<n<<"C"<<j<<" = "
        <<a<<"/"<<b<<"*"<<c<<" = "
        <<d<<" = "<<p<<endl;
    
    //cout<<"Using formula   "<<n<<"C"<<j<<" = "
            //<<factRec(n)/(factRec(n-j)*factRec(j))<<endl;
    
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
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
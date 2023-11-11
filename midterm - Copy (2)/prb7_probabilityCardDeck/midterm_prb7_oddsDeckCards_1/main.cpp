/* File:    main.cpp
 * Author: Danielle 
 * Created: 11-02-23 @8PM
 * Purpose: midterm problem 7 Probability for a deck of cards 
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
#include <algorithm>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
int binomialCoeff(int,int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers    

    int n = 52, // number of cards in a deck
        r = 2, // number cards in 1 pair
        numOf1Kind = 4; //4 cards for each type of card  
    float nTypes = binomialCoeff(13,1);//13.0f;
    int sampleSize = binomialCoeff(n,r);
    int num1Pair = binomialCoeff(numOf1Kind,r);   
    int nWaysAnyPair = binomialCoeff(nTypes,r);
    float  odds = 0;
    
    cout<<endl<<endl<<"\tAny type of Pair\n\n";
    cout<<"Sample Size: C("<<n<<","<<r<<")= "
        <<sampleSize<<endl;
    cout<<"# of types of cards in a deck: C("<<nTypes<<",1"<<") = "
        <<nTypes<<endl;
    cout<<"# of ways to get a single pair: C("<<numOf1Kind<<","<<r<<") = "
        <<num1Pair<<endl;    
    cout<<"# ways to get single pair: C("<<nTypes<<","<<r<<") = "
        <<nWaysAnyPair<<endl;    
    odds = (1.0f*nWaysAnyPair/sampleSize)*100;
    cout<<"Probability 1 pair = "<<showpoint<<setprecision(3)
        <<odds<<"%\n";

    
    // 2 Pair  
    r=4;
    cout<<endl<<endl<<"\tAny 2 Pairs\n\n";     
    sampleSize = binomialCoeff(n,r);   
    num1Pair*=num1Pair;
    cout<<"Sample Size: C("<<n<<","<<r<<")= "
        <<sampleSize<<endl;
    cout<<"# of ways to get two single pairs: C("<<numOf1Kind<<","<<r-2<<")^2 = "
        <<num1Pair<<endl;
    cout<<"# ways to get single pair: C("<<nTypes<<","<<r<<") = "
        <<nWaysAnyPair<<endl; 
    int nWays2Pairs = nWaysAnyPair*num1Pair;
    cout<<"# ways two combo pairs = "<<nWays2Pairs<<endl;
    odds = (1.0f*nWays2Pairs/sampleSize)*100;
    cout<<"Probability  2 combo pairs = "<<showpoint<<setprecision(3)
        <<odds<<"%\n";

    
    // 3 of a kind
    r=3;
    cout<<endl<<endl<<"\t3 of a Kind\n\n";     
    sampleSize = binomialCoeff(n,r);   
    num1Pair = binomialCoeff(numOf1Kind,r); 
    nWaysAnyPair = binomialCoeff(nTypes,r);
    cout<<"Sample Size: C("<<n<<","<<r<<")= "
        <<sampleSize<<endl;
    cout<<"# of ways to get 3 of a Kind: C("<<numOf1Kind<<","<<r<<") = "
        <<num1Pair<<endl;   
    cout<<"# ways to get 3 of a Kind: C("<<noshowpoint<<nTypes<<","<<r<<") = "
        <<nWaysAnyPair<<endl;   
    odds = (1.0f*nWaysAnyPair/sampleSize)*100;
    cout<<"Probability 3 of a Kind = "<<showpoint<<setprecision(3)
        <<odds<<"%\n";
    
    // 4 of a kind
    r=4;
    cout<<endl<<endl<<"\t4 of a kind\n\n";     
    sampleSize = binomialCoeff(n,r);   
    num1Pair = binomialCoeff(numOf1Kind,r); 
    nWaysAnyPair = binomialCoeff(nTypes,r);
    cout<<"Sample Size: C("<<n<<","<<r<<")= "
        <<sampleSize<<endl;
    cout<<"# of ways to get 4 of a kind: C("<<numOf1Kind<<","<<r<<") = "
        <<num1Pair<<endl;   
    cout<<"# ways to get 4 of a kind: C("<<noshowpoint<<nTypes<<","<<r<<") = "
        <<nWaysAnyPair<<endl;   
    odds = (1.0f*nWaysAnyPair/sampleSize)*100;
    cout<<"Probability 4 of a kind = "<<showpoint<<setprecision(3)
        <<odds<<"%\n";
    
    
    return 0;
}

/**********  Function Implementations  **************/

// Return value of Bionomial Coefficient C(n,k)
int binomialCoeff(int n, int r){

    // Base Cases: C(n, 0) = C(n, n) = 1
    if(r==0 || r==n) {return 1;}

    // Recursive
    // Expected output if:
    // C(5, 3) = C(4, 2) + C(4, 3)
	// C(5, 3) = (4!/(2!*(4-2)!) + (4!/(3! * (4-3)!) = 6+4=10
    return binomialCoeff(n-1,r-1) + binomialCoeff(n-1,r); 
}
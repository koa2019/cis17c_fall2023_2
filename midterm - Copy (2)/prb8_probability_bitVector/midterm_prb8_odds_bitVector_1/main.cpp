/* File:    main.cpp
 * Author: Danielle 
 * Created: 11-02-23 @8PM
 * Purpose: midterm problem 8 Probability for Bit Vector
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

    int n = 100, // number of cards in a deck
        r = 5, // number cards in 1 pair
        nFilled = 40; //4 cards for each type of card  
    //float nTypes = binomialCoeff(13,1);//13.0f;
    int sampleSize = binomialCoeff(n,r);
    //int num1Pair = binomialCoeff(numOf1Kind,r);   
    int nWays = binomialCoeff(nFilled,r);
    float  odds = 0;
    
    cout<<endl<<endl<<"\tMidterm Problem 8\n\tBit Vector Odds\n\n";
    cout<<"Sample Size: C("<<n<<","<<r<<") = "
        <<sampleSize<<endl<<endl;
    
    cout<<"# of ways 5 bits will all land \nin 40% filled section\nC("<<nFilled<<","<<r<<") = "
        <<nWays<<endl;    
  
    odds = (1.0f*nWays/sampleSize)*100;
    cout<<"\nProbability = "<<nWays<<"/"<<sampleSize<<" = "<<showpoint<<setprecision(3)
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
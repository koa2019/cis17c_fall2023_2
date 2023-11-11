/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 4th, 2023, 11:19 AM
 * Purpose:  Any Factorial
 */

//System Libraries
#include <iomanip>
#include <iostream>   //Input/Output Library
#include <cmath>      //Math Library for Exp, Pow, Logs, etc......
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    unsigned int n;
    float nFctrl=0;
    n=12;
    
    
    //Map inputs to outputs here, i.e. the process
    for(int i=1;i<=n;i++){
        cout<<"ln("<<setw(2)<< i <<") = "<<setw(8)<<log(i);
        nFctrl+=log(i);
        cout<<" nFactorial += "<<nFctrl<<endl;
    }

    cout<<"\tnFactorial = "<<nFctrl<<endl<<endl;
    
    //Display the results
    int intPwr=nFctrl;           //Integer Power
    float fltFrc=nFctrl-intPwr;  //Decimal/Fraction
    float base10=nFctrl/log(10);   //Convert to base 10
    int iPwr10=base10;
    float fFrc10=base10-iPwr10;    
    float e = exp(fltFrc+intPwr);
    
    cout<<n<<"! = e^"<<intPwr<<" = "<<exp(fltFrc)<<" xExp("<<intPwr<<")"<<endl;
    cout<<n<<"! = e^("<<intPwr<<" + "<<fltFrc<<" ) = "<<e<<endl;
    cout<<n<<"! = "<<pow(10,fFrc10)<<" x10^("<<iPwr10<<")"<<endl;
    

    return 0;
}
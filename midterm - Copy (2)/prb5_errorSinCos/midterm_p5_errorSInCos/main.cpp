/* File:    main.cpp
 * Author:  Danielle F
 * Created: 09-28-2023 @ 10 PM
 * Purpose:  
 * https://drlvk.github.io/nm/section-differentiation-intro.html
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
float getOrderE(float &n, const int h);

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers    
    
    //Declare variables here       
    
    //Initialize Variables    
    int h=4, zero;
    float n, err;
    n=zero=err=0; 
    
    n=.012345678910;
    //n=.0123; // h^4
    
    cout<<fixed<<setprecision(14)<<endl
        <<"h:   "<<h<<endl
        <<"n:   "<<n<<endl
        <<"err: "<<err<<endl<<endl;
    
    err = getOrderE(n,h);
    h=err;
    cout<<"\t\n"<<h<<"^"<<n<<"  err = "<<err<<endl<<endl;
    cout<<"Order of error: "<<h<<endl;
    //Display the results
    return 0;
}

float getOrderE(float &n, const int h){
    float e=0;
    int count=0;
    do {    
        //If the error term is some nonzero multiple of a power of h, 
        //the exponent of h is the order of the error term.
        e=pow(h,n);
        cout<<count<<" "<<fixed<<setprecision(14)<<"e = "<<e<<endl;
        if(e>0){ return e; }
        n++;
        count++;
    }while(e==0);
    return e;
}
///**********  Function Implementations  **************/
//int getEOrder(int h){
//    if(h==0) return 1;
//    if(h==1) return 1;
//    //recursion
//    return 1;
//}

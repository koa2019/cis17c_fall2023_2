/* File:   main.cpp
 * Author: Danielle 
 * Created: 11-06-23 @1:30 PM
 * Purpose: Mutual Recursion Midterm problem 11
*/

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library#include <iomanip>0
#include <iomanip>
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
const float deg2Rad = (4*atan(1))/180;
const float rad45 = 45*deg2Rad;

//Function Prototypes
//float recur(float,float &,float &);//Fibonacci Recursion
float cosRecur(float);
float sinRecur(float);
float tanRecur(float);


//Execution Starts Here
int main(int argc, char** argv){
    
    float radian=0,sinX=0,cosX=0,tanX=0;
    for(int x=0;x<=45;x+=5){
        
        radian=x*deg2Rad; 
        sinX=sin(radian);
        cosX=cos(radian);
        
        cout<<"cMath cos("<<setw(2)<<x<<") = "<<cosX<<endl;
        cout<<"Recur cos("<<setw(2)<<x<<") = "<<cosRecur(radian)<<endl;
        
        cout<<"cMath sin("<<setw(2)<<x<<") = "<<sinX<<endl;
        cout<<"Recur sin("<<setw(2)<<x<<") = "<<sinRecur(radian)<<endl;
        
        cout<<"cMath tan("<<setw(2)<<x<<") = "<<tanX<<endl;
        cout<<"Recur tan("<<setw(2)<<x<<") = "<<tanRecur(radian)<<endl;
        cout<<endl;
    }
    return 0;
}

//Function Implementations

float tanRecur(float x){
    //Base Case
    float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(x)<=tol){    
       return x;// Base conditions 
    }    
    //Recursive Representation    
    float xHalf=x/2;
    float tanHalf = tanRecur(xHalf);  
    // tan2x=2tan(x)/1-tan^2(x)
    return 2*tanHalf/(1-tanHalf*tanHalf);
}


float cosRecur(float x){
    //Base Case
    float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(x)<tol){ 
        return 1-x*x/2; 
    }    
    //Recursive Representation    
    float halfX=x/2;
    //float halfC = cosRecur(halfX); 
    float halfS = sinRecur(halfX);  
     //C(2x)=1-2sin^2(x)
    return 1-2*halfS*halfS;
}

float sinRecur(float x){
    //Base Case
    float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(x)<tol){      
        return x;
    }    
    //Recursive Representation    
    float halfX=x/2;
    //sin(2x)=2*sin(x)*cos(x)
    return 2*sinRecur(halfX)*cosRecur(halfX);    
}
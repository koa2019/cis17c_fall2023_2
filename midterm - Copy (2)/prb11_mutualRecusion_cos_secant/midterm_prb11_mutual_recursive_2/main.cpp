/* File:   main.cpp
 * Author: Danielle 
 * Created: 11-06-23 @1:30 PM
 * Purpose: Mutual Recursion Midterm problem 11
 * Takes version 1 and implements new base conditions and formulas
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
const float rad2Deg = 180/(4*atan(1));
const float rad45 = 45*deg2Rad;

//Function Prototypes
//float recur(float,float &,float &);//Fibonacci Recursion
float cosRecur(float);
float sinRecur(float);
float tanRecur(float);


//Execution Starts Here
int main(int argc, char** argv){
    
    float x=0,radian=0,sinX=0,cosX=0,tanX=0,cx=0,sx=0,c2x=0,s2x=0;
    float degree=-45;
    float stop = 45;

    for(float d=degree; d<=stop; d++){
     
        radian=d*deg2Rad; 
        //degree=x*rad2Deg;
        //cx=1+x+(x/6);//cx=x/2;
        //sx=1+((x*x)/2);//sx=x/2;
        //c2x=.5*cx*sx;
        //s2x=cx*cx*sx*sx/(cx*cx-(sx*sx));
        
       //cout<<count<<endl;
        cout<<"Degrees x = " <<d<<endl
            <<"Radians x = " <<radian<<"\n";
        //cout<<"          cx(x) = " <<cx<<endl;
        //cout<<"          sx(x) = " <<sx<<endl;
        //cout<<"         cx(2x) = "<<c2x<<endl;
        //cout<<"         sx(2x) = "<<s2x<<endl;
        cout<<"Recur cos("<<setw(2)<<radian<<") = "<<cosRecur(radian)<<endl;
        cout<<"Recur sin("<<setw(2)<<radian<<") = "<<sinRecur(radian)<<endl;
        cout<<endl;       
    }
 
    return 0;
}

//Function Implementations

float cosRecur(float x){
    //Base Case
    float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(x)<tol){ 
        //return 1-x*x/2; //C(x)=1-(x^2/2!) version 1
       return 1/x+(x/6);// Base conditions C(x)=1/x+x/6    
    }    
    //Recursive Representation    
    float xHalf=x/2;
    float halfCos = cosRecur(xHalf); 
    float halfSin = sinRecur(xHalf);
    //cout<<"\thalfCos="<<halfCos<<"  halfSin="<<halfSin<<endl;
    // C(2x)=.5*C(x)*S(x)    
    return .5*halfCos*halfSin;
    
    //version 1
    //C(2x)=1-2sin^2(x)
    //return 1-2*halfSin*halfSin;
}

float sinRecur(float x){
    //Base Case
    float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(x)<tol){    
        //return x;//S(x)=x version 1
       return 1+x*x/2;// Base conditions S(x)=1+x*x/2    
    }    
    //Recursive Representation    
    float xHalf=x/2;
    float halfCos = cosRecur(xHalf); 
    float halfSin = sinRecur(xHalf);
    
    // S(2x)= C^2(x)*S^2(x)/C^2(x)-S^2(x)
    return halfCos*halfCos*halfSin*halfSin/(halfCos*halfCos-(halfSin*halfSin));
    
    //version 1
    //sin(2x)=*sin(x)*cos(x)
    //return 2*sinRecur(xHalf)*cosRecur(xHalf);    
}

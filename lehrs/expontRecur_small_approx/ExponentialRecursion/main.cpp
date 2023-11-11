/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 21st, 2021, 11:51 AM
 * Purpose: Exponential Sequence
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
float expRec(float);//Exponential Recursion
double expRec(double);//Exponential Recursion
double expRecStupid(double);//Exponential Recursion

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    double dx=5.0;
    float fx=dx;
    
    
    //Initialize Variables
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"Exponential Sequence"<<endl;
    
    //Display the outputs
    cout<<"e^"<<fx<<" Recursive float  -> "<<expRec(fx)<<endl;
    //cout<<"e^"<<dx<<" Recursive double -> "<<expRec(dx)<<endl;
    //cout<<"e^"<<dx<<" Recursive Stupid double -> "<<expRecStupid(dx)<<endl;
    //cout<<"e^"<<fx<<" Math Lib         -> "<<exp(fx)<<endl;

    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations
double expRec(double x){
    int count=0;count++;
    cout<<"\ncount="<<count<<" Start x="<<x<<" ";
    
    //Base Case
    double tol=1e-9f;//Tolerance of 6 decimal, small x approximation
    if(abs(x)<tol){ //Only executes at the very last iteration. when it overflows
        cout<<"\n\tif abs("<<x<<")<"<<tol<< " ? "<<x<<" +1-> x= "<< 1+x<< " \n\n";
        return 1+x;
    }
    
    //Recursive Representation
    cout<<"\n\tBefore Recur x="<<x<<" \n"; //expRec(x/2)="<<x/2<<" ";
    
    double a=expRec(x/2); //only cuttinig the x in half
    
    cout<<" After recur. x= "<<x<<" a*a="<<a*a<<endl;
    
    return a*a;
}

float expRec(float x){
    int count=0;++count;
    cout<<"\ncount="<<count<<"\t       Start x="<<x<<" ";
    
    //Base Case
    float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(x)<tol){
          cout<<"\n\tif abs("<<x<<")<"<<tol<< " ? "<<x<<"+1-> return x= "<< 1+x<< " \n\n";
          ++count;
          return 1+x;
    }
    
    cout<<"\n\tBefore Recur x="<<x<<" \n"; //expRec(x/2)="<<x/2<<" ";
    
    //Recursive Representation
    float a=expRec(x/2);
    
    cout<<"\ncount="<<count<<" After recur.\n\tx= "<<x<<"\n\ta= "<<a<< "\n\ta*a= "<<a*a<<endl;
    
    return a*a;
}

//Function Implementations
double expRecStupid(double x){
    //Base Case
    double tol=1e-9f;//Tolerance of 6 decimal, small x approximation
    if(abs(x)<tol)return 1+x;
    //Recursive Representation
    //double a=expRec(x/2);
    return expRecStupid(x/2)*expRecStupid(x/2);
}
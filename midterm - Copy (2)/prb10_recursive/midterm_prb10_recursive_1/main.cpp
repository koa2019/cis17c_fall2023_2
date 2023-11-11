/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 21st, 2021, 11:51 AM
 * Purpose: Fibonacci Sequence
 * Refer to Lehr's ExponentialRecusion cpp
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
float recur(float,float &,float &);//Fibonacci Recursion

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    float nLoop;
    float numrtr=0.0f,demon=0.0f;
    
    //Initialize Variables
    nLoop=1.1;
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"Recursive Function"<<endl<<endl;  
    
    //Display the outputs
    cout<<left<<fixed;
    for(float n=-1;n<=nLoop;n +=.1){      
        float g2x = recur(n,numrtr,demon);
        cout<<"g("
            <<setw(5)<<setprecision(2)<<n<<" *2) = "<<right
            <<setw(5)<<setprecision(2)<<numrtr<<" / "
            <<setw(4)<<setprecision(2)<<demon <<" = "
            <<setw(7)<<setprecision(4)<<g2x  <<" \n";
    }
    cout<<endl<<endl;

    return 0;
}

//Function Implementations

float recur(float n,float &numrtr, float &denom){
    //Base Case
    //double tol=1e-9f;//Tolerance of 6 decimal, small x approximation
    //float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    //if(abs(n)<tol)return 1+n;
    if(n<-1.1)return 0;
    if(n>1.1)return 0;
    
    //Recursive Representation
    float n2=2*n;
    float gn = n2-(n2*n2*n2/6);
    numrtr = 2*gn;
    denom = gn*gn+1;
    //cout<<n<<" g(2*n) = "<<gn<<" "<<numrtr<<" / " <<denom<< " = " <<numrtr/denom<<endl;
    return numrtr/denom;
}
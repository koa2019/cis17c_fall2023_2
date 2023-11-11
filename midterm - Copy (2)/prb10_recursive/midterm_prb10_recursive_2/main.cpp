/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 21st, 2021, 11:51 AM
 * Purpose: Fibonacci Sequence
 * Refer to Lehr's ExponentialRecusion cpp
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library#include <iomanip>0
#include <iomanip>
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow

//Function Prototypes
//float recur(float,float &,float &);//Fibonacci Recursion
float recur(float);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    float nLoop;
    
    //Initialize Variables
    nLoop=1.1;
    float n=-1.0f;
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"Recursive Function"<<endl<<endl;  
    
    //Display the outputs
    cout<<left<<fixed; 
    cout<<setw(7)<<setprecision(4)<<recur(n)<<")=recur \n";

    return 0;
}

//Function Implementations
float recur(float n){
    
    int count=0; count++;
    float numrtr=0, // 2g(n)
          denom=0;//recur(n*n+1);  
    
    //Base Case
    cout<<"count="<<count<<" Start n= "<<n<<" ";
    
    //Base Case
    float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(n)<tol){
        cout<<"\n\tif abs("<<n<<")<"<<tol<< " ? "<<n<<" +1-> n= "<< 1+n<< " \n\n";
        return 1+n;
    }
    
    //n *=2;
    //n +=.1;
    
    //float gn = n-(n*n*n/6);
    //cout<<"  else g("<<n<<")= "<<gn<< " ";   
    
    float gn = n*2-(n*2*n*2*n*2/6);  
    numrtr = gn*2;
    denom = (gn*gn)+1;//recur(n*n+1); 
    
    cout<<"\n\tg("<<n*2<<")= "<<gn<< " \n"; 
    cout<<"\tg(2N)= "<<numrtr<<" / "<<denom<<" = "<<numrtr/denom<<endl;
    //cout<<"numrtr="<<numrtr<<" denom="<<denom<<" g(2N)= "<<numrtr/denom<<endl;
    
    
    //Recursive Representation    
    cout<<"\tBefore Recur n= "<<n<<" \n\n";
    
    float a = recur(n+.1); 
    
    cout<<" After Recur n= "<<n<<" a= "<<a<<"\n";
    
    
    //numrtr = a*2;
    //denom = (a*a)+1;//recur(n*n+1);   
    //cout<<"\tnumrtr="<<numrtr<<" denom="<<denom<<" num/dem="<<numrtr/denom<<endl;
     
    
    return a;
}
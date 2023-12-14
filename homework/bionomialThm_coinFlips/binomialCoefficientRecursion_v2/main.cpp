/* File:   main.cpp
 * Author: Danielle and Dr. Mark E. Lehr
 * Created: 2023 
 * Purpose: Bias Coin flip Binomial Coefficient v2
 * 
 * Probability for unbiased coin flip .6/1 = 60% probability.
 * Probability equation: 
 *          https://onlinestatbook.com/2/probability/binomial.html
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
float factFor(float);//Factorial Product
int factRec(int);//Factorial Recursive 
float bCoeff(float,float);//Recursive Binomial Coefficent

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables     
    int nLoops=10000,       
        nHeads=1, // number of possible heads
        nFaces=2, // number of faces on coin
        nCoins=1, // number of coins flipping
        n = nCoins*nFaces,//number of coins multiplied by faces on 1 coin       
        a,    // numerator
        b,   // previous element
        c,   // current element
        d,   // denom
        bioNCoef;//bioNCoef formula      
 
    float bias=nHeads*1.0/n,// coin bias. Normally 50%
          problty; // probability formula   
    
    for (int i = 0; i < nLoops; i++) {
        a = factRec(n);   // numerator
        b = factRec(n-nHeads); // previous element
        c = factRec(nHeads);  // current element
        d = b*c;      // denom
        bioNCoef = a/d;  // bioNCoef formula
        problty = pow(bias,n)*pow((1-bias),2-n); //probability    
    }
    
    //BCoeff breaks
    //cout<<"Using Recursion "<<n<<"C"<<showpoint<<nHeads<<" = "<<bCoeff(n,nHeads)<<endl;
    
    
    cout<<fixed<<setprecision(2);
    cout<<"Using formula:\n"<< "C(" 
        << nHeads << ","
        << setprecision(0) << n <<") = "
        << a << "/" 
        << setprecision(2) << b << "*" << setprecision(2)<< c 
        << " = " << bioNCoef << " * " << problty 
        << " = " << bioNCoef*problty <<"%\n";
    
    //Original output from lehr's example in pascallTriangleBinomialCoefficientRecur
    //cout<<"Using formula   "<<n<<"C"<<nHeads<<" = "
            //<<factRec(n)/(factRec(n-nHeads)*factRec(nHeads))<<endl;

    return 0;
}

//Function Implementations
float bCoeff(float n,float nHeads){
    //Base conditions for the recursion
    if(nHeads==0)return 1;
    if(n==nHeads)return 1;
    //Recursive Form
    return bCoeff(n-1,nHeads-1)+bCoeff(n-1,nHeads);
}

float factFor(float n){
    float fact=1;
    for(float i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}

int factRec(int n){
    //Base Case
    if(n<=1)return 1;
    //Recursive Representation
    return factRec(n-1)*n;
}
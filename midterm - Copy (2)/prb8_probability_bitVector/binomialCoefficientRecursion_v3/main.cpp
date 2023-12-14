/* File:   main.cpp
 * Author: Danielle and Dr. Mark E. Lehr
 * Created: 2023 
 * Purpose: Bias Coin flip Binomial Coefficient v3
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
void getResults(int n, int m, int nFlips, float bias);
float factFor(float);//Factorial Product
int factRec(int);//Factorial Recursive 
float bCoeff(float,float);//Recursive Binomial Coefficient

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables     
    int nFlips=1,       
        m=5, // number of possible heads
        nCoins=1, // number of coins flipping
        n = 5;//number of coins multiplied by faces on 1 coin       
    float bias = .60;// coin bias. Normally 50%    
         
    getResults(n,m,nFlips,.4);  
    cout<<endl<<endl;  
    
    getResults(n,m,nFlips,bias);   
   
    // bCoeff BREAKS
    //cout<<"Using Recursion " << n << "C" << m << " = " << bCoeff(n,m) <<endl;
    
    // Original output from lehr's example in pascallTriangleBinomialCoefficientRecur
    // cout<<"Using formula   "<<n<<"C"<<m<<" = "
            //<<factRec(n)/(factRec(n-m)*factRec(m))<<endl;
    
  
    return 0;
}
//Function Implementations
 void getResults(int n, int m, int nFlips, float bias){
    int a,    // numerator
        b,   // previous element
        c,   // current element
        d,   // denom
        binoCoef;//binoCoef formula      
 
    float problty, // probability formula   
          sumProblty = 0;
    
    // simulate flipping 4 coins nFlips times
    for (int i = 0; i <= nFlips; i++) {
        // Calculate probability
        a = factRec(n);   // numerator
        b = factRec(n-m); // previous element
        c = factRec(m);  // current element
        d = b*c;      // denom    
   
        binoCoef = a/d;  // binoCoef formula
        problty = pow(bias,n)*pow((1-bias),n-m); //probability    
        sumProblty += problty;
        cout<<"sumProb = "<<sumProblty<<endl;
    }cout<<endl;
    
    // Print results
    cout<<fixed<<setprecision(2);
    cout<<"Binomial Equation using Factorial Recursion formula:\n"
        <<"Bias: " << bias*100 << "% heads\n"
        << "C(" << m << ","
        << setprecision(0) << n <<") = "
        << a << "/" 
        << setprecision(2) << b << "*" << setprecision(2) << c 
        << " = " << binoCoef << " * " << setprecision(5) << problty 
        << " = " << setprecision(3) << binoCoef*problty*100 <<"%\n";
    }
    

int bCoeff(int n,int j){
    //Base conditions for the recursion
    if(j==0)return 1;
    if(n==j)return 1;
    //Recursive Form
    return bCoeff(n-1,j-1)+bCoeff(n-1,j);
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
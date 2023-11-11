/* 
 * File:   main.cpp
 * Author: Danielle
 * Created: 11-01-23
 * Purpose: Midterm prb 9 
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <iomanip>
using namespace std;  //Library Scope

//User Libraries
//Global Constants
//Function Prototypes
//float pow(float,int);//z=base^pwr
float power(float,float);//How computer calculate base^pwr
float powerExp(float);
float powerLNRec(float,float);
float logFact(int);
float logFactRec(int);
float powRec(float,int);
void sumOfNFactLogs(float, float);


//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here

    //Declare and initialize values
    const float e = 2.71828;
    float base=3;
    float pwr=4;
    
    cout<<endl<<endl;
    
    //Compare with how implemented in the computer
    cout<<"cmath        pow("<<base<<","<<pwr<<") "<<base<<"^"<<pwr<<" = "<<pow(base,pwr)<<endl;
    cout<<"Recursive Power ("<<base<<","<<pwr<<") "<<base<<"^"<<pwr<<" = "<<powRec(base,pwr)<<endl;

    
    cout<<endl<<endl;
   
    cout<<"             cmath ln("<<base<<") = "<<log(base)<<endl;
    cout<<"Power ln Recursive ln("<<base<<") = "<<logFactRec(base)<<endl;
    
    //cout<<endl<<"Recursive Power ";
    //cout<<"logFact("<<base<<") = "<<logFact(base)<<endl;
    //cout<<"logFact("<<base-1<<") = "<<logFact(base-1)<<endl<<endl;    
    //float ln = logFact(base)-logFact(base-1);
    //cout<<"ln("<<base<<") = "<<ln<<endl;
    
//    cout<<endl<<endl;
//    cout<<"cmath      exp("<<base<<") = "<<exp(base)<<endl;
//    cout<<"cmath      exp("<<base<<") = "<<exp(base)<<endl;
//    cout<<"       power(e,"<<base<<") = "<<power(e,base)<<endl;
//    cout<<"  powerLNRec(e,"<<base<<") = "<<powerLNRec(e,base)<<endl;
//    cout<<endl<<endl;
//    
//    cout<<"cmath      exp("<<log(base)<<") = "<<exp(log(base))<<endl;
//    cout<<"cmath       ln("<<exp(base)<<") = "<<log(exp(base))<<endl;
//    cout<<"        power(e,ln("<<base<<"))  = "<<power(e,log(base))<<endl<<endl;
//    
//    cout<<"cmath   exp(ln(e)) = "<<exp(log(e))<<endl;
//    cout<<"powRec(e,ln(base)  = "<<powRec(e,log(base))<<endl;
//    cout<<"powerLNRec(e,ln(e) = "<<powerLNRec(e,log(e))<<endl;
//    cout<<endl<<endl;
//    
//    cout<<"powRec(ln(base),e) = "<<powRec(log(base),e)<<endl;
//    
//    
//    
//    cout<<"  powerLNRec(,e) = "<<powerLNRec(e,log(base))<<endl;
//    cout<<"  powerLNRec("<<log(base)<<",e) = "<<powerLNRec(log(base),e)<<endl;
    
    
    
//    cout<<endl<<"Recursive Power ln(n)\n";
//    cout<<"logFact("<<base<<") = "<<logFact(base)<<endl;
//    cout<<"logFact("<<base-1<<") = "<<logFact(base-1)<<endl<<endl;    
//    float ln = logFact(base)-logFact(base-1);
//    cout<<"ln("<<base<<") = "<<ln<<endl;
    
    //cout<<"e^"<<base<<" = "<<exp(logFact(base))<<endl<<endl;
    
    
    //cout<<base<<"! = e^(logFact(base*pwr)) = "<<exp(logFact(base))<<endl;
     
    //cout<<endl<<"N FACTORIAL SUM OF LOGS"<<endl;
    //sumOfNFactLogs(base,1);
    
    return 0;
}

//Based off of logFact(int n)
float logFactRec(int n){
    //Base Condition
    if(n<=1)return 0;
    //Recursion
    float logN = log(n);
    float logNLess1 = logFact(n-1);
    float logFactN = logNLess1+logN;//logFact(n-1)+log(n);     
    float logNLess2 = logFact(n-2);
    float logFactNLess2 = logNLess2+logNLess1;//logFact(n-2)+log(n-1);   
    return logFactN-logFactNLess2;//logFactN-logFactNLess1;    
}

// f(n)=ln(n) == loge(n), 
// then f-1(n) = e^n. exp(
float logFact(int n){
    //Base Condition
    if(n<=1)return 0;
    //Recursion
    //like powRec(base,n-1)*base == base^2*base^1=base^3
    return logFact(n-1)+log(n);
}


//power recursion
float powRec(float base,int n){
    //Base Condition
    if(n<=0)return 1;
    //Recursion
    return powRec(base,n-1)*base;//base^n
}

//How computer calculate base^n
//ex = exp(base) 
float power(float base, float pwr){
    //cout<<"n="<<pwr<<" *ln("<<base<<") = "<<pwr*log(base)<<endl;
    return exp(pwr*log(base));
}


//power recursion
float powerLNRec(float e, float n){
   
    //Base Condition
    if(n<=0)return 1;
    //Recursion
    return powerLNRec(e,n-1)*e;//e^n
}


//How computer calculate lnn
//ex = exp(base) 
float powerExp(float base){
    //cout<<"n="<<pwr<<" *ln("<<base<<") = "<<pwr*log(base)<<endl;
    return exp(log(base));
}



void sumOfNFactLogs(float base, float pwr){
    
    /*  N FACTORIAL USING SUM OF LOGS*/
    
    //Declare variables here
    unsigned int n;
    float nFctrl=0;
    n=base*pwr;
    
     //Map inputs to outputs here, i.e. the process
    for(int i=1;i<=n;i++){
        cout<<"ln("<<setw(2)<< i <<") = "<<setw(8)<<log(i);
        nFctrl+=log(i);
        cout<<" nFactorial += "<<nFctrl<<endl;
    }

    cout<<"\t nFactorial = "<<nFctrl<<endl<<endl;
    
    //Display the results
    int intPwr=nFctrl;           //Integer Power
    float fltFrc=nFctrl-intPwr;  //Decimal/Fraction
    float base10=nFctrl/log(10);   //Convert to base 10
    int iPwr10=base10;
    float fFrc10=base10-iPwr10;    
    float e = exp(fltFrc+intPwr);
    
    cout<<n<<"! = e^"<<fltFrc<<" = "<<exp(fltFrc)<<" base e("<<intPwr<<") = "<<exp(intPwr)<<endl;
    cout<<n<<"! = e^("<<intPwr<<" + "<<fltFrc<<" ) = "<<e<<endl;
    cout<<n<<"! = "<<pow(10,fFrc10)<<" x10^("<<iPwr10<<")"<<endl;
    
}
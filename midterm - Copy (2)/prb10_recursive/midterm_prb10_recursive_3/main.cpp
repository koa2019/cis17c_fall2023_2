/* 
 * File:   main.cpp
 * Author: Danielle 
 * Created: 11-02-23 @8PM
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
double dblRecur(double,int x=1);
float recur(float,int x=1);
float recur2(float,int x=1);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    double nd = -1.0;
    float n = -1.0f;
    int x=2;
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"\tRecursive Function"<<endl<<endl;  
    
    //Display the outputs
    cout<<left<<showpoint; 
 
    cout<<"float  g("<<setw(8)<<right<<n<<setw(5)<<") = "<<setprecision(7)<<recur(n)<<"\n"; 
    cout<<"float  g("<<setw(7)<<2*n<<") = "<<setprecision(7)<<recur(2*n,x)<<"\n";    
    //cout<<"double g("<<setw(8)<<nd<<") = "<<setprecision(7)<<dblRecur(nd)<<"\n"; 
    //cout<<"double g("<<setw(8)<<2*nd<<") = "<<setprecision(7)<<dblRecur(2*nd,2)<<"\n";

   
    int input=0;
    do{
        cout<<endl<<endl;
        cout<<"Press 1: to show g(n)\n"
            <<"Press 2: to show g(2n)\n"
            <<"Press Enter: to exit\n";     
        input=0;
        cin>>input;
        if(input==1)recur2(n);
        else if(input==2)recur2(2*n,x);        
    }while(input==1 || input==2);

    return 0;
}

//Function Implementations
double dblRecur(double n, int x){
    
    int count=0; count++;
    double numrtr=0, // 2g(n)
          denom=0;//recur(n*n+1);  
    
    //Base Case
    //cout<<"count="<<count<<"        Start n= "<<n<<" ";
    
    //Base Case
    double tol=1.0e-9f;//Tolerance of 9 decimal, small x approximation
    if(abs(n)<tol){
        //cout<<"\n\tabs("<<n<<")<  "<<tol<< " ? "<<n<<" +1-> n= "<< 1+n<< " \n";
        return 1+n;
    }

    //cout<<"\n\tBefore Recur n= "<<setprecision(6)<<n<<" \n\n";
    
    
    //Recursive Representation  
    double a = dblRecur(n+.1); 
    //cout<<"\nAfter Recur \n\tn= "<<n<<"\n\ta= "<<a<<"\n";
    a *=x;
    
    
    double gn = a-(a*a*a/6); //n-(n*n*n/6); // 
    numrtr = gn*2;
    denom = (gn*gn)+1;//recur(n*n+1); 
    
    
    //cout<<"\tg("<<a<<")= "<<gn<< " \n"; 
    //cout<<"\tg(n)= "<<numrtr<<" / "<<denom<<" = "<<numrtr/denom<<endl;
    //cout<<"\tg(a) = g("<<a<<")= "<<numrtr/denom<<"\n";
    //cout<<"\tg(n) = g("<<n<<")= "<<numrtr/denom<<"\n"
    cout<<"\tn="<<left<<setw(11)<<n<<" a="<<setw(9)<<a<<" g(n)="<<numrtr/denom<<"\n";
    
    return numrtr/denom; //a*a;//
}



//Function Implementations
float recur(float n,int x){
    
    int count=0; count++;
    float numrtr=0, // 2g(n)
          denom=0;//recur(n*n+1);  
    
    //Base Case
    //cout<<"count="<<count<<"        Start n= "<<n<<" ";
    
    //Base Case
    float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(n)<tol){
        //cout<<"\n\tabs("<<n<<")<  "<<tol<< " ? "<<n<<" +1-> n= "<< 1+n<< " \n";
        return 1+n;
    }

    //cout<<"\n\tBefore Recur n= "<<setprecision(6)<<n<<" \n\n;    
    
    //Recursive Representation
    float a = recur(n+.1f); 
    //cout<<"\nAfter Recur \n\tn= "<<n<<"\n\ta= "<<a<<"\n";   
    a *=x;
    
    float gn = a-(a*a*a/6); //n-(n*n*n/6); // 
    numrtr = gn*2;
    denom = (gn*gn)+1;//recur(n*n+1); 
    
    //cout<<"\tg("<<a<<")= "<<gn<< " \n"; 
    //cout<<"\tg(n)= "<<numrtr<<" / "<<denom<<" = "<<numrtr/denom<<endl;
    //cout<<"\tg(a) = g("<<a<<")= "<<numrtr/denom<<"\n";
    //cout<<"\tg(n) = g("<<n<<")= "<<numrtr/denom<<"\n"
    //cout<<"\tn="<<left<<setw(11)<<n<<" a="<<setw(9)<<a<<" g(n)="<<numrtr/denom<<"\n";
    
    return numrtr/denom;
}


//prints from within the function instead of in main()
float recur2(float n, int x){
    
    int count=0; count++;
    float numrtr=0, // 2g(n)
          denom=0;//recur(n*n+1);  
    
    //Base Case
    //cout<<"count="<<count<<"        Start n= "<<n<<" ";
    
    //Base Case
    float tol=1.0e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(n)<tol){
        //cout<<"\n\tabs("<<n<<")<  "<<tol<< " ? "<<n<<" +1-> n= "<< 1+n<< " \n";
        return 1+n;
    }

    //cout<<"\n\tBefore Recur n= "<<setprecision(6)<<n<<" \n\n";
    
    
    //Recursive Representation    
    float a = recur2(n+.1f); 
    a *=x;
    //cout<<"\nAfter Recur \n\tn= "<<n<<"\n\ta= "<<a<<"\n";
    
    
    
    float gn = a-(a*a*a/6); //n-(n*n*n/6); // 
    numrtr = gn*2;
    denom = (gn*gn)+1;//recur(n*n+1); 
    
    //cout<<"\tg("<<a<<")= "<<gn<< " \n"; 
    //cout<<"\tg(n)= "<<numrtr<<" / "<<denom<<" = "<<numrtr/denom<<endl;
    //cout<<"\tg(a) = g("<<a<<")= "<<numrtr/denom<<"\n";
    //cout<<"\tg(n) = g("<<n<<")= "<<numrtr/denom<<"\n"
    cout<<"\tn="<<left<<setw(11)<<n<<" a="<<setw(9)<<a<<" g(n)="<<numrtr/denom<<"\n";
    
    return numrtr/denom; //a*a;//
}
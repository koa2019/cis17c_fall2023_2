/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 09-28-2023 @ 12AM
 * Purpose: slope intercept curve fit line.
 *          Take formulas in the excel sheet within this project 
 *          and create a program that mirrors the excel data.
 *          Reference cis110c>lectures>09-11-23_1stOrderCurveFit_inPrep4BigO.
 * 
 * slope: m' = (SumY'*SumX-(n*SumXY')) / ((SumX)^2-(Rows*SumX^2))
 * y-intercept: b' = (SumY'-mSumX)/n;
 * 
 * Input: read data from a file.
 * Output: see expectedOutput.png
 * 
 */

//System Libraries
#include <bits/stdc++.h> 
#include<iostream>
#include<iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
float **readFile(int&,float&,float&,float&);
float square(float **,int, int);
float multiply(float **,int,int,int);
void print(float,float,float,float,float,float,float,float,float,float);
void destroy(float **,int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers      
        
    int Rows;
    float sumX, //Sum of X
          sumY, //Sum of Y
          sumYprime; //Sum of Y' which is Y plus errors
    Rows=sumX=sumY=sumYprime=0;      
    
    float **Data=readFile(Rows,sumX,sumY,sumYprime);
    
    // Summations
    float sumXX = multiply(Data,Rows,0,0);
    float sumXYprime = multiply(Data,Rows,0,2);
    
    //Derived calculations for a line
    float m = (Data[21][1]-Data[10][1])/(Data[21][0]-Data[10][0]);
    float b = -32*m;  
    
    //Least squares curve fit for a line
    float mPrime = ((sumYprime*sumX)-(Rows*sumXYprime))/((sumX*sumX)-(Rows*sumXX));
    float bPrime=(sumYprime-(mPrime*sumX))/Rows;  
    print(Rows,sumX,sumY,sumYprime,sumXX,sumXYprime,m,b,mPrime,bPrime);           
    
    // Destroy dynamic 2D array's memory
    destroy(Data,Rows);

    return 0;
}

/**********  Function Implementations  **************/

// c==0 x variables, c==1 y variables, c==2 y' = y+error variables
float multiply(float **Data,int Rows,int left, int right){
    float temp,sum=0;
    for(int r=0;r<Rows;r++){      
        for(int c=0;c<=left;c++){            
           //cout<<"["<<r<<","<<c<<"]="<<Data[r][c]<<" ";           
            temp=Data[r][left]*Data[r][right];
            //cout<<Data[r][left]<<" * "<<Data[r][right]<<" = "<<temp;
            sum+=temp;
            //cout<<sum<<endl;
            temp=0;  
        }//cout<<endl;
    }
    return sum;
}

void print(float Rows,float sumX,float sumY,float sumYprime,float sumXX,
        float sumXYprime,float m,float b,float mPrime,float bPrime){
cout<<left
    <<setw(10)<<"n: "<<Rows<<endl
    <<setw(10)<<"|error|:  7.5"<<endl
    <<setw(10)<<"sumX: "<<sumX<<endl
    <<setw(10)<<"sumY: "    <<sumY<<endl
    <<setw(10)<<"sumY': "  <<sumYprime<<endl
    <<setw(10)<<"(sumX)^2: "<<sumX*sumX<<endl//(sumX)^2    
    <<setw(10)<<"sumX^2: "  <<sumXX<<endl //sx^2
    <<setw(10)<<"sumXY': " <<sumXYprime<<endl;
    
    cout<<fixed<<setprecision(4)<<endl;
    cout<<setw(9)<<"Expected "<<setw(4)<<"m : " <<setw(3)<<m<<endl;
    cout<<setw(9)<<"Derived " <<setw(4)<<"m': "<<setw(3)<<mPrime<<endl;
    cout<<setw(7)<<"Expected b : "<<b<<endl;
    cout<<setw(7)<<"Derived  b': "<<bPrime<<endl<<endl;
    cout<<"Expected line: y = "<<m<<"x + "<<b<<endl;
    cout<<"Derived  line: y = "<<mPrime<<"x + "<<bPrime<<endl;
 }

float **readFile(int &Rows,float &sumX,float &sumY,float &sumYprime){
    
    //Declare the Row and Empirical Data files
    char fn_r[]="r.dat";//r file name -> Set point X functional values
    char fn_f[]="f.dat";//f file name -> Measured data Y        
    ifstream in;
    in.open(fn_r);
    float rd,cd;
    in>>rd;//37 Rows
    in>>cd;//3 Cols: X,Y,Y'
    Rows=static_cast<int>(rd);
    int Cols=static_cast<int>(cd);
    float **Data=new float*[Rows];// Allocate a Row of pointers
    for(int r=0;r<Rows;r++){// Rows=310
        Data[r]=new float[Cols]; // Allocate an array of floats to each Row in **Data
    }
    
    // Initialize 2D ptr
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            Data[r][c]=0; // Allocate an array of floats to each Row in **Data
        }
    }
    
    // Read data in from file. 
    // File contains Row x Cols matrix which is 310x3.
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
                in>>Data[r][c]; //Read and set array element
                //cout<<fixed<<setprecision(2);
                //cout<<"["<<r<<","<<c<<"]="<<Data[r][c]<<" ";
                
                if(cd>0 && c==0){ //column 0 represents variables of X
                    sumX+=Data[r][c];
                    //cout<<"["<<r<<","<<c<<"]="<<Data[r][c];
                    //cout<<" sumX="<<sumX<<" ";
                    
                } else if(cd>0 && c==1){//column 1 represents variables of Y
                    sumY+=Data[r][c];
                    //cout<<"["<<r<<","<<c<<"]="<<Data[r][c]<<" sumY=";
                    //cout<<" sumY="<<sumY<<" ";
                    
                } else {//column 2 represents variables of Y'=Y+error
                    sumYprime+=Data[r][c];
                    //cout<<"["<<r<<","<<c<<"]="<<Data[r][c]<<" sumYprime=";
                    //cout<<" sumYprime="<<fixed<<setprecision(2)<<sumYprime<<" ";
                }
        }//cout<<endl;
    }//cout<<endl;
    //cout<<"sumX="<<sumX<<"\nsumY="<<sumY<<"\nsumY'="<<sumYprime<<" \n\n";
    //cout<<"\neof...\n\n";
    in.close();
    return Data;
}
void destroy(float **Data,int Rows){
    for(int r=0;r<Rows;r++){
       delete Data[r]; // Allocate an array of floats to each Row in **Data      
    }
    delete [] Data;
    Data=nullptr;
}
/*Danielle edited Dr. Mark E. Lehr
  09-2023
  Purpose:  Curve fit of Data Structure empirical timing and/or
            operational analysis
			
			* r.dat contains x data when n^0, n^1, n^2.
			
			* f.dat constains y` prime which is y+errors. 
				  Note when we get the data from our analysis we represetnt the errors, so we are y prime. 
				  In farehnTemp spreadsheet we calculaed y` with errors because we were't
				  doing timing analysis on it.
			
			* c.dat prints 3 coeffiencients
			
			* Using data from Lehr's TemperatureLinearCurveFitLeastSquares.ods
			  and df_TemperatureLinearCurveFitLeastSquares.ods
			
			* Problem: couldn't get anything to print in main.
			
*/
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries 
#include "mArray.h"

//Global Constants - Physics, Math, Conversions, Dimensions for
//function prototypes only!

//Function Prototypes

//Execution begins here
int main(){
    //Declare the Row and Empirical Data files
    char fn_r[]="r.dat";//r file name -> Set point X functional values
    mArray r(fn_r);     //Independent variable, form of the equation
    char fn_f[]="f.dat";//f file name -> Measured data Y
    mArray f(fn_f);     //Dependent variable, from empirical data run
    
    //r.getThis(f);
    
    int row=r.getRows(), col=r.getCols();
    double sx=r.getSumX(),
           sy=r.getSumY(), 
           sxy=r.getSumX()*r.getSumY(),
           sye=f.getSumYE();
    cout<<row<<" "<<col<<endl;
    
    cout<<fixed<<setprecision(2)
        <<"n:      "<<row<<endl
        <<"sumX:   "<<sx<<endl
        //<<"\nsumY:  "<<sy<<endl
        <<"sumX*X: "<<sx*sx<<endl     
        <<"sumXY:  "<<sxy<<endl   
        <<"sumY':  "<<sye<<endl        
        <<endl;
    //double m = ((sye*sx)-(Rows*sxye))/((sx*sx)-(Rows*sxsx));
    //cout<<"slope: "<<m<<endl;
    double b=(sy-.555555556*sx)/row;  
    cout<<"b: "<<b<<endl;
   
//    float num=0;
//    //cout << r.getData(0,1) <<" "; 
//    
//   for(int r=0;r<row;r++){
//        for(int c=0;c<col;c++){    
//            num = r.getData(r,c);
//            cout << num <<" ";    
//        } cout<<endl;
//    } 
    
    //Make the Sum of Squares Calculation c=(rt*r)^-1
    mArray rt(false,r); //Transpose of independent variable
    mArray c=mArray::invMat(rt*r)*rt*f;
    
    //Output the results
    char fn_c[]="c.dat";//c file name -> Functional Coefficients solutions
    c.mPrint(fn_c);     //Where curve fit coefficients are printed
    
    return 0;
}
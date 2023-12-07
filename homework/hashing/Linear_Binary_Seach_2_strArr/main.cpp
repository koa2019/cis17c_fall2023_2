/* 
 * File:   main.cpp
 * Author: Danielle and Dr. Mark E. Lehr
 * Purpose:  Using string arrays
 * Common searching and sorting algorithms
 * Binary and Linear Timing and Operational Analysis
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono> //microseconds 
using namespace std;
// this namespace is used to perform calculation
using namespace chrono; //https://www.geeksforgeeks.org/how-to-calculate-running-time-in-microseconds-in-cpp/

//Global Constants Only, No Global Variables
int ob,//operations before
    oeq,//equal sign
    olt,//less than
    oinc,//increment
    osub,//subtract
    oadd,//add
    odiv,//divide
    ogt,//greater than
    oi,//index
    count2;
//Linear search global vars
int ob1,//operations before
    oeq1,//equal sign
    olt1,//less than
    oinc1,//increment
    osub1,//subtract
    oadd1,//add
    odiv1,//divide
    ogt1,//greater than
    oi1,//index
    count1;

//Function Prototypes Here
void prntAry(const string [],int n,int perLine);
void copyAry(string [],string [],int n);
void fillAry(string [],int n,char z='z',char a='a');

int  linSrch(string [],int n, int val);
int  binSrch(string [],int, string);
void selSort(string [],int);


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    //const int SIZE=100000;
    int arrSize=10, strLeng=20;
    int perLine=10;
    int value=0,found=0,found2=0;   
    string str1[arrSize]={};
    string str2[arrSize]={};
    string str3[arrSize]={};
    char a=97,z=122;
    
    // fill string array    
    for(int indx=0;indx<arrSize;indx++){
        for(int j=0;j<strLeng;j++){
            str1[indx]+=rand()%(z-a+1)+a;
        } //cout<<str1[indx]<<endl;
    } //cout<<endl<<endl;   
    
    // make 2 copies of str1 array
    for(int i=0;i<arrSize;i++){
        str2[i]=str1[i];
        str3[i]=str1[i];
    }        
  
    //Finish initializing the rest of the array
    //fillAry(str1,arrSize,z,a);
    //copyAry(str2,str1,arrSize);
    //copyAry(str3,str1,arrSize);
    
    //Print the values in the array
    
    cout<<"String array 2:\n";
    prntAry(str2,arrSize,perLine); 
    cout<<"String array 3:\n";
    prntAry(str3,arrSize,perLine); 
    // Sort the array the for all positions
    //selSort(str1,arrSize);
    //cout<<"After Sorting"<<endl; prntAry(str1,arrSize,perLine); 
    
    
    
    //*************************************************************
    //                    Linear Search Analysis 
    //*************************************************************
    cout<<"\n\n\nUsing the Linear Search"<<endl;  
    auto start1 = high_resolution_clock::now();//int beg=time(0);
    int nLoops=1;
    for(int i=0;i<nLoops;i++){
        
        //Test the linear search by randomly choosing a value and determine if found;
        value=rand()%9;//(highRng-lowRng+1)+lowRng;        
     
        //Linear Search
        found = linSrch(str1,arrSize,value);
        
        if(i==0){
            cout<<"Linear Operational Analysis Results\n";
            cout<<"Before="<<ob1<<endl
            <<"Eq="<<oeq1<<endl
            <<"Lt="<<olt1<<endl
            <<"Inc="<<oinc1<<endl
            <<"Sub="<<osub1<<endl
            <<"Add="<<oadd1<<endl
            <<"Div="<<odiv1<<endl
            <<"Gt="<<ogt1<<endl
            <<"Indx="<<oi1<<endl
            <<"\tLinear Op Total="<<ob1+oeq1+olt1+oinc1+osub1+oadd1+odiv1+ogt1+oi1<<endl<<endl;
        }
    }
    // Timer ends now
    auto stop1 = high_resolution_clock::now();
    // Difference is calculated
    auto duration = duration_cast<microseconds>(stop1 - start1);    
    
    // Linear Timing analysis results    
    cout<<"String array 1:\n";
    prntAry(str1,arrSize,perLine);
    cout<<"["<<value<<"] "<<str1[value]<<" was found at position "<<found<<endl;
    cout<<"nLoops: "<<nLoops<<endl;
    cout<<"N: "<<arrSize<<"\n";
    cout<<"Linear Search: "
        << (double)(duration.count() / 1000.0) << " microseconds\n";
    
    
    //*************************************************************
    //              Binary Search Analysis 
    //*************************************************************
    cout<<"\n\n\nUsing the Binary Search"<<endl;
    // Sort the array the for all positions
    //cout<<"Sorting String array2...\n";
    selSort(str2,arrSize);
     
    
    start1 = high_resolution_clock::now();//int beg=time(0);
    for(int i=0;i<nLoops;i++){  
        //Binary Search
        found2 = binSrch(str2,arrSize,str1[value]);
        if(i==0){
            cout<<"Binary Operational Analysis Results\n";
            cout<<"Before="<<ob<<endl
            <<"Eq="<<oeq<<endl
            <<"Lt="<<olt<<endl
            <<"Inc="<<oinc<<endl
            <<"Sub="<<osub<<endl
            <<"Add="<<oadd<<endl
            <<"Div="<<odiv<<endl
            <<"Gt="<<ogt<<endl
            <<"Indx="<<oi<<endl
            <<"\tBinary Op Total="<<ob+oeq+olt+oinc+osub+oadd+odiv+ogt+oi<<endl<<endl;
        }        
    }
    // Timer ends now
    stop1 = high_resolution_clock::now();
    // Difference is calculated
    duration = duration_cast<microseconds>(stop1 - start1);  
    
    cout<<"After Sorting String array2:"<<endl;
    prntAry(str2,arrSize,perLine); 
    cout<< str1[value]<<" was found at position "<<found2<<endl;
    cout<<"nLoops: "<<nLoops<<endl;
    cout<<"N: "<<arrSize<<"\n";
    cout<<"Binary Search: "
        << (double)(duration.count() / 1000.0) << " microseconds\n";
    
    
    //Exit
    return 0;
}


int  binSrch(string a[],int n, string val){
    //Initialize end points which are indexes    
    int lowEnd=0;
    int highEnd=n-1;
    ob++; oeq+=2; osub++;
    
    //Loop until value found not indexes
    do{
        count2++;
        int middle=(highEnd+lowEnd)/2;
        oeq++; oadd++; odiv++;
        if(val==a[middle]){
            oeq++;
            //cout<<endl<<val<<" == "<<a[middle]<<" ?";
            //cout<<"\tBinary middle="<<middle<<endl<<endl;
            return middle;
        }
        else if(val>a[middle]){
            lowEnd=middle+1;
            oeq++; ogt++; oadd++; 
        } else {            
            highEnd=middle-1;
            oeq++; osub++; 
        }   
        oi++;
    }while(lowEnd<=highEnd);
    olt++;    
    //cout<<"lowEnd="<<lowEnd<<" hiEnd="<<highEnd;
    //cout<<" count2 = "<<count2<<endl;    
    oeq++;
    return -1;//Not found
}

int  linSrch(string a[],int n, int val){
    ob1++;
    for(int indx=0;indx<n;indx++){
        oi1++; oeq1++; olt1++; oinc1++;
        if(a[val]==a[indx]){
            oeq1++; ob1++;
            //cout<<"\tLinear indx="<<indx<<endl;
            return indx; 
        }    
    }
    ob1++;
    return -1;
}


void selSort(string a[],int n){
    sort(a, a+n);
}


void copyAry(string copyIt[],string source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void fillAry(string strArr[], int n, char z, char a){
    //char a=97,z=122;
    int strLeng=20;
    for(int indx=0;indx<n;indx++){
        for(int j=0;j<strLeng;j++){
            strArr[indx] += rand()%(z-a+1)+a;
        } //cout<<strArr[indx]<<endl;
    }
}
void prntAry(const string a[],int n,int perLine){
    for(int indx=0;indx<n;indx++){
        cout<<indx<<". "<<a[indx]<<"\n";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
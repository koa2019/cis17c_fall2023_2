/* 
 * File:   main.cpp
 * Author: Danielle and Dr. Mark E. Lehr
 * Purpose:  Using integer arrays
 * Common searching and sorting algorithms
 * Binary and Linear Timing and Operational Analysis
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> //microseconds 
using namespace std;
// this namespace is used to perform calculation
using namespace chrono; //https://www.geeksforgeeks.org/how-to-calculate-running-time-in-microseconds-in-cpp/

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
int ob,//operations before
    oeq,//equal sign
    olt,//less than
    oinc,//increment
    osub,//subtract
    oadd,//add
    odiv,//divide
    ogt,//greater than
    oi,//index
    count;
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
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void copyAry(int [],int [],int);
int  linSrch(int [],int, int);
int  binSrch(int [],int, int);
void selSort(int [],int);


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=100000;
    int array[SIZE],brray[SIZE];
    int lowRng=100,highRng=750;
    int perLine=10;
    int end=0,value=0,found=0,found2=0;
    
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    
    //Print the values in the array
    //prntAry(array,SIZE,perLine);
    // Sort the array the for all positions
    //selSort(array,SIZE);
    //cout<<"After Sorting"<<endl; prntAry(array,SIZE,perLine); 
    
    // Start timing and operational analysis here
    cout<<"Using the Linear Search"<<endl;  
    auto start1 = high_resolution_clock::now();//int beg=time(0);
    int nLoops=1;
    for(int i=0;i<nLoops;i++){
        
        //Test the linear search by randomly choosing a value and determine if found;
        value=rand()%(highRng-lowRng+1)+lowRng;        
     
        //Linear Seach
        found = linSrch(array,SIZE,value);
        
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
    cout<<"The value "<<value<<" was found at position "<<found<<endl;
    cout<<"nLoops: "<<nLoops<<endl;
    cout<<"N: "<<SIZE<<"\n";
    cout<<"Linear Search: "
        << (double)(duration.count() / 1000.0) << " microseconds\n";
    
    
    
    // Binary Timing analysis results
    cout<<endl<<endl<<endl<<"Using the Binary Search"<<endl;
    // Sort the array the for all positions
    selSort(brray,SIZE);
    //cout<<"After Sorting"<<endl;
    //prntAry(brray,SIZE,perLine);  
    
    start1 = high_resolution_clock::now();//int beg=time(0);
    for(int i=0;i<nLoops;i++){  
        //Binary Search
        found2 = binSrch(brray,SIZE,value);
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
    cout<<"The value "<<value<<" was found at position "<<found2<<endl;
    cout<<"nLoops: "<<nLoops<<endl;
    cout<<"N: "<<SIZE<<"\n";
    cout<<"Binary Search: "
        << (double)(duration.count() / 1000.0) << " microseconds\n";
        
    //Exit
    return 0;
}


int  binSrch(int a[],int n, int val){
    //Initialize end points which are indexes    
    int lowEnd=0;
    int highEnd=n-1;
    ob++;
    oeq+=2; osub++;
    
    //Loop until value found not indexes
    do{
        count++;
        int middle=(highEnd+lowEnd)/2;
        oeq++; oadd++; odiv++;
        if(val==a[middle]){
            oeq++;
            return middle;
        }
        else if(val>a[middle]){
            lowEnd=middle+1;
            oeq++; ogt++; oadd++; 
        }
        else {
            highEnd=middle-1;
            oeq++; osub++;
        }     
        oi++;
    }while(lowEnd<=highEnd);
    olt++;    
    //cout<<"lowEnd="<<lowEnd<<" hiEnd="<<highEnd;
    //cout<<" count = "<<count<<endl;    
    oeq++;
    return -1;//Not found
}

int  linSrch(int a[],int n, int val){
    ob1++;
    for(int indx=0;indx<n;indx++){
        oi1++; oeq1++; olt1++; oinc1++;
        if(val==a[indx]){oeq1++; ob1++; return indx; }    
    }
    ob1++;
    return -1;
}


void selSort(int a[],int n){
    //Loop and declare variables
    int indx,min;
    for(int pos=0;pos<n-1;pos++){       
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        //oeq+=2;
        for(int i=pos+1;i<n;i++){
            if(a[i]<min){
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
    }
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}
void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
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
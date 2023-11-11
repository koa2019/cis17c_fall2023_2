/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Common searching and sorting algorithms
 * Binary and Linear Timing and Operational Analysis'
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
int ob,//operations before
    oeq,//equal sign
    olt,//less than
    oinc,//increament
    osub,//subtract
    oadd,//add
    odiv,//divide
    ogt,//greater than
    oi,//index
    count;

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
int  linSrch(int [],int, int);
int  binSrch(int [],int, int);
void selSort(int [],int);
void copyAry(int [],int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    //srand(time(0));
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=12000;
    int array[SIZE],brray[SIZE];
    int lowRng=100,highRng=750;
    int perLine=10;
    int end=0,value=0,found=0;
    
    int beg=time(0);
    for(int i=0;i<SIZE;i++){
        
        //Finish initializing the rest of the array    
        fillAry(array,SIZE,highRng,lowRng);
        copyAry(brray,array,SIZE);
    
   
        //Print the values in the array
        //prntAry(array,SIZE,perLine);
        //prntAry(brray,SIZE,perLine);

        //Sort the array the for all positions
        //selSort(array,SIZE);
        selSort(brray,SIZE);

   
        
        //Test the linear search by randomly choosing a value and
        //determine if found;
        value=rand()%(highRng-lowRng+1)+lowRng;         
        
        //Binary Search
        found = binSrch(brray,SIZE,value);
        //cout<<"The value "<<value<<" was found at position "
           //<<binSrch(brray,SIZE,value);//<<endl;
        
        //Linear Seach
        //found = linSrch(array,SIZE,value);
        //cout<<"The value "<<value<<" was found at position "<<
        //linSrch(array,SIZE,value);//<<endl;
    }
    end=time(0);
    
    //cout<<"Using the Linear Search"<<endl<<endl;    
    //cout<<"Linear Search Takes T("<<SIZE<<")="<<end-beg<<" Seconds"<<endl;
    //cout<<"The value "<<value<<" was found at position "<<found<<endl;
    
    cout<<"Using the Binary Search"<<endl<<endl;
    cout<<"For N="<<SIZE<<" Binary Search Takes "<<end-beg<<" Seconds"<<endl;
    //cout<<"The value "<<value<<" was found at position "<<found<<endl;
    
//    cout<<"Before="<<ob<<endl
//        <<"Eq="<<oeq<<endl
//        <<"Lt="<<olt<<endl
//        <<"Inc="<<oinc<<endl
//        <<"Sub="<<osub<<endl
//        <<"Add="<<oadd<<endl
//        <<"Div="<<odiv<<endl
//        <<"Gt="<<ogt<<endl
//        <<"Indx="<<oi<<endl
//        <<"\tTotal="<<ob+oeq+olt+oinc+osub+oadd+odiv+ogt+oi<<endl<<endl;
//    
    //Print the values in the array
    //cout<<"After Sorting"<<endl;
    //prntAry(array,SIZE,perLine);
    //prntAry(brray,SIZE,perLine);
    
    
    //Exit
    return 0;
}


int  binSrch(int a[],int n, int val){
    //Initialize end points which are indexes    
    int lowEnd=0;
    int highEnd=n-1;
//    ob++;
//    oeq+=2; osub++;
    
    //Loop until value found not indexes
    do{
        //count++;
        int middle=(highEnd+lowEnd)/2;
        //oeq++; oadd++; odiv++;
        if(val==a[middle]){
            //oeq++;
            return middle;
        }
        else if(val>a[middle]){lowEnd=middle+1;}
        else {highEnd=middle-1;}     
        //oeq+=2; ogt++; oadd++; osub++; oi++;
    }while(lowEnd<=highEnd);
    //olt++;    
    //cout<<"lowEnd="<<lowEnd<<" hiEnd="<<highEnd;
    //cout<<" count = "<<count<<endl;
    //Not found
    return -1;
}

int  linSrch(int a[],int n, int val){
    //ob++;
    for(int indx=0;indx<n;indx++){
        //oi++; oeq++; olt++; oinc++;
        if(val==a[indx]){return indx; oeq++; ob++;}    
    }
    //ob++;
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


void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
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
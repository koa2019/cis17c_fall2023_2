/* File:   main.cpp
 * Author: Danielle
 * Created: 12-13-23
 * Purpose: cis17c final problem 4 sort mergeP vs selectionP v1
 * 
 * Based off Lehr's Merge v4 sort that creates a Recursive sort and
 * applies the merge recursively to sort the array
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <climits> //shrt_max
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
short  *fill(int);
void print(short *,int,int);
void merge(short *,int,int,int);
void mrgSort(short *,int,int);
//int *combine(int *,int,int *,int);
//Function Prototypes Here
void prntAry(const short [],int,int);
void fillAry(short [],int,int,int);
void swap(int &,int &);
short *selSort(short [],int,int);
void copyAry(short [],short [],int);

short *mergeP(short *a,int beg,int end, int p){
    short *pArry = new short[p];
    mrgSort(a,beg,end);
    //cout<<"\n\tHit Mergep"<<endl;
    for(int i = 0; i < p; i++){
        //cout<<"A="<<a[i]<<" ";
        pArry[i]=a[i];
        //cout<<"P "<<pArry[i]<<" \n";
        
    }
    return pArry;
}
short *selSort(short a[],int n, int p){
    //Loop and declare variables
    int indx,min;
	short *arrp= new short[p];
    for(int pos=0;pos<p;pos++){
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            if(a[i]<min){
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
		arrp[pos]=min;//a[pos]
    }
        return arrp;
}
void fillAry(short a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}
void copyAry(short copyIt[],short source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void prntAry(const short a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
//Execution Begins Here
int main(int argc, char** argv) {

    // Using time point and system_clock
    std::chrono::time_point<std::chrono::system_clock> start1, end1;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    //Declare all Variables Here
    const int SIZE=100000;
    short array[SIZE],brray[SIZE];
    short lowRng=10000,highRng=SHRT_MAX;
    int perLine=10;
    int p=0;
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    
    //Print the values in the array
    //prntAry(array,SIZE,perLine);
    //prntAry(brray,SIZE,perLine);
    
    //Merge the arrays then print
    //cout<<"Merge\n";
    
    //mrgSort(array,0,SIZE);
    //print(array,SIZE,perLine);
    
    //**********************************************************
    //              Timing Analysis 
    //**********************************************************
    p=140; 
    cout<<"Selection P: ";    
    start1 = std::chrono::system_clock::now();//begin
    short *pArr = selSort(array,SIZE,p);    
    end1 = std::chrono::system_clock::now();//end
    chrono::duration<double> elapsed_seconds1 = end1 - start1;
    time_t end_time1 = std::chrono::system_clock::to_time_t(end1);
    cout<<endl<<"n = "<<SIZE<<endl
        <<"p = "<<p
        <<"\nTotal Run Time = "<<elapsed_seconds1.count()<<" Seconds\n\n";
     
    // prntAry(pArr,p,perLine);
    for(int i=0;i<p;i++){
        cout<<pArr[i]<<" ";
        if(i%10==9){cout<<endl;}
    }
    cout<<endl;
    //prntAry(array,SIZE,perLine);
    
    
    cout<<endl<<"Merge P: ";
    start = std::chrono::system_clock::now();
    short *pArr2 = mergeP(brray,0,SIZE,5);
    end = std::chrono::system_clock::now(); 
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            
    cout<<endl<<"n = "<<SIZE<<endl
        <<"p = "<<p
        <<"\nTotal Run Time = "<<elapsed_seconds.count()<<" Seconds\n\n";

    cout<<endl<<"Merge sorted Top p = "<<p<<endl;
    for(int i=0;i<p;i++){
        cout<<brray[i]<<" ";
        if(i%10==9){cout<<endl;}
    }
    //prntAry(brray,SIZE,perLine);

    return 0;
}


void mrgSort(short *a,int beg,int end){
    int center=(beg+end)/2;
    if((center-beg)>1)mrgSort(a,beg,center);
    if((end-center)>1)mrgSort(a,center,end);
    merge(a,beg,center,end);
}

void merge(short *hilow,int beg,int nlow,int nhigh){
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge
    int *c=new int[span];  //Allocate Memory
    //Fill the array
    for(int i=0;i<span;i++){
        if(cntl==nlow){
            c[i]=hilow[cnth++];
        }else if(cnth==nhigh){
            c[i]=hilow[cntl++];
        }else if(hilow[cntl]<hilow[cnth]){
            c[i]=hilow[cntl++];
        }else{
            c[i]=hilow[cnth++];
        }
    }
    //Copy back and deallocate memory
    for(int i=0;i<span;i++){
        hilow[beg+i]=c[i];
    }
    delete []c;
}

int *combine(short *a,int na,int *b,int nb){
    //Allocate memory
    int *ab=new int[na+nb];
    //First a
    for(int i=0;i<na;i++){
        ab[i]=a[i];
    }
    //Then b
    for(int i=na;i<na+nb;i++){
        ab[i]=b[i-na];
    }
    //Return the combination
    return ab;
}

void print(short *a,int n,int perLine){
    //First print the unsorted array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//int *fill(int n){
//    //Allocate memory
//    int *a=new int[n];
//    for(int i=0;i<n;i++){
//        a[i]=i;
//    }
//    return a;
//}
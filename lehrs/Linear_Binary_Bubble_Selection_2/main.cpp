/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Common searching and sorting algorithms
 * Bubble and Select Sort Timing and Operational Analysis
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
int oeq,//equal sign
    olt,//less than
    oinc,//increament
    osub,//subtract
    oadd,//add
    ogt,//greater than
    oi;//index

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [], int, int, int);
void copyAry(int [], int [], int);
//void swap(int &,int &);
//void smlLst(int [],int,int);
//void mrkSort(int [],int);
void bublSrt(int [],int);
void selSort(int [],int);

//Program Execution Begins Here

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int> (time(0)));

    //Declare all Variables Here
    const int SIZE = 800;
    int array[SIZE], brray[SIZE];
    int lowRng = 100, highRng = 200;
    int perLine = 10;
    int end = 0, value = 0, nOp = 0;

    int beg = time(0);

    //Finish initializing the rest of the array    
    fillAry(array, SIZE, highRng, lowRng);
    copyAry(brray,array,SIZE);


    //Print the values in the array
    //prntAry(array,SIZE,perLine);
    //prntAry(brray,SIZE,perLine);

    //Sort the array the for all positions
    //mrkSort(array,SIZE);
    //bublSrt(array, SIZE);
    selSort(brray,SIZE);

    end = time(0);
    //cout<<"Bubble Sort T("   h<<SIZE<<") = "<<end-beg<<" Seconds"<<endl;
    cout<<"Selection Sort T("<<SIZE<<") = "<<end-beg<<" Seconds"<<endl;
     
    //Print the values in the array
    //cout<<"After Sorting"<<endl;
    //prntAry(array, SIZE, perLine);
    //prntAry(brray,SIZE,perLine);
    //prntAry(array,size,perLine);
    cout<<"Eq="<<oeq<<endl
        <<"Lt="<<olt<<endl
        <<"Inc="<<oinc<<endl
        <<"Sub="<<osub<<endl
        <<"Add="<<oadd<<endl
        <<"Gt="<<ogt<<endl
        <<"Indx="<<oi<<endl
        <<"Total="<<oeq+olt+oinc+osub+oadd+ogt+oi<<endl;
    
    //Exit
    return 0;
}

void copyAry(int copyIt[], int source[], int n) {
    for (int i = 0; i < n; i++) {
        copyIt[i] = source[i];
    }
}

void selSort(int a[],int n){
    //Loop and declare variables
    int indx,min;
    for(int pos=0;pos<n-1;pos++){
         oi++; oeq++; olt++; osub++; oinc++;
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        oeq+=2;
        for(int i=pos+1;i<n;i++){
            oi++; oeq++; olt++; osub++; oinc++;
            if(a[i]<min){
                min=a[i];
                indx=i;
                olt++; oeq+=2;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
        oeq+=2;
    }
}

void bublSrt(int a[],int n){
    //Keep looping and comparing until no swaps are left
    bool swap;
    do{
        swap=false;
        oeq++;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            oi++; oeq++; olt++; osub++; oinc++;
            if(a[i]>a[i+1]){
                ogt++; oadd++;
                int temp=a[i];               
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
                oeq+=4;
                oadd+=2;
            }
        }
        oi++;
    }while(swap);
}

void fillAry(int a[], int n, int hr, int lr) {
    for (int indx = 0; indx < n; indx++) {
        a[indx] = rand() % (hr - lr + 1) + lr;
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

//void mrkSort(int a[],int n){
//    for(int pos=0;pos<n-1;pos++){
//        smlLst(a,n,pos);
//    }
//}
//
//void smlLst(int a[],int n,int pos){
//    for(int i=pos+1;i<n;i++){
//        if(a[pos]>a[i]){
//            swap(a[pos],a[i]);
//        }
//    }
//}
//
//void swap(int &a,int &b){
//    int temp=a;
//    a=b;
//    b=temp;
//}


//int binSrch(int a[], int n, int val) {
//
//    //Initialize end points which are indexes
//    int ob = 1,
//            op = 0;
//    int lowEnd = 0;
//    int highEnd = n - 1;
//    ob += 3;
//
//    //Loop until value found not indexes
//    do {
//        int middle = (highEnd + lowEnd) / 2;
//        if (val == a[middle])return middle; //op=8
//        else if (val > a[middle])lowEnd = middle + 1; //op=5
//        else highEnd = middle - 1; //op=3       
//    } while (lowEnd <= highEnd);
//    op += (8 + 5 + 3);
//    //cout<<"\tbinSearch op = "<<ob+op<<endl;
//    //Not found
//    return op + ob; //-1;
//}

//int  linSrch(int a[],int n, int val){
//    for(int indx=0;indx<n;indx++){
//        if(val==a[indx])return indx;
//    }
//    return -1;
//}
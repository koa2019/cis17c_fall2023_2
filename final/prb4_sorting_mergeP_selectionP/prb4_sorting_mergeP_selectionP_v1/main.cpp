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
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
//int  *fill(int);
void print(int *,int,int);
void merge(int *,int,int,int);
void mrgSort(int *,int,int);
int *combine(int *,int,int *,int);
//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void swap(int &,int &);
int *selSort(int [],int,int);
void copyAry(int [],int [],int);

int *mergeP(int *a,int beg,int end, int p){
    int *pArry = new int[p];
    mrgSort(a,beg,end);
    //cout<<"\n\tHit Mergep"<<endl;
    for(int i = 0; i < p; i++){
        //cout<<"A="<<a[i]<<" ";
        pArry[i]=a[i];
        //cout<<"P "<<pArry[i]<<" \n";
        
    }
    return pArry;
}
int *selSort(int a[],int n, int p){
    //Loop and declare variables
    int indx,min;
	int *arrp= new int[p];
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
//Execution Begins Here
int main(int argc, char** argv) {
    //Allocate the arrays
//    int n=10;
//    int *a=fill(n);
//    int *b=fill(3*n);
//    int *ab=combine(a,n,b,3*n);
//    //Print the arrays
//   // print(a,n,perLine);
//   // print(b,3*n,perLine);
//    print(ab,4*n,perLine);
    
    //Declare all Variables Here
    const int SIZE=10;
    int array[SIZE],brray[SIZE];
    int lowRng=100,highRng=200;
    int perLine=10;
    int p=5;
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    
    //Print the values in the array
    //prntAry(array,SIZE,perLine);
    prntAry(brray,SIZE,perLine);
    
    //Merge the arrays then print
    //cout<<"Merge\n";
    
    //mrgSort(array,0,SIZE);
    //print(array,SIZE,perLine);
    
     cout<<"Select\n";
     //begin
     int *pArr = selSort(array,SIZE,p);
     //end
     //int size=sizeof(pArr)/sizeof(pArr[0]);
     //cout<<size<<endl;
     for(int i=0;i<p;i++){
         cout<<pArr[i]<<" ";
     }
     cout<<endl;
     prntAry(array,SIZE,perLine);
    
     cout<<"MergeP\n";
    int *pArr2 = mergeP(brray,0,SIZE,5);
    for(int i=0;i<p;i++){
         cout<<pArr2[i]<<" ";
     }
     cout<<endl<<"Merge sorted";
     prntAry(brray,SIZE,perLine);
    //Deallocate data
//    delete []a;
//    delete []b;
//    delete []ab;
    //Exit stage right
    return 0;
}


void mrgSort(int *a,int beg,int end){
    int center=(beg+end)/2;
    if((center-beg)>1)mrgSort(a,beg,center);
    if((end-center)>1)mrgSort(a,center,end);
    merge(a,beg,center,end);
}

void merge(int *hilow,int beg,int nlow,int nhigh){
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

int *combine(int *a,int na,int *b,int nb){
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

void print(int *a,int n,int perLine){
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
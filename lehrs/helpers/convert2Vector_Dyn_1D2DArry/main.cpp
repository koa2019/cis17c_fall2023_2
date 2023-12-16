/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 10-24-23 @9PM
 * Purpose:  convert to vectors - Compare 1 and 2 Dimensional Dynamic Arrays
 * Based off of cis17a>lab_nasaFormat_vectConver
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;


//Function Prototypes Here
void smlLst(vector<int>&,int);//checks for smallest
void mrkSort(vector<int>&);//Sort
void fillAry(int **,vector<int> &,int,int);//fills vector with 2D pointer
void fillVec(vector<int>&,int,int,int);//fills random
void prntVec(vector<int> &,int);//void prntAry(const int *,int,int);

void prntAry(int **,int,int);
int  **fillAry(int,int);
void destroy(int **,int);
void swap(int &,int &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays
    int colsize=3;//The column size for a 2 dimensional Array
    vector<int>avec(rowsize);//int *array;
    vector<int>bvec(rowsize);//int *brray;
    vector<int>cvec(rowsize);//int *crray;      
    int **table;
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    fillVec(avec,rowsize,highRng,lowRng);//array=fillAry(rowsize,highRng,lowRng);
    fillVec(bvec,rowsize,highRng,lowRng);//brray=fillAry(rowsize,highRng/10,lowRng/10);
    fillVec(cvec,rowsize,highRng,lowRng);//crray=fillAry(rowsize,highRng/100,lowRng/100);
        
    //Sort the array the for all positions
    mrkSort(avec);//mrkSort(array,rowsize);
    mrkSort(bvec);//mrkSort(brray,rowsize);
    mrkSort(cvec);//mrkSort(crray,rowsize);
    
    //Fill the 2-D array
    table=fillAry(rowsize,colsize);
    fillAry(table,avec,rowsize,0);
    fillAry(table,bvec,rowsize,1);
    fillAry(table,cvec,rowsize,2);
    
    //Print the values in the array
    cout<<"\navec";
    prntVec(avec,perLine);
    cout<<"bvec";
    prntVec(bvec,perLine);//prntAry(brray,rowsize,perLine);
    cout<<"cvec";
    prntVec(cvec,perLine);//prntAry(crray,rowsize,perLine);
    prntAry(table,rowsize,colsize);
    
    //Cleanup
    //delete []array;
    //delete []brray;
    //delete []crray;
    destroy(table,rowsize);

    //Exit
    return 0;
}

/******************************************************************************/
//                          VECTORS
/******************************************************************************/

// FILL VECTOR WITH 2D POINTER ARRAY VALUES
//void fillAry(int **a,int *c,        int rowSize,int wchCol){
void fillAry  (int **a,vector<int> &c,int rowSize,int wchCol){
    for(int row=0;row<rowSize;row++){
        a[row][wchCol]=c[row];
    }
}

//int *fillAry(int n,int hr,int lr){
void fillVec(vector<int> &a,int n,int hr,int lr){
    n=n<2?2:n;
    //int *a=new int[n];
    for(int indx=0;indx<a.size();indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }    
}

void prntVec(vector<int> &a,int perLine){
    //Print the values in the array
    cout<<endl<<"The Vector Values"<<endl;
    for(int indx=0;indx<a.size();indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//void mrkSort(int a[],int n){
void mrkSort(vector<int> &a){
    for(int pos=0;pos<a.size()-1;pos++){
        smlLst(a,pos);
    }
}

//void smlLst(int a[],int n,int pos){
void smlLst(vector<int> &a,int pos){
    for(int i=pos+1;i<a.size();i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

/******************************************************************************/
//                          2D POINTER ARRAY
/******************************************************************************/

int **fillAry(int rows,int cols){
    //Allocate Memory for 2-D Array
    rows=rows<2?2:rows;
    cols=cols<2?2:cols;
    int **a=new int*[rows];
    for(int row=0;row<rows;row++){
        a[row]=new int[cols];
    }
    //Fill it with 0's
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            a[row][col]=0;
        }
    }
    return a;
}

void prntAry(int **a,int rowsize,int colsize){
     cout<<endl<<"The Array Values"<<endl;
    for(int row=0;row<rowsize;row++){
        for(int col=0;col<colsize;col++){
            cout<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}

void destroy(int **a,int rows){
    for(int row=0;row<rows;row++){
        delete []a[row];
    }
    delete []a;
}
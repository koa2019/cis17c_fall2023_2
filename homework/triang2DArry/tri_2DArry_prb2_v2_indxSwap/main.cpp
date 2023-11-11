/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 23rd, 2020, 12:15 pM
 * Purpose:  Triangular array
 *           Complete the fillAry & prntAry function
 *           int **fillAry(int *,int);
 *           void  prntAry(int **,int *,int *,int)
 * 
 * v2: Prints the sorted index and col[indx[i] arrays.
 *     See mrkSort() and prntAry(int *col,int *indx, int size)
 */

//System Libraries Here
#include <iostream>  //I/O Library
#include <string>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  mrkRand(int=1<<15-1);     //PSRNG repeating the same sequence
int *fillAry(int);             //Randomly fill a 1-D column array
void prntAry(int *,int);       //Print a 1-D array
void prntAry(string,int *,int);       //Print a 1-D array
void prntAry(int *,int *, int);       //Prints a 1-D array using a sorted 1D array
void destroy(int **,int *,int *,int);//Deallocate memory
int *fillIdx(int);
void mrkSort(int *,int *,int); //Use a database sort
//Complete the following Function
int**fillAry(int *,int);       //Randomly fill a triangular array
void prntAry(int **,int *,int *,int);//Print a triangular array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int *col;      //Pointer to column array
    int *indx;     //Index Array to the Sort Routine
    int **trangl;  //Pointer to triangular array
    int rowSize;   //Number of Rows in the Array
    
    //Input or initialize values Here
    cout<<"Input the Number of Rows in the Array"<<endl;
    //cin>>rowSize;
    rowSize=10;
    indx=fillIdx(rowSize);      //Index used for Database Sort
    col=fillAry(rowSize);       //Dynamic 1-D array,#Columns in each row
    trangl=fillAry(col,rowSize);//Dynamic triangular array
    
    //Output Located Here
    cout<<"The Column Array Size"<<endl;
    prntAry(col,rowSize);
    cout<<"The Triangular Array Sorted"<<endl;
    mrkSort(col,indx,rowSize);//Sort the columns with an index. SORTS INDX ARRAY.
    cout<<"\nAfter mrkSort\n";
    prntAry("  col",col,rowSize);    // unsorted col array
    prntAry("sIndx",indx,rowSize); // sorted indx array
    prntAry(col,indx,rowSize);     // col array using sorted indx[] to set col sizes
    prntAry(trangl,col,indx,rowSize);//Display the Matrix with Columns sorted

    //Deallocate the array
    destroy(trangl,col,indx,rowSize);
    
    //Exit
    return 0;
}

//Modify this Function for unequal number of columns per row
//Input rows  -> Number of rows
//      col   -> Column array size n with number of columns in each row
//Output
//      array -> 2D Triangular Array/Matrix
int **fillAry(int *col,int rows){
    int **array=new int*[rows];
    for(int i=0;i<rows;i++){
        array[i]=new int[rows];
    }
    
    // change column sizes here
    int a[]={1,2,2,3,4,5,6,7,8,9};
    for(int i=0;i<rows;i++){
        for(int j=0;j<a[i];j++){
            array[i][j]=mrkRand()%9+1;//1 Digit numbers [1-9]
        }
    }
    return array;
}

//Modify this Function for unequal number of columns per row
//Input n     -> Number of rows
//      col   -> Column array size n with number of columns in each row
//      array -> 2D Triangular Array/Matrix
void prntAry(int **array,int *col,int *indx,int rows){
    
    int a[]={1,2,2,3,4,5,6,7,8,9};
    for(int i=0;i<rows;i++){
        for(int j=0;j<a[i];j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// sorts col 1D array. Sorts ascending order. small to big.
void mrkSort(int *col,int *indx,int size){
    
    cout<<"\n"; prntAry("indx",indx,size); prntAry("col ",col,size);cout<<endl;
    
    for(int pos=0;pos<size-1;pos++){
        for(int lst=pos+1;lst<size;lst++){ // (0,1),(0,2),(0,3)...(0,size)
            if(col[indx[pos]]>col[indx[lst]]){
                
                cout<<col[indx[pos]]<<">"<<col[indx[lst]]<<" swap ";
                cout<<indx[pos]<< "&"<<indx[lst]<<"\n";
                
                // swap
                indx[pos]=indx[pos]^indx[lst]; //
                indx[lst]=indx[pos]^indx[lst];
                indx[pos]=indx[pos]^indx[lst];
                prntAry("indx",indx,size);
                prntAry(col,indx,size);
            }
        }
        cout<<endl;
    }
}

void destroy(int **a,int *c,int *indx,int n){
    //Delete every row of the triangular array
    for(int i=0;i<n;i++){
        delete a[i];
    }
    //Delete the pointers
    delete []a;
    delete []c;
    delete []indx;
}

void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
}

// i made this function
void prntAry(string name, int *a,int n){
    cout<<name<<"[] = ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
// i made this function
void prntAry(int *col, int *indx, int n){
    cout<<"sCol [] = ";
    for(int i=0;i<n;i++){
        cout<<col[indx[i]]<<" ";
    }
    cout<<endl<<endl;
}

// Fills col 1D array with lehr's random sequence
int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=mrkRand()%9+1;//1 Digit numbers [1-9]
        //cout<<array[i]<<"  ";
    }
    //cout<<endl;
    return array;
}

int *fillIdx(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=i;
    }
    return array;
}

int mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}
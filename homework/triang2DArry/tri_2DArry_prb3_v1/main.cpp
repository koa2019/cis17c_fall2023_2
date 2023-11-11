/* 
 * File:   main.cpp
 * Author: Danielle F
 * Created: 9-3-23
 * Purpose:  Triangular array
 *           Complete the functions with the defined structure
 
 Instructions:
 Complete the code.  There are 3 functions that need to be modified to output the desired result.  
 Fill the columns first with random 1 digit values, then fill the data array with random 1 digit values.

//Create this function
TriMatx *fillMat(int rows){
    TriMatx *triMt=new TriMatx;
    triMt->size=0;
    triMt->col=0;
    triMt->indx=0;
    triMt->data=0;
    return triMt;}

//Create these functions
void prntAry(TriMatx *triMt){}
void mrkSort(TriMatx *triMt){}

Clues:   
 
input: 10
Expected Output:
Input·the·Number·of·Rows·in·the·Array↵
The·Column·Array·Size↵
3·4·1·8·2·6·2·5·7·9·↵
↵
The·Triangular·Array·Sorted↵
9·↵
3·2·↵
9·3·↵
9·4·3·↵
9·8·2·3·↵
7·1·4·4·9·↵
3·9·2·4·5·4·↵
3·5·8·3·8·6·7·↵
9·4·1·5·4·7·9·7·↵
5·5·6·2·4·7·6·6·1·↵
↵
↵
 */

//System Libraries Here
#include <iostream>  //I/O Library
using namespace std;

//User Libraries Here
struct TriMatx{
     int size;  //Represents the number of rows
     int *col;  //Represents the column array, i.e. number of columns for each row
     int *indx; //Represents the index matrix which you can sort to use for display
     int **data;//Represents the data contents of the Triangular matrix
};

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  mrkRand(int=1<<15-1);     //PSRNG repeating the same sequence
void prntAry(int *,int);       //Print a 1-D array
void destroy(TriMatx *);       //Deallocate memory
//Complete the following Function
TriMatx *fillMat(int);  //Randomly fill a triangular structure
void mrkSort(TriMatx *);//Use a database sort
void prntAry(TriMatx *);//Print a triangular array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int rowSize;   //Number of Rows in the Array
    TriMatx *triMt;//Triangular Matrix Structure
    
    //Input or initialize values Here
    cout<<"Input the Number of Rows in the Array"<<endl;
    cin>>rowSize;
    triMt=fillMat(rowSize);//Dynamic triangular array

    //Output Located Here
    cout<<"The Column Array Size"<<endl;
    prntAry(triMt->col,triMt->size);
    cout<<"The Triangular Array Sorted"<<endl;
    mrkSort(triMt);//Sort the columns with an index
    prntAry(triMt);//Display the Matrix with Columns sorted

    //Deallocate the structure
    destroy(triMt);
    
    //Exit
    return 0;
}

//Create this function
TriMatx *fillMat(int rows){
    TriMatx *triMt=new TriMatx;
    triMt->size=0;
    triMt->col=0;
    triMt->indx=0;
    triMt->data=0;
    return triMt;
}

//Create this function
void prntAry(TriMatx *triMt){
 
}

//Create this function
void mrkSort(TriMatx *triMt){
 
}

void destroy(TriMatx *triMt){
    //Delete every row of the triangular array
    for(int i=0;i<triMt->size;i++){
        delete []triMt->data[i];
    }
    //Delete the pointers
    delete []triMt->data;
    delete []triMt->col;
    delete []triMt->indx;
    delete triMt;
}

void prntAry(int *a,int n){
    if(a==0)return;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
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
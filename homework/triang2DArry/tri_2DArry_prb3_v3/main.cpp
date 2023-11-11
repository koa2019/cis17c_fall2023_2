/* 
 * File:   main.cpp
 * Author: Danielle F
 * Created: 9-3-23
 * Purpose:  Triangular array v3
 *           Complete the functions with the defined structure
 
 * v3:
 * wrote code for void mrkSort(TriMatx *) and rewrote void prntAry(TriMatx *).
   
    
 * Clues:   
 * Ref to fill *col & *indx:
 * https://github.com/ml1150258/CSC_CIS_17C/blob/master/Class/MarkQuerySort_Structure/main.cpp
 * Ref how to fill **data:
 * https://github.com/ml1150258/CSC_CIS_17a/blob/master/Class/Structure_of_2D_Dynamic_Array/main.cpp

 * Ref for later when struct is an array:
 * https://github.com/ml1150258/CSC_CIS_17C/blob/master/Class/ObjectsWithConstructor/main.cpp
 * https://github.com/ml1150258/CSC_CIS_17a/blob/master/Class/MarkSort_Database_Index_Sort_Structure_V2/main.cpp
 */

//System Libraries Here
#include <bits/stdc++.h>
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
void prntAry(int *,int*,int);    
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
    prntAry(triMt->col,triMt->size); //(*col,size)
    cout<<"The Triangular Array Sorted"<<endl;
    mrkSort(triMt);//Sort the columns with an index
    prntAry(triMt);//Display the Matrix with Columns sorted

    //Deallocate the structure
    destroy(triMt);
    
    //Exit
    return 0;
}


//Randomly fill a triangular structure
//Ref to fill *col & *indx

TriMatx *fillMat(int rows){
    
    TriMatx *triMt=new TriMatx;
    triMt->size=rows;           //Number of rows
    triMt->col=new int[rows];   //1D column array,# of columns for each row
    triMt->indx=new int[rows];  //1D index matrix which you can sort to use for display
    int **a2D = new int*[rows]; //create 2D array, so I can point the structure to it
    
    for(int i=0;i<rows;i++){  // initialize 1D arrays
        triMt->col[i]=mrkRand()%9+1;//1 Digit numbers [1-9]
        triMt->indx[i]=i;
        a2D[i]=new int[triMt->col[i]];//Set # of cols for each row
    }
    
    for(int i=0;i<rows;i++){ //initialize 2D array
         for(int j=0;j<triMt->col[i]; j++){
            a2D[i][j] = mrkRand()%9+1;//1 Digit numbers [1-9]
        }   
    }
    
    triMt->data=a2D; //Set 2D array for data contents of the Triangular matrix.
    return triMt;
}

//Prints **data and sorts its rows using indx[i] values
void prntAry(TriMatx *triMt){
    for(int i=0;i<triMt->size;i++){
        //cout<<triMt->col[triMt->indx[i]]<<" = "; //Num cols in each row
        for(int j=0;j<triMt->col[triMt->indx[i]]; j++){
            cout<<triMt->data[triMt->indx[i]][j]<<" ";//sorts 2D array using indx[]
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}


//Sort the columns with an index. Only sorts indx[]
void mrkSort(TriMatx *triMt){
   for(int left=0;left<triMt->size-1;left++){//Works on each position in the list
        for(int right=left+1;right<triMt->size;right++){//Compare and swap with lower elements in the list
        
            if( triMt->col[triMt->indx[left]] > triMt->col[triMt->indx[right]]){//Swap
            
                //cout<<triMt->col[triMt->indx[left]] << ">"<< triMt->col[triMt->indx[right]]
                    //<<" swap ["<<triMt->indx[left]<<"]&["<<triMt->indx[right]<<"]\n";
                triMt->indx[left]=triMt->indx[left]^triMt->indx[right];
                triMt->indx[right]  =triMt->indx[left]^triMt->indx[right];
                triMt->indx[left]=triMt->indx[left]^triMt->indx[right];
                //prntAry(triMt->indx, triMt->size);
                //prntAry(triMt->indx,triMt->col, triMt->size);
            }
        }
    }
}

void destroy(TriMatx *triMt){
    //Delete every row of the triangular array
    for(int i=0;i<triMt->size;i++){
        delete []triMt->data[i];// Destroys **data rows
    }
    //Delete the pointers
    delete []triMt->data;
    delete []triMt->col;
    delete []triMt->indx;
    delete triMt;
}

void prntAry(int *col,int n){
    if(col==0)return;
    //cout<<"size = "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<col[i]<<" ";
    }
    cout<<endl<<endl;
}
void prntAry(int *indx, int *col,int n){
    if(col==0)return;
    //cout<<"size = "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<col[indx[i]]<<" ";
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
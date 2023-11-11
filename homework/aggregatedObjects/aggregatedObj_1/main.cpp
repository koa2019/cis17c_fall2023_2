/* File:   main.cpp
 * Author: Danielle F
 * Created: 9-13-23 @4PM
 * Purpose:  Dynamic Object Arrays
 
 * Utilizes an array of Row Objects to create a 2-D Matrix with different #'s of Columns
 * 
 * This assignment requires you to use aggregates without the benefit of setter 
 * functions, just constructors.  
 * There are examples covered in class and the zoom video.  
 * Double pointers are utilized to create a single dimension array of row objects.  
 * Each with a potentially different number of columns.  
 * There will be 2 more extensions of this exercise.
 
 * You are to complete in code where it says  //Student to complete
 * 
 * Input: 4 6
 * Output: See expected output.png
 */

//User Libraries
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//User Libraries
class RowAray{
    private:
        int size;
        int *rowData;
        int mrkRand(int);
    public:
        RowAray(int);   //Student to Complete
        ~RowAray();     //Student to Complete
        int getSize(){return size;}
        int getData(int i){return rowData[i];}
};

int RowAray::mrkRand(int seed){
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

//Student to complete
RowAray::RowAray(int n){
    size=n; // size is number of columns
    rowData=new int[size];  // each row has 6 cols in it
    for(int i=0;i<size;i++){
        rowData[i]=mrkRand(size)%90+10;
        //cout<<"row"<<i<<" = "<<rowData[i]<<endl;
    }
}

//Student to complete
RowAray::~RowAray(){
  delete []rowData;
}


class Table{
    private:
        int szRow;
        int szCol;
        RowAray **records;
    public:
        Table(int,int);  //Student to Complete
        ~Table();        //Student to Complete
        int getSzRow(){return szRow;}
        int getSzCol(){return szCol;}
        int getData(int,int); //Student to Complete
};

//Student to complete
// Lehr's reference https://github.com/ml1150258/CSC_CIS_17C/blob/master/Class/RandomDynamic2DArray/main.cpp
//https://github.com/ml1150258/CSC_CIS_17C/blob/master/Class/MovieDataStructureStepByStepSolution/Last_10_Structure_In_A_Structure/main.cpp
//https://github.com/ml1150258/CSC_CIS_17C/blob/master/Class/PlayCardsClass/CardDeck_V6/Deck.h
Table::Table(int rows,int cols){
    
    szRow=rows;
    szCol=cols;
    
    //Allocate a row of pointers
    records = new RowAray*[rows];  
    
    //Each row aggregates RowAray class to create an array with its size equal to cols
    for(int row=0;row<rows;row++){
        records[row] = new RowAray(cols);
    }
}

//Student to complete
Table::~Table(){
    for(int row=0;row<szRow;row++){
        delete records[row];
    }
    delete [] records;
}

//Student to complete
int Table::getData(int row,int col){
    //return (**(records+row)).getData(col);
    return records[row]->getData(col);
}

class Triangle{
    private:
        int szRow;
        RowAray **records;
    public:
        Triangle(int);  //Student to Complete
        ~Triangle();    //Student to Complete
        int getSzRow(){return szRow;}
        int getData(int,int);  //Student to Complete
};

//Student to complete
Triangle::Triangle(int rows){
    
     szRow=rows;
    
    //Allocate a row of pointers
    records = new RowAray*[rows];  
    
    //Each row aggregates RowAray class to create an array with its size equal to cols
    for(int row=0;row<rows;row++){
        records[row] = new RowAray(row+1); //(rows+1); //Add an extra column to compensate for prntTri()
    }
    
    //Print to see what's being saved to this 2D array
    // for(int row=0;row<rows;row++){
    //     for(int col=0;col<rows+1;col++){
    //         cout<<"["<<row<<","<<col<<"]="<<records[row]->getData(col)<<"   ";
    //     } cout<<endl;
    // } cout<<endl;
}

Triangle::~Triangle(){
    for(int row=0;row<szRow;row++){
        delete records[row];
    }
    delete [] records;
}

int Triangle::getData(int row,int col){
    return records[row]->getData(col);
    //return (**(records+row)).getData(col);
}

//Global Constants

//Function Prototype
void prntRow(RowAray *,int);
void prntTab(Table *);
void prntTri(Triangle *);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows,cols,perLine;
   
   //Read in Rows and Cols
   cout<<"Input Rows and Cols"<<endl;
   cin>>rows>>cols;
   perLine=cols/2;
   
   //Test out the RowAray
   RowAray row(cols);
    
   //Print the RowAray
   cout<<"The Row Array size = "<<row.getSize()
           <<" printed "<<perLine<<" per Line";

   prntRow(&row,perLine);
   
   //Test out the Table
   Table tab(rows,cols);
   
   //Print the Table
   cout<<"The table size is [row,col] = ["<<rows<<","<<cols<<"]";
   prntTab(&tab);
   cout<<endl;
   
   //Test out the Triangular Table
   Triangle tri(rows);
   
   //Print the Triangular Table
   cout<<"The triangular table size is [row,row] = ["<<rows<<","<<rows<<"]";
   prntTri(&tri);

   //Exit Stage Right
   return 0;
}

void prntRow(RowAray *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntTab(Table *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getSzCol();col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
}

void prntTri(Triangle *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<=row;col++){ //PRINTS <=ROW INSTEAD OF <ROW. Gives you +1 col on every iteration but WHY?
            //cout<<row<<"-"<<col<<"  "<<col+1+row<<endl;
            cout<<a->getData(row,col)<<" ";//[0,0] [1,0] [1,1] [2,0] [2,1] [2,2] [3,0] [3,1] [3,2] [3,3]
        }
        cout<<endl;
    }
    cout<<endl;
}
/* File:    main.cpp
 * Author:  Danielle F
 * Created: 09-26-2023 @ 5 PM
 * Purpose:  Template aggregates
 * 
 * Build a Template table from a row template.
 * Complete the code for the 2 classes, RowAray and Table Template
 * 
 * Input: 3 5
 * Output: see expectedOutput.png
 */

//User Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
template<class T> 
class RowAray{   // Complete the code for this class
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int);
        virtual ~RowAray();
        int mrkRand(int);
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};

template<class T>
int RowAray<T>::mrkRand(int seed){
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

template<class T>
RowAray<T>::RowAray(int n){
    size=n;
    rowData=new T[size];
    for(int i=0;i<size;i++){
        rowData[i]=mrkRand(size)%90+10; //fills array with int or floats
    }
}

template<class T>
RowAray<T>::~RowAray(){
    delete []rowData;
}

template<class T>
void RowAray<T>::setData(int row,T val){
    if(row>=0&&row<size)rowData[row]=val;
    else rowData[row]=0;
}

template<class T>
class Table{      // Complete the code for this class
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns; //Aggregates template Class RowAray 
    public:
        Table(unsigned int,unsigned int); //Default constructor
        Table(const Table<T> &);          //Copy Constructor
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template<class T> // Default constructor
Table<T>::Table(unsigned int rows,unsigned int cols){
    //Student to correct/complete
    szRow=1;
    szCol=1;
    columns=new RowAray<T>*[1];
    columns[0]=new RowAray<T>(1);
}

template<class T> //Copy Constructor
Table<T>::Table(const Table &a){
    //Student to correct/complete
    szRow=1;
    szCol=1;
    columns=new RowAray<T>*[1];
    columns[0]=new RowAray<T>(1);
}

template<class T>
Table<T>::~Table(){
    //Student to correct/complete
}

template<class T>
T Table<T>::getData(int row,int col)const{
    //Student to correct/complete
    return 0;
}

template<class T>
void Table<T>::setData(int row,int col,T val){
    //Student to correct/complete
    szRow=1;
    szCol=1;
    columns=new RowAray<T>*[1];
    columns[0]=new RowAray<T>(1);
}

template<class T>
Table<T> Table<T>::operator+(const Table<T> &a){
    //Student to correct/complete
    szRow=1;
    szCol=1;
    columns=new RowAray<T>*[1];
    columns[0]=new RowAray<T>(1);
}

//Global Constants

//Function Prototype
template<class T>
void prntRow(T *,int); // Prints a row
template<class T>
void prntTab(const Table<T> &);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows,cols;
   
   //Input the rows and the cols
   cout<<"Input the Rows and Columns for the Row and Table Arrays"<<endl;
   cin>>rows>>cols;
   
   //Test out the Row with integers and floats
   RowAray<int> a(rows); RowAray<float> b(cols);
   cout<<"Test the Integer Row with Rows"<<endl;
   prntRow(&a,rows); // Prints a row
   cout<<"Test the Float Row with Columns"<<endl;
   prntRow(&b,cols);  // Prints a row
   
   //Test out the Table with a float
   Table<float> tab1(rows,cols); //Calls Default constructor
   Table<float> tab2(tab1);     //Calls Copy constructor
   Table<float> tab3=tab1+tab2; //Uses Table's overloaded operator+()
   
   cout<<"Float Table 3 size is [row,col] = Table 1 + Table 2 ["
           <<rows<<","<<cols<<"]";
   cout<<endl<<"Table 1"<<endl;
   prntTab(tab1);
   cout<<"Table 2 copy of Table 1"<<endl;
   prntTab(tab2);
   cout<<"Table 3 addition of Table 1 and Table 2"<<endl;
   prntTab(tab3);
   
   //Exit Stage Right
   return 0;
}

template<class T>
void prntRow(T *a,int perLine){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int i=0;i<a->getSize();i++){ //Calls class RowAray function
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

template<class T>
void prntTab(const Table<T> &a){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int row=0;row<a.getSzRow();row++){
        for(int col=0;col<a.getSzCol();col++){
            cout<<setw(8)<<a.getData(row,col);
        }
        cout<<endl;
    }
    cout<<endl;
}
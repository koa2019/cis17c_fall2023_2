/* Author: Danielle
 * Created: 9-20-23 @4:55pm
 * Purpose:  Abstraction, Operator Overloading, 
 *           Copy Construction and Polymorphism
 * 
 * v1: defines and implements tab1 and tab2.
 
 * Input: 3 4
 * Output: see expectedOutput.png
           tab1 creates 2D array
           tab2 copies tab1
           tab3 adds tab1+tab2 with overloaded operator+()
 */

//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//******************************************************************************
//        Defines a 1D array BUT doesn't allocate any memory for it.
//******************************************************************************

class AbsRow{
    protected:
        int size;
        int *rowData;
    public:
        virtual int getSize()const = 0;   //NOTICE = 0
        virtual int getData(int)const = 0;//NOTICE = 0
};

//******************************************************************************
//              RowAray inherits AbsRow
//              RowAray->AbsRow
//      Allocates memory and initializes a 1D array using AbsRow    
//******************************************************************************

class RowAray:public AbsRow{
    public:
        RowAray(unsigned int);//Default constructor 
        virtual ~RowAray();   //Virtual destructor
        int mrkRand(int);
        int getSize()const{return size;}
        int getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,int);//(row,val)
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

//Default constructor 
//Allocates memory for 1D array
RowAray::RowAray(unsigned int n){
    size=n;
    rowData=new int[size];
    for(int i=0;i<size;i++){
        rowData[i]=mrkRand(size)%90+10;
    }
}

//Virtual destructor. 
//Destroys 1D array
RowAray::~RowAray(){
    delete []rowData;
    //rowData=nullptr;
}

// Sets inherited *rowData by 
// Directly accessing AbsRow Class's 1D pointer *rowData
void RowAray::setData(int row,int val){
    if(row>=0&&row<size)rowData[row]=val;
    else rowData[row]=0;
}


//******************************************************************************
//              AbsTab1 inherits RowAray->AbsRow
//               AbsTab1->RowAray->AbsRow
//              Defines a 2D pointer array
//******************************************************************************

class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual int getData(int,int)const = 0;
};

//******************************************************************************
//              Table inherits AbsTab1->RowAray->AbsRow
//              Table->AbsTab1->RowAray->AbsRow
//              Allocate & initialize a 2D pointer array
//******************************************************************************
class Table:public AbsTabl{
    public:
        Table(unsigned int,unsigned int);//Default constructor
        Table(const Table &);           //Copy constructor
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        int getData(int,int)const;//(row,col)
        void setData(int,int,int);//(row,col,val)
};

// Default constructor calls RowAray's default constructor 
// NOTICE: columns & rows instead of rows & cols
Table::Table(unsigned int rows,unsigned int cols){
    szRow=rows;//3
    szCol=cols;//4
    columns=new RowAray*[cols]; //Allocating memory for array of col pointers
    for(int col=0;col<cols;col++){
        columns[col]=new RowAray(rows);//Allocating memory for array of row pointers
    }
    
     
    // This is how Table constructor loops when initializing **columns
    // cout<<"\nIN Table construct\n";
    // for(int c=0;c<szCol;c++){
    //     //<<"col="<<c<<" ";
    //     for(int r=0;r<szRow;r++){
    //         //cout<<"\nIN Table construct columns["<<c<<"]->getDataRow("<<r<<")= "<<columns[c]->getData(r); 
    //         //cout<<"row="<<r<<" = ";
    //         cout<<columns[c]->getData(r)<< " ";
    //     } cout<<endl;
    // } cout<<endl;
}

// Student to supply
// Copy Constructor. 
// In main() PlusTab tab2() calls it & szCol=4 szRow=3
// PlusTab tab3 calls it & szCol=0 szRow=0
Table::Table(const Table &oldTab){ //accepts **columns     
    
    //cout<<"\n IN Table copy constructor  szCol="<<oldTab.getSzCol();
    //cout<<"\n IN Table copy constructor  szRow="<<oldTab.getSzRow()<<endl;
    
    // Copy col and row sizes to new object
    szCol=oldTab.getSzCol();
    szRow=oldTab.getSzRow();
    
    // Allocate memory for new 2D object with values from oldTable
    columns = new RowAray*[oldTab.getSzCol()];
    for(int c=0; c < oldTab.getSzCol(); c++){
        columns[c]=new RowAray(oldTab.getSzRow());
    }
    
    // Copy oldTab elements to new Table object   
    // This is how Table constructor loops cols & rows when it creates **columns
    //cout<<"\nIN Table COPY Construct\n";
    for(int c=0;c<szCol;c++){
        // Notice how this prints ONLY the top col+row
        //cout<<"\ncol["<<c<<"] row[0]= ";
        //cout<<oldTab.columns[c]->getData(0)<<" "; 
        for(int r=0;r<szRow;r++){
            
            // Calls Tables setData()
            setData(r,c, oldTab.columns[c]->getData(r));
            //cout<<columns[c]->getData(r)<< " ";
            //cout<<"\noldTab.columns["<<c<<"]->getDataRow("<<r<<")= "<<oldTab.columns[c]->getData(r); 
            //cout<<oldTab.columns[c]->getData(r)<< " ";            
        }
        //cout<<endl;
    } 
    //cout<<endl;    
     
    
    // This is how prntTab() loops. rows & cols
    //cout<<"\nIN Table COPY Construct\n";
    //for(int r=0;r<szRow;r++){
        //cout<<"row="<<r<<" ";
        //for(int c=0; c < szCol; c++){       
        //cout<<"\noldTab.columns["<<c<<"]->getData("<<r<<")= "<<oldTab.columns[c]->getData(r);       
        //cout<<"col="<<c<<" = ";
        //cout<<oldTab.columns[c]->getData(r)<< " ";
        //} cout<<endl;
    //}
    
}

//Destructor
//Student to supply
Table::~Table(){  
    //cout<<szCol<<endl;
    //for(int c=0;c<szCol;c++){
        //delete [] columns[c];
    //}
   // delete [] columns;
}

// Student to supply
// In prntTab()...tab1->getData(row,col)
// NOTICE: Table constructor allocates 2D columns & then rows instead of rows & cols
int Table::getData(int row,int col)const{    
    //cout<<"\n"<<columns[col]->getData(row)<<endl; // For printing tab1
    return columns[col]->getData(row); //1;//this->getData(col,row); //0;
}

// Student to supply
// Calls Class RowAray's setData(row,val)
void Table::setData(int row,int col,int val){
    columns[col]->setData(row,val); 
}


//******************************************************************************
//          PlusTab inherits Table->AbsTab1->RowAray->AbsRow
//              PlusTab->Table->AbsTab1->RowAray->AbsRow
//
//******************************************************************************

class PlusTab:public Table{
    public:
        // Calls Table constructor
        PlusTab(unsigned int r,unsigned int c):Table(r,c){};
        PlusTab operator+(const PlusTab &);
};

PlusTab PlusTab::operator+(const PlusTab &a){
    //Student to supply
    return a;
}


//Global Constants
//Function Prototype
void prntTab(const Table &);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows,cols;
   
   //Initialize Variables
   cout<<"Input the Rows and Cols"<<endl;
   cout<<"For a 2-D Array composed of 1-D Rows"<<endl;
   cout<<"Created from Abstract Classes"<<endl;
   cout<<"Inherited to include Overloaded Operators"<<endl;
   //cin>>rows>>cols;
   rows=3; cols=4;
   
   //Test out the Tables
   //Overloaded constructors from different inherited classes
   PlusTab tab1(rows,cols); //PlusTab calls Table constructor to create **columns
   PlusTab tab2(tab1); // PlusTab calls Table copy constructor to 
   PlusTab tab3=tab1+tab2;
   
   //Print the tables
   cout<<"Abstracted and Polymorphic Print Table 1 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab1);
   cout<<"Copy Constructed Table 2 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab2);
   cout<<"Operator Overloaded Table 3 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab3);

   //Exit Stage Right
   return 0;
}

//Prints all 3 PlusTab tables
void prntTab(const Table &a){
    cout<<endl;
    //cout<<"\n***  ^IN PRNTTAB(). row="<<a.getSzRow()<<"  col="<<a.getSzCol()<<" ***\n";
    for(int row=0;row<a.getSzRow();row++){
        for(int col=0;col<a.getSzCol();col++){
            cout<<setw(4)<<a.getData(row,col);
        }
        cout<<endl;
    }
    cout<<endl;
}
/* File:    main.cpp
 * Author:  Danielle F
 * Created: 10-22-232023 @11 PM
 * Purpose: Builds off homework>simpleVectors assignment. Starting from v4

 * Input: 10
 * Output:  M N Q N A N I R. See expectedOutput.PNG
  
 * Version 5: 
 * Modify the SimpleVector to 2x or 1/4x when hitting the arraySize limit.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User Libraries for .h file
// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int numOccup;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0; numOccup=0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   void incrNumOccup(){numOccup++;}
   void decrNumOccup(){numOccup--;}
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }
   
   int getNumOccupSize() const
      { return numOccup; }
   
   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Adding 4 functions Push front/back, Pop front/back
   void pshFrnt(T);
   void pshBack(T);
   T popFrnt();
   T popBack();
   void prntSV(){
       for(int i=0;i<numOccup;i++){cout<<aptr[i]<<" "; }
       cout<<endl;}
    };


//*********************************************************************
// Make func manually mimic vector syntax: vec.insert(vec.begin(),val).
// Add new element to the front of the array, index 0.
//*********************************************************************

template <class T>
void SimpleVector<T>::pshFrnt(T val) 
{
    //Check if array size is maxed out then double ArraySize    
    int size=arraySize;
    if(numOccup==arraySize){
        size=arraySize*2;
        arraySize=size;      
    }
    
    // Create & initialize a new bigger temporary Template array
    T *tempPtr = new T[size]; //[arraySize+1]; 
    
    // Reset first element to val
    tempPtr[0]=val;
   
    // Copy aptr contents to tempPtr starting at index 1 
    for(int count=1, i=0; count < arraySize+1; count++, i++)
        { tempPtr[count] = aptr[i]; }
  
    // Increase numOccup counter
    incrNumOccup();
     
    // Delete aptr and then Copy tempPtr address to aptr. 
    delete [] aptr; //delete [] this->aptr;
    aptr=tempPtr; //this->aptr=tempPtr;        
}


//*********************************************************************
// Make func manually mimic vector syntax: vec.push_back(val).
// Add new element to the back of the array
//*********************************************************************

template <class T>
void SimpleVector<T>::pshBack(T val)
{
    cout<<"pushing back.... "<<val<<endl;
    //Check if array size is maxed out or not   
    int size=arraySize;
    if(numOccup==arraySize){
        size=arraySize*2;
        arraySize=size;      
    }
    cout<<"numOccup = "<<numOccup<<" ArraySize = "<<arraySize<<endl;
    
    // Create & initialize a new bigger temporary Template array
    T *tempPtr = new T[size]; //[arraySize+1]; 
    
    // Reset last element in array to val
    tempPtr[numOccup]=val;
    
    // Copy aptr contents to tempPtr starting at index 0 
    for(int count = 0; count < arraySize; count++)
      { tempPtr[count] = aptr[count]; }
  
    //Increase each counter by 1
    incrNumOccup(); 
    
    // Copy tempPtr to aptr. 
    delete [] aptr;
    aptr=tempPtr;   
}

//*********************************************************************
// Make func manually mimic vector syntax: vec.erase(vec.begin(),vec.begin()+1)
//*********************************************************************

template <class T>
T SimpleVector<T>::popFrnt()
{
    
    // Return frist element in array amd delete it from the aptr
    char zero = aptr[0];
    
    // Create & initialize a new smaller temporary Template pointer array
    T *tempPtr = new T[arraySize-1]; 
    
    
    // Copy aptr contents to tempPtr starting at index 0 
    for(int count = 0; count < arraySize-1; count++)
        { tempPtr[count] = aptr[count+1]; }
  
    //Decrease each counter by 1
    decrNumOccup(); 
    
    // Copy tempPtr to aptr. 
    delete [] aptr;
    aptr=tempPtr;
    
    return zero; //static_cast<char>(zero);
}

//*********************************************************************
// Make func manually mimic vector syntax:  vec.pop_back().
// Remove the last element in the array
//*********************************************************************

template <class T>
T SimpleVector<T>::popBack()
{
    // Return last element in array and delete it from the aptr
    T last = aptr[arraySize-1];
    
   // Create & initialize a new smaller temporary Template pointer array
    T *tempPtr = new T[arraySize-1];
    
    // Copy aptr contents to tempPtr starting at index 0
    for(int count = 0; count < arraySize-1; count++) 
        {tempPtr[count] = aptr[count];}

    //Decrease each counter by 1
    decrNumOccup();         
     
    // Copy tempPtr to aptr. 
    delete [] aptr;
    aptr=tempPtr;
    
    return last; //65;
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
   { *(aptr + count) = 0; }
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   numOccup = obj.numOccup;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
   { *(aptr + count) = *(obj.aptr + count); }
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif

//Global Constants

//Function prototypes
int mrkRand(int seed=0);
void fillVec(SimpleVector<char> &, vector<char> &);
void prntVec(vector<char> &, int);

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    int size;
    cout<<"Input the Size of the Array 10-100"<<endl;
    //cin>>size;
    size=10;
    vector<char> vec(size);     
    SimpleVector<char> sv(size);
    cout<<"The array Size = "<<sv.size()<<endl;
    
    //Fill the Template vector & Vector
    fillVec(sv,vec);
    sv.prntSV(); //Print the Simple Vector and Regular Vector
    //prntVec(vec,10);
    
    //Add a value to the array
    char vlFrnt=mrkRand()%26+65;
    char vlBack=mrkRand()%26+65;
    cout<<"\nThe value added to the front is = "<<vlFrnt<<endl;
    sv.pshFrnt(vlFrnt);
    sv.prntSV();
    //cout<<"\n\t pshFrnt "<<vlFrnt<<"  Array size = "<<sv.size()<<" numOccup="<<sv.getNumOccupSize()<<endl;  
    
    cout<<"\nThe value added to the back  is = "<<vlBack<<endl;
    sv.pshBack(vlBack);
    sv.prntSV();
    //cout<<"\n\t pshBack "<<vlBack<<"  Array size = "<<sv.size()<<" numOccup="<<sv.getNumOccupSize()<<endl;  
    
    
    //Remove 2 from the Front and 2 from the back
    cout<<endl;
    cout<<"Remove 2 from the front and back"<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    sv.prntSV(); //Print the Simple Vector
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
     sv.prntSV(); //Print the Simple Vector
//    cout<<"\n\t popFrnt "<<sv.popFrnt()<<"  Array size = "<<sv.size()<<" numOccup="<<sv.getNumOccupSize()<<endl;  
//    cout<<"\n\t popFrnt "<<sv.popFrnt()<<"  Array size = "<<sv.size()<<" numOccup="<<sv.getNumOccupSize()<<endl;  
//    cout<<"\n\t popBack "<<sv.popBack()<<"  Array size = "<<sv.size()<<" numOccup="<<sv.getNumOccupSize()<<endl;  
//    cout<<"\n\t popBack "<<sv.popBack()<<"  Array size = "<<sv.size()<<" numOccup="<<sv.getNumOccupSize()<<endl;  
    
    
     
     
    // edit regular vector 
    vec.insert(vec.begin(),vlFrnt);
    vec.push_back(vlBack);   
    vec.erase(vec.begin(),vec.begin()+1);
    vec.erase(vec.begin(),vec.begin()+1);
    vec.pop_back();
    vec.pop_back();    
    //prntVec(vec,10); //Print the Vector

    return 0;
}

void prntVec(vector<char> &vec, int perLine){
    cout<<endl;
     cout<<"Regular Vector = ";
     for(int i=0;i<vec.size();i++){
         cout<<vec[i]<<" ";
         if(i%perLine==(perLine-1))cout<<endl;
     }
     cout<<endl;
}


void fillVec(SimpleVector<char> &sv, vector<char> &vec){
    for(int i=0;i<sv.size();i++){
        sv[i]=mrkRand(sv.size())%26+65;
        vec[i]=sv[i];
        sv.incrNumOccup();
    }
    //cout<<"\n\tNumOccupSize="<<sv.getNumOccupSize()<<endl;
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
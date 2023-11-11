/* File:    main.cpp
 * Author:  Danielle F
 * Created: 09-13-2023 @12PM
 * Purpose: To Test and Modify the Simple Vector.
            Simple Vector Push and Pop.
    See lehr github>cis17c>lab>simple vector
    Add the 4 functions in the Template Simple Vector as indicated:
    * push_back
    * pop_back
    * push_front
    * pop_front
    The functions should add or delete from the front or back.  The array will need to be resized and copied.

 * Input: 10
 * Output: see expectedOutput.PNG
 * 
 * Version 1: creates regular vector inside of main to edit a vector when
 * it's not a template.
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
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Adding 4 functions Push front/back, Pop front/back
   void pshFrnt(T);
   void pshBack(T);
   T popFrnt();
   T popBack();
};

//*********************************************************************
// Make func manually mimic vector syntax: vec.insert(vec.begin(),val)
//*********************************************************************

template <class T>
void SimpleVector<T>::pshFrnt(T val) 
{
//    // Create & initialize a new temporary Template pointer array
//    SimpleVector<char> tempPtr(arraySize+1);
//    //tempPtr = new T [arraySize];
//    
//    // Reset first element to val
//    tempPtr[0]=val;
//    
//    //cout<<"\nTempPtr SIZE = "<<tempPtr.size()<<endl;
//    
//    // Copy aptr contents to tempPtr starting at index 1 
//    for(int count = 1; count < tempPtr.size(); count++)
//      {
//          //int i=0;
//          //cout<<i<<" ";
//          tempPtr[count] = aptr[count-1];
//          //NONE of these are working i=i+1; i++; i+=1;
//      }
//  
//    // Copy tempPtr to aptr. aptr=tempPtr;
//    cout<<"\nTempPtr = ";
//    for(int count = 0; count < tempPtr.size(); count++)
//      {cout<<tempPtr[count]<<" ";} cout<<endl;
}


//*********************************************************************
// Make func manually mimic vector syntax: vec.push_back(val)
//*********************************************************************

template <class T>
void SimpleVector<T>::pshBack(T val)
{
    
    // 
}

//*********************************************************************
// Make func manually mimic vector syntax: vec.erase(vec.begin(),vec.begin()+1)
//*********************************************************************

template <class T>
T SimpleVector<T>::popFrnt()
{
   //Student Code Here
   return 65;
}

//*********************************************************************
// Make func manually mimic vector syntax:  vec.pop_back()
//*********************************************************************

template <class T>
T SimpleVector<T>::popBack()
{
   //Student Code Here
   return 65;
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
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
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
void prntVec(SimpleVector<char> &, vector<char> &, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size;
    cout<<"Input the Size of the Array 10-100"<<endl;
    cin>>size;
    cout<<"The array Size = "<<size<<endl;
    SimpleVector<char> sv(size);
    vector<char> vec(size);
     
    //Fill the Template vector & Vector
    fillVec(sv,vec);
    
    //Print the Vector
    prntVec(sv,vec,10);
    
    //Add a value to the array
    char vlFrnt=mrkRand()%26+65;
    char vlBack=mrkRand()%26+65;
    cout<<"The value added to the front is = "<<vlFrnt<<endl;
    cout<<"The value added to the back  is = "<<vlBack<<endl;
    
    // edit regular vector & template vecctor 
    vec.insert(vec.begin(),vlFrnt);
    vec.push_back(vlBack); 
    sv.pshFrnt(vlFrnt);
    sv.pshBack(vlBack);
    
    //Print the Vector
    prntVec(sv,vec,10);
    
    //Remove 2 from the Front and 2 from the back
    cout<<endl;
    cout<<"Remove 2 from the front and back"<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
    
    // edit regular vector 
    vec.erase(vec.begin(),vec.begin()+1);
    vec.erase(vec.begin(),vec.begin()+1);
    vec.pop_back();
    vec.pop_back();
    
    //Print the Vector
    prntVec(sv,vec,10);

    return 0;
}

void prntVec(SimpleVector<char> &sv, vector<char> &vec, int perLine){
    cout<<endl<<"Template Vectr = ";
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
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
    }
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
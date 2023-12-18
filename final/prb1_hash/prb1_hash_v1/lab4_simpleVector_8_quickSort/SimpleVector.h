/* File:   SimpleVector.h
 * Author: DanYell
 * Created on December 13, 2023, 8:44 PM
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;
#include "LinkedList.h"
template <class T>
class SimpleVector {
private:
   LinkedList<T> *aptr;  //Pointer to Linked List
   //T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int numOccup;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector(){ aptr=new LinkedList<T>(0); arraySize = 0; numOccup=0;}      
   
   // Constructor declaration
   SimpleVector(int);//(const T &);//
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
    // Access to return the array size
    int size() const { return aptr->cntLst(); } //{ return arraySize; }
       
   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   void incrNumOccup(){numOccup++;}
   void decrNumOccup(){numOccup--;}   
   int getNumOccupSize() const {return numOccup;}
   
   //Adding 4 functions Push front/back, Pop front/back
   void pushFrnt(int);//(const T &);
   void pushBack(int);//(const T &);
   T popFront();
   T popBack();
   void getQuickSort(){
       int count = aptr->cntLst();
       cout<<"\tList count = "<<count<<" = "<<aptr->getObj(count-1)<<endl;
       aptr->quick_sort(aptr->getPtr(0), aptr->getPtr(count-1));
   
   }
   void getTail(){aptr->setTail();};
   void prntSV(){aptr->prntLst();};
};

//*********************************************************************
// Make func manually mimic vector syntax: vec.insert(vec.begin(),val).
// Add new element to the front of the array, index 0.
//*********************************************************************

template <class T>
void SimpleVector<T>::pushFrnt(int val) {
    aptr->pshFrnt(val);
}


//*********************************************************************
// Make func manually mimic vector syntax: vec.push_back(val).
// Add new element to the back of the array
//*********************************************************************

template <class T>
void SimpleVector<T>::pushBack(int val){ //(const T &val)
    aptr->pshBack(val);
}

//*********************************************************************
// Make func manually mimic vector syntax: vec.erase(vec.begin(),vec.begin()+1)
//*********************************************************************

template <class T>
T SimpleVector<T>::popFront(){
    
    // Return frist element in array amd delete it from the aptr
    int zero = aptr->popFrnt();
    return zero; //static_cast<int>(zero);
}

//*********************************************************************
// Make func manually mimic vector syntax:  vec.pop_back().
// Remove the last element in the array
//*********************************************************************

template <class T>
T SimpleVector<T>::popBack(){
    // Return last element in array and delete it from the aptr
    T last = aptr->popBck();    
    return last; //65;
}

//***********************************************************
//      Constructor for SimpleVector class with 1 object                 
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int d){//(const T &d){ //
   arraySize = 0;
   numOccup = 0;
   // Allocate memory for the array.
   try {aptr=new LinkedList<T>(d);}//aptr = new T [s];   
   catch (bad_alloc){ memError(); }
   arraySize++;
   numOccup++;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
   // Copy the array size.
   //arraySize = obj.arraySize;
   //numOccup = obj.numOccup;
   
   // Allocate memory for the array.
   aptr = new LinkedList<T>(obj.aptr->getObj(0));//aptr = new T [arraySize];  
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < obj.size(); count++)
   { aptr->addLst(obj.aptr->getObj(count)); }
}


//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector(){
      delete aptr;
}
//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError(){
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError(){
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub){
   if (sub < 0 || sub >= aptr->cntLst())
      subError();
   return aptr->getObj(sub);
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub){
   if (sub < 0 || sub >= aptr->cntLst())
      subError();
   return aptr->getPtr(sub);
}
#endif /* SIMPLEVECTOR_H */


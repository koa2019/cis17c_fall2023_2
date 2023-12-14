/*  Author: Danielle 
    Date:   12-10-23 @1:17 am
    Purpose: Linked List v5 
 
    v5:
    * Added LinkList.h and it has structure link.h in it and I
    * moved all link.h functions to LinkedList.h class template. Horrible.
 
 
    v6 To do:
 
    * Turn Singular Linked List to Double Linked List

    * Use this to create a Sorted Linked List,

    * Use this to create a prioritized list by use.  
      Bring to front those links recently queried.

    * Sufficiently test and prove that they work as intended.  How do you prove it is working?
    

 * FYI:
    * lnkList is lnkList
    * lnk2 is lnkList->linkPtr
    * lnk3 is lnkList->linkPtr->linkPtr
    * lnk4 is lnkList->linkPtr->linkPtr->linkPtr
    * lnk5 is lnkList->linkPtr->linkPtr->linkPtr->linkPtr   
*/

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
#include "LinkedList.h"

//Function Prototypes for Link structure

//Execution Begins Here
int main(int argc, char** argv) {
    
    // Declare variables
    LinkedList<int> *list1;
    list1 = new LinkedList<int>(5);
    (*list1).prntLst();
    list1->pshBack(2);
    (*list1).prntLst();
    list1->pshFrnt(9);
    (*list1).prntLst();
    list1->pshFrnt(66);
    list1->pshFrnt(12);
    list1->pshFrnt(4);
    (*list1).prntLst();
    
    cout<<"\nPopped from front: "<<list1->popFrnt();    
    (*list1).prntLst();    
    cout<<"\nPopped from back: "<<list1->popBack();
    (*list1).prntLst();   
    
//    LinkedList<int> *lnk6 = create(6);
//    cout<<"\n\nCreated node "<<lnk6->data;
//    cout<<"\nPushed back node "<<lnk6->data<<"\n";
//    pshBack(lnkList,lnk6); // pshBack(linkList, link want to push back)
//    prntLst(lnkList);

    /*  HOW DO YOU FIND A NODE AND THEN INSERT IT AT THE FRONT ???????????    */
    //cout<<"\nPush front: "<<lnkList->linkPtr->linkPtr->data<<endl; // Push node 3 to front
    //fndPshFrnt(lnkList,lnkList->linkPtr->linkPtr); // Push node 3 to front
    
    return 0;
}


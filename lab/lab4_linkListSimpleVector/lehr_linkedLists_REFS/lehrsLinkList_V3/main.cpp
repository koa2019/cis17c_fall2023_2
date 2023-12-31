/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose: Linked from first principles v3.	
	     Adds Link.h and functions. pop(), push().
	
	v4: 
	1) Complete the function prototypes for the linked list:
    pop_front(), pop_back(), push_front(),push_back(),prntLst(),dstryLst().
	
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
#include "Link.h"


//Function Prototypes
Link *fillLst(int);
void prntLst(Link *);
void destroy(Link *);

//Prototype function you are to consider for Wednesday
Link *create(int);    //Create a Link with Data
void pshFrnt(Link *,Link *); //Push a link to the front
void pshBack(Link *,Link *); //Push a link to the end
Link *popFrnt(Link *);      //Pull/pop a link from the front
Link *popBack(Link *);      //Pull/pop a link from the back

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    Link *lnk1=fillLst(5);
    
    //Printing all the data elements in the linked list
    prntLst(lnk1);
    
    //Delete all the allocated memory
    destroy(lnk1);
    
    //Exit stage right
    return 0;
}

Link *fillLst(int n){
    //Initially create the front pointer/beginning pointer
    Link *front=new Link;
    front->data=1;
    front->lnkNext=NULL;
    //If n>1 then fill with the data and links to the next
    Link *temp=front;
    for(int i=2;i<=n;i++){
        Link *nxtLink=new Link; // Allocate memory for new link that's next in line
        nxtLink->data=i; //Initializing this link's member variable 
        temp->lnkNext=nxtLink; // Setting the previous link's lnkNext pointer to this current link's address. ex link2->lnkNext = link3.
        temp=nxtLink; // Resets temps address to the current link's address to prepare for the next iteration.
    }
    temp->lnkNext=NULL; //Initialize the last link's lnkNext member variable to null
    //Return the front of the list
    return front;
}

void prntLst(Link *next){
    while(next!=NULL){
        cout<<next->data<<endl;
        next=next->lnkNext;
    }
}

void destroy(Link *front){
    while(front!=NULL){
        Link *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}
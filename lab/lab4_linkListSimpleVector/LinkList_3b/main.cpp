/*  Author: Danielle 
    Date:   March 29th, 2021  1:12pm
    Purpose: Builds off of Dr. Lehr's LinkedList_v3. 	
 
    * Adds Link.h.
    * Defined pop_front(),
               * pop_back(),
               * push_front(),
               * push_back().   	
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
Link *popFrnt(Link *);      //Pull/pop a link from the front
Link *popBack(Link *);      //Pull/pop a link from the back
void pshFrnt(Link *,Link *); //Push a link to the front
void pshBack(Link *,Link *); //Push a link to the end


//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    Link *lnk1=fillLst(5);
    
    //Printing all the data elements in the linked list
    cout<<"\nOriginal List\n";
    prntLst(lnk1);
    
    
        /* 
        * lnk1 is lnk1
        * lnk2 is lnk1->lnkNext
        * lnk3 is lnk1->lnkNext->lnkNext
        * lnk4 is lnk1->lnkNext->lnkNext->lnkNext
        * lnk5 is lnk1->lnkNext->lnkNext->lnkNext->lnkNext
        */
        
    cout<<"\nPopped from front\n";
    lnk1 = popFrnt(lnk1);//pop out the last node
    prntLst(lnk1);
    
    cout<<"\nPopped from back\n";
    lnk1 = popBack(lnk1);//pop out the last node
    prntLst(lnk1);
    
    Link *lnk0 = create(0);
    cout<<"\nCreated lnk"<<lnk0->data;
    
    cout<<"\nPushed front: "<<lnk0->data<<endl;
    pshFrnt(lnk1,lnk0); // Push lnk0 to front of lnk1    
    prntLst(lnk1);
    
    Link *lnk6 = create(6);
    cout<<"\nCreated lnk"<<lnk6->data;
    cout<<"\nPushed back: "<<lnk6->data<<endl;
    pshBack(lnk1,lnk6); // pshBack(linkList, link want to push back)
    prntLst(lnk1);

    lnk0=nullptr;
    lnk6=nullptr;
    destroy(lnk1);    
    return 0;
}


/******************************************************************************/
/*                     Push a link to the end                                 */
/******************************************************************************/

void pshBack(Link *head, Link *newTail){ 
    
    /*    while this node's lnkNext is NOT NULL   */
    while(head->lnkNext !=NULL){ 
             
        //cout<<"node "<<head->data<<endl;// Print current node
        
        /*  Move iterator forward by 1  */
        head=head->lnkNext;
    }
    //cout<<"Outside Loop. iterator at "<<head->data<<endl;
    head->lnkNext = newTail; //On last node, point lnkNext to newTail
}



/******************************************************************************/
/*                      Push a link to the front                              */
/*                      Swap old head to new head                             */
//  https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/ 
/******************************************************************************/

void pshFrnt(Link *oldHead, Link *newHead){ 
    
     /*  Swap oldHead and newHead  */   
    Link *temp = create(oldHead->data);  //Create new temporary node & initialize with oldHead's variables    
    (*temp).lnkNext = oldHead->lnkNext; //Diff ways to de-reference a pointer
    
   
    /* Link oldHead first node's address to newHead's address */
    oldHead->lnkNext = newHead; //Inserts newHead node
    oldHead->data    = newHead->data;
    
    /*  Reset newHead variables with oldHead's */
    newHead->data    = temp->data;
    newHead->lnkNext = temp->lnkNext; 
}



/******************************************************************************/
//                        Pull/pop a link from the front
/******************************************************************************/

Link *popFrnt(Link *oldList){      
    
    // Allocate new temp pointer
    Link *temp = new Link;
    
    // Set temp's address to the oldList's head (the first node's pointer address)
    temp = oldList->lnkNext;
    
    // Set oldList's first node's pointer to null
    oldList->lnkNext = NULL;
    
    // Delete the old list
    delete oldList;
    
    // Return new smaller list
    return temp;
}



/******************************************************************************/
/*                  Pull/pop a link from the back                             */
/*                                                                            */
//https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
/******************************************************************************/

Link *popBack(Link *oldList){ 
    
    // Allocate new temp pointer
    Link *temp = new Link;
    
    // Set temp's address to the oldList's address
    temp = oldList;   
   
    //cout<<"Iterate until you find the second last node\n\n";    
                
    /* Iterate until you find the second last element in the list.  */
    // Compares current node's neighbor's lnkNext variable 
    // 1st iteration starts by looking at lnk2's variable lnkNext. Is it NULL or not?
    //    lnk1->lnkNext->lnkNext=lnk3;   from v1
    while(temp->lnkNext->lnkNext != NULL){         
        
        //cout<<"\titerator on "<<temp->data<<endl;    
        //cout<<"\tTRUE.  "<<temp->lnkNext->data<<"'s lnkNext is NOT NULL"<<endl; 
       
        /* move iterator forward by 1   */      
        temp = temp->lnkNext; //moves to lnk2 after 1st iteration
        //cout<<"\titerator moved to "<<temp->data<<endl<<endl;
        
    }   
        
    cout<<"Outside loop.  iterator at "<<temp->data<<endl;   
    //cout<<"list's second last node is "<<temp->data<<endl<<endl;
    
    /* Assign NULL to the second last node in the list.  */ 
    //cout<<"deleting "<<temp->lnkNext->data<<endl; 
    delete temp->lnkNext; //pointing & deleting last node in list
    temp->lnkNext=NULL;
                
    return oldList;
}



/******************************************************************************/
//                  Create a Link with Data  
/******************************************************************************/

Link *create(int num){      
    Link *newLink = new Link;
    newLink->data=num;       //alt way  (*link).data=num;
    newLink->lnkNext=NULL;
    return newLink;
}


/******************************************************************************/
//                      Fill list with n links                
/******************************************************************************/
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
    while(next!=NULL){ //while entire node is NOT NULL
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
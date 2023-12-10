/*  Author: Danielle 
    Date:   10-22-23 @10:39 pm
    Purpose: v4b functions should return a single value not the entire linked list
            * Linked from first principles v3b_templateClass	
            * Turns in from a structure to a template<class> with a structure	
     
    * lnk1 is lnk1
    * lnk2 is lnk1->lnkNext
    * lnk3 is lnk1->lnkNext->lnkNext
    * lnk4 is lnk1->lnkNext->lnkNext->lnkNext
    * lnk5 is lnk1->lnkNext->lnkNext->lnkNext->lnkNext
   
*/

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
#include "Link.h"


//Function Prototypes
Link<int> *fillLst(int);
void prntLst(Link<int> *);
void destroy(Link<int> *);

//Prototype function you are to consider for Wednesday
Link<int> *create(int);    //Create a Link with Data
void pshFrnt(Link<int> *,Link<int> *); //Push a link to the front
void pshBack(Link<int> *,Link<int> *); //Push a link to the end
void fndPshFrnt(Link<int> *,Link<int> *); //Find and then Push a link to the end
int popFrnt(Link<int> *);      //Pull/pop a link from the front
int popFrnt(Link<int> **);      //Pull/pop a link from the front
int popBack(Link<int> *);      //Pull/pop a link from the back

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare variables
    Link<int> *lnk1=fillLst(5);
    
    //Printing all the data elements in the linked list
    cout<<"\nOriginal Linked List\n";
    prntLst(lnk1);
    
       
    int indx = popFrnt(&lnk1);//pop out the last node
    //int indx = popFrnt(lnk1);//pop out the last node
    cout<<"\nPopped from front: "<<indx<<endl;    
    prntLst(lnk1);
    
    cout<<"\nPopped from back:  ";
    cout<<popBack(lnk1)<<endl;//pop out the last node
    prntLst(lnk1);
    
    Link<int> *lnk9 = create(9);
    cout<<"\n\nCreated node "<<lnk9->data;
    
    cout<<"\nPushed front node "<<lnk9->data<<"\n";
    pshFrnt(lnk1,lnk9); // Push lnk9 to front of lnk1    
    prntLst(lnk1);
    
    Link<int> *lnk6 = create(6);
    cout<<"\n\nCreated node "<<lnk6->data;
    cout<<"\nPushed back node "<<lnk6->data<<"\n";
    pshBack(lnk1,lnk6); // pshBack(linkList, link want to push back)
    prntLst(lnk1);


    /*  HOW DO YOU FIND A NODE AND THEN INSERT IT AT THE FRONT ???????????    */
    //cout<<"\nPush front: "<<lnk1->lnkNext->lnkNext->data<<endl; // Push node 3 to front
    //fndPshFrnt(lnk1,lnk1->lnkNext->lnkNext); // Push node 3 to front
    
    lnk9=nullptr;
    lnk6=nullptr;
    destroy(lnk1);    
    return 0;
}


/******************************************************************************/
/*                     Push a link to the end                                 */
/******************************************************************************/
void pshBack(Link<int> *head, Link<int> *newTail){ 
        
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
void pshFrnt(Link<int> *oldHead, Link<int> *newHead){ 
    
     /*  Swap oldHead and newHead  */   
    Link<int> *temp = create(oldHead->data);  //Create new temporary node & initialize with oldHead's variables    
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
//https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/?ref=lbp
/******************************************************************************/
int popFrnt(Link<int> **head){   
    
    int index0 = head[0]->data;// set with the first element in head  
    Link<int> *temp = *head; // Store head node
    *head = temp->lnkNext;// Change head
    free(temp);           // Free old head
    return index0;
}


int popFrnt(Link<int> *head){      
    
    int index0 = head->data;// set with the first element in head
    
    Link<int> *temp =new Link<int>;   
        
    // Set temp's address to the head's head (the first node's pointer address)
    temp = head->lnkNext;
    
    cout<<endl<<endl<<"temp->data = "<<temp->data<<endl;//2    
    
    head->lnkNext = NULL;  // Set head's first pointer to null
    
    delete head;
    
    head=temp;// set head address to temp's address
     
    cout<<endl<<"Hit popFront.\nhead: "; prntLst(head); 
    cout<<endl<<"temp: "; prntLst(temp); cout<<endl;
    
    //delete temp->lnkNext;
    //temp->lnkNext = NULL; 
    
    return index0;
}




/******************************************************************************/
/*                  Pull/pop a link from the back                             */
/*                                                                            */
//https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
/******************************************************************************/
int popBack(Link<int> *oldList){     
    
    // Allocate new temp pointer
    Link<int> *temp = new Link<int>;
    
    // Set temp's address to the oldList's address
    temp = oldList;   
  
    // Search for the 2nd to last element in list
    while(temp->lnkNext->lnkNext != NULL){         
       //cout<<"'s lnkNext is NOT NULL"<<endl; 
       
        /* move iterator forward by 1   */      
        temp = temp->lnkNext; //moves to lnk2 after 1st iteration
        //cout<<"\titerator moved to "<<temp->data<<endl<<endl;
        
    }   
        
    //cout<<"\nOutside loop. iterator at "<<temp->data<<endl;   
    //cout<<"list's second last node is "<<temp->data<<endl<<endl; 
    
    
    /* Assign NULL to the second last node in the list.  */ 
    int last=temp->lnkNext->data;//Set with last number in list
    //cout<<"deleting "<<last<<endl; 
    
    delete temp->lnkNext; //pointing & deleting last node in list
    temp->lnkNext=NULL;                
    return last;
}


/******************************************************************************/
//                  Create a Link with Data  
/******************************************************************************/
Link<int> *create(int num){      
    Link<int> *newLink = new Link<int>;
    newLink->data=num;       //alt way  (*link).data=num;
    newLink->lnkNext=NULL;
    return newLink;
}


/******************************************************************************/
//                      Fill list with n links
/******************************************************************************/
Link<int> *fillLst(int n){
    
    //Initially create the front pointer/beginning pointer
    Link<int> *front=new Link<int>;
    front->data=1;
    front->lnkNext=NULL;
    //If n>1 then fill with the data and links to the next
    Link<int> *temp=front;
    for(int i=2;i<=n;i++){
        Link<int> *nxtLink=new Link<int>; // Allocate memory for new link that's next in line
        nxtLink->data=i; //Initializing this link's member variable 
        temp->lnkNext=nxtLink; // Setting the previous link's lnkNext pointer to this current link's address. ex link2->lnkNext = link3.
        temp=nxtLink; // Resets temps address to the current link's address to prepare for the next iteration.
    }
    temp->lnkNext=NULL; //Initialize the last link's lnkNext member variable to null
    //Return the front of the list
    return front;
}



void prntLst(Link<int> *head){
    while(head!=NULL){ //while entire node is NOT NULL
        cout<<head->data<<" ";
        head=head->lnkNext;// Move iterator forward
    }
}

void destroy(Link<int> *front){
    while(front!=NULL){
        Link<int> *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}


/******************************************************************************/
//                           BROKEN!!!
/*                       Push findThis to the end                                */
/******************************************************************************/
void fndPshFrnt(Link<int> *oldList,Link<int> *findThis){

    //cout<<"\noldList: "<<oldList->lnkNext->data<<"\nfindThis: "<<findThis->data<<endl;    
    int num = findThis->data;
    cout<<"Push back "<<num<<endl;
    
    Link<int> *front=new Link<int>;    
    while(oldList!=NULL){  
        
    //Initially create the front pointer/beginning pointer
   
    front->data=oldList->data;
    front->lnkNext=NULL;
    Link<int> *temp=front;    

        
        if(oldList->data!=num){ //Fill new list starting at 1, if the link we're pushing isn't the first one
            
            //If n>1 then fill with the data and links to the next           
            for(int i=2;i<=5;i++){
                Link<int> *nxtLink=new Link<int>; // Allocate memory for new link that's next in line
                nxtLink->data=oldList->data;//i // if num==2, then set it to 3
                cout<<"nxtLink->data:  "<<nxtLink->data<<endl;
                temp->lnkNext=nxtLink; // Setting the previous link's lnkNext pointer to this current link's address. ex link2->lnkNext = link3.
                temp=nxtLink; // Resets temps address to the current link's address to prepare for the next iteration.
            }
            temp->lnkNext=NULL;//oldList->lnkNext;  //Initialize the last link's lnkNext member variable to null
                  
        }
        else if(oldList->data==num){  //if findThis->data is 1
            cout<<oldList->data<<"=="<<num<<endl;
            //cout<<oldList->lnkNext->lnkNext->lnkNext->lnkNext->data<<endl;//5
        } 
        
        cout<<"oldList:  "<<oldList->data<<endl;     
        //move iterator forward
        oldList=oldList->lnkNext;
   }
    
    prntLst(front);
    
}

/******************************************************************************/
/*                  Pull/pop a link from the back                             */
/*                                                                            */
//https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
/******************************************************************************/
//Link<int> *popBack(Link<int> *oldList){ 
//    
//    // Allocate new temp pointer
//    Link<int> *temp = new Link<int>;
//    
//    // Set temp's address to the oldList's address
//    temp = oldList;   
//   
//    //cout<<"Iterate until you find the second last node\n\n";    
//                
//    /* Iterate until you find the second last element in the list.  */
//    // Compares current node's neighbor's lnkNext variable 
//    // 1st iteration starts by looking at lnk2's variable lnkNext. Is it NULL or not?
//    //    lnk1->lnkNext->lnkNext=lnk3;   from v1
//    while(temp->lnkNext->lnkNext != NULL){         
//        
//        //cout<<"\titerator on "<<temp->data<<endl;    
//        //cout<<"\tTRUE.  "<<temp->lnkNext->data<<"'s lnkNext is NOT NULL"<<endl; 
//       
//        /* move iterator forward by 1   */      
//        temp = temp->lnkNext; //moves to lnk2 after 1st iteration
//        //cout<<"\titerator moved to "<<temp->data<<endl<<endl;
//        
//    }   
//        
//    cout<<"Outside loop.  iterator at "<<temp->data<<endl;   
//    //cout<<"list's second last node is "<<temp->data<<endl<<endl;
//    
//    /* Assign NULL to the second last node in the list.  */ 
//    //cout<<"deleting "<<temp->lnkNext->data<<endl; 
//    delete temp->lnkNext; //pointing & deleting last node in list
//    temp->lnkNext=NULL;
//                
//    return oldList;
//}
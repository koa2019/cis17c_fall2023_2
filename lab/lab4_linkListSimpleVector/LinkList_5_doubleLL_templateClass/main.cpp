/*  Author: Danielle 
    Date:   12-10-23 @1:17 am
    Purpose: Linked List v5 
 
    To do:
 
    Turn Singular Linked List to Double Linked List

    Create a Doubly Linked List.

    Use this to create a Sorted Linked List,

    Use this to create a prioritized list by use.  Bring to front those links recently queried.

    Sufficiently test and prove that they work as intended.  How do you prove it is working?
    
    BUG:
    * Make popFrnt(Link<int>*) work like popFrnt(Link<int>**)
 
    * lnkList is lnkList
    * lnk2 is lnkList->next
    * lnk3 is lnkList->next->next
    * lnk4 is lnkList->next->next->next
    * lnk5 is lnkList->next->next->next->next   
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
int popFrnt(Link<int>*);      //Pull/pop a link from the front
int popFrnt(Link<int>**);      //Pull/pop a link from the front
int popBack(Link<int>*);      //Pull/pop a link from the back

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare variables
    Link<int> *lnkList=fillLst(5);
    
    //Printing all the data elements in the linked list
    cout<<"\nOriginal Linked List\n";
    prntLst(lnkList);
    
       
    int indx = popFrnt(&lnkList);//pop out the last node
    //int indx = popFrnt(lnkList);//pop out the last node
    cout<<"\nPopped from front: "<<indx<<endl;    
    prntLst(lnkList);
    
    cout<<"\nPopped from back:  ";
    cout<<popBack(lnkList)<<endl;//pop out the last node
    prntLst(lnkList);
    
    Link<int> *lnk9 = create(9);
    cout<<"\n\nCreated node "<<lnk9->data;
    
    cout<<"\nPushed front node "<<lnk9->data<<"\n";
    pshFrnt(lnkList,lnk9); // Push lnk9 to front of lnkList    
    prntLst(lnkList);
    
    Link<int> *lnk6 = create(6);
    cout<<"\n\nCreated node "<<lnk6->data;
    cout<<"\nPushed back node "<<lnk6->data<<"\n";
    pshBack(lnkList,lnk6); // pshBack(linkList, link want to push back)
    prntLst(lnkList);


    /*  HOW DO YOU FIND A NODE AND THEN INSERT IT AT THE FRONT ???????????    */
    //cout<<"\nPush front: "<<lnkList->next->next->data<<endl; // Push node 3 to front
    //fndPshFrnt(lnkList,lnkList->next->next); // Push node 3 to front
    
    lnk9=nullptr;
    lnk6=nullptr;
    destroy(lnkList);    
    return 0;
}


/******************************************************************************/
/*                     Push a link to the end                                 */
/******************************************************************************/
void pshBack(Link<int> *head, Link<int> *newTail){ 
        
    /*    while this node's next is NOT NULL   */
    while(head->next !=NULL){ 
             
        //cout<<"node "<<head->data<<endl;// Print current node
        
        /*  Move iterator forward by 1  */
        head=head->next;
    }
    //cout<<"Outside Loop. iterator at "<<head->data<<endl;
    head->next = newTail; //On last node, point next to newTail
}


/******************************************************************************/
/*                      Push a link to the front                              */
/*                      Swap old head to new head                             */
//  https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/ 
/******************************************************************************/
void pshFrnt(Link<int> *oldHead, Link<int> *newHead){ 
    
     /*  Swap oldHead and newHead  */   
    Link<int> *temp = create(oldHead->data);  //Create new temporary node & initialize with oldHead's variables    
    (*temp).next = oldHead->next; //Diff ways to de-reference a pointer
    
   
    /* Link oldHead first node's address to newHead's address */
    oldHead->next = newHead; //Inserts newHead node
    oldHead->data    = newHead->data;
    
    /*  Reset newHead variables with oldHead's */
    newHead->data    = temp->data;
    newHead->next = temp->next; 
}



/******************************************************************************/
//                        Pull/pop a link from the front
//https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/?ref=lbp
/******************************************************************************/
int popFrnt(Link<int> **head){   
    
    int index0 = head[0]->data;// set with the first element in head  
    Link<int> *temp = *head; // Store head node
    *head = temp->next;// Change head
    free(temp);           // Free old head
    return index0;
}


int popFrnt(Link<int> *head){      
    
    int index0 = head->data;// set with the first element in head
    
    Link<int> *temp =new Link<int>;   
        
    // Set temp's address to the head's head (the first node's pointer address)
    temp = head->next;
    
    cout<<endl<<endl<<"temp->data = "<<temp->data<<endl;//2    
    
    head->next = NULL;  // Set head's first pointer to null
    
    delete head;
    
    head=temp;// set head address to temp's address
     
    cout<<endl<<"Hit popFront.\nhead: "; prntLst(head); 
    cout<<endl<<"temp: "; prntLst(temp); cout<<endl;
    
    //delete temp->next;
    //temp->next = NULL; 
    
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
    while(temp->next->next != NULL){         
       //cout<<"'s next is NOT NULL"<<endl; 
       
        /* move iterator forward by 1   */      
        temp = temp->next; //moves to lnk2 after 1st iteration
        //cout<<"\titerator moved to "<<temp->data<<endl<<endl;
        
    }   
        
    //cout<<"\nOutside loop. iterator at "<<temp->data<<endl;   
    //cout<<"list's second last node is "<<temp->data<<endl<<endl; 
    
    
    /* Assign NULL to the second last node in the list.  */ 
    int last=temp->next->data;//Set with last number in list
    //cout<<"deleting "<<last<<endl; 
    
    delete temp->next; //pointing & deleting last node in list
    temp->next=NULL;                
    return last;
}


/******************************************************************************/
//                  Create a Link with Data  
/******************************************************************************/
Link<int> *create(int num){      
    Link<int> *newLink = new Link<int>;
    newLink->data=num;       //alt way  (*link).data=num;
    newLink->next=NULL;
    return newLink;
}


/******************************************************************************/
//                      Fill list with n links
/******************************************************************************/
Link<int> *fillLst(int n){
    
    //Initially create the front pointer/beginning pointer
    Link<int> *front=new Link<int>;
    front->data=1;
    front->next=NULL;
    //If n>1 then fill with the data and links to the next
    Link<int> *temp=front;
    for(int i=2;i<=n;i++){
        Link<int> *nxtLink=new Link<int>; // Allocate memory for new link that's next in line
        nxtLink->data=i; //Initializing this link's member variable 
        temp->next=nxtLink; // Setting the previous link's next pointer to this current link's address. ex link2->next = link3.
        temp=nxtLink; // Resets temps address to the current link's address to prepare for the next iteration.
    }
    temp->next=NULL; //Initialize the last link's next member variable to null
    //Return the front of the list
    return front;
}



void prntLst(Link<int> *head){
    while(head!=NULL){ //while entire node is NOT NULL
        cout<<head->data<<" ";
        head=head->next;// Move iterator forward
    }
}

void destroy(Link<int> *front){
    while(front!=NULL){
        Link<int> *temp=front;
        front=front->next;
        delete temp;
    }
}


/******************************************************************************/
//                           BROKEN!!!
/*                       Push findThis to the end                                */
/******************************************************************************/
void fndPshFrnt(Link<int> *oldList,Link<int> *findThis){

    //cout<<"\noldList: "<<oldList->next->data<<"\nfindThis: "<<findThis->data<<endl;    
    int num = findThis->data;
    cout<<"Push back "<<num<<endl;
    
    Link<int> *front=new Link<int>;    
    while(oldList!=NULL){  
        
    //Initially create the front pointer/beginning pointer
   
    front->data=oldList->data;
    front->next=NULL;
    Link<int> *temp=front;    

        
        if(oldList->data!=num){ //Fill new list starting at 1, if the link we're pushing isn't the first one
            
            //If n>1 then fill with the data and links to the next           
            for(int i=2;i<=5;i++){
                Link<int> *nxtLink=new Link<int>; // Allocate memory for new link that's next in line
                nxtLink->data=oldList->data;//i // if num==2, then set it to 3
                cout<<"nxtLink->data:  "<<nxtLink->data<<endl;
                temp->next=nxtLink; // Setting the previous link's next pointer to this current link's address. ex link2->next = link3.
                temp=nxtLink; // Resets temps address to the current link's address to prepare for the next iteration.
            }
            temp->next=NULL;//oldList->next;  //Initialize the last link's next member variable to null
                  
        }
        else if(oldList->data==num){  //if findThis->data is 1
            cout<<oldList->data<<"=="<<num<<endl;
            //cout<<oldList->next->next->next->next->data<<endl;//5
        } 
        
        cout<<"oldList:  "<<oldList->data<<endl;     
        //move iterator forward
        oldList=oldList->next;
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
//    // Compares current node's neighbor's next variable 
//    // 1st iteration starts by looking at lnk2's variable next. Is it NULL or not?
//    //    lnkList->next->next=lnk3;   from v1
//    while(temp->next->next != NULL){         
//        
//        //cout<<"\titerator on "<<temp->data<<endl;    
//        //cout<<"\tTRUE.  "<<temp->next->data<<"'s next is NOT NULL"<<endl; 
//       
//        /* move iterator forward by 1   */      
//        temp = temp->next; //moves to lnk2 after 1st iteration
//        //cout<<"\titerator moved to "<<temp->data<<endl<<endl;
//        
//    }   
//        
//    cout<<"Outside loop.  iterator at "<<temp->data<<endl;   
//    //cout<<"list's second last node is "<<temp->data<<endl<<endl;
//    
//    /* Assign NULL to the second last node in the list.  */ 
//    //cout<<"deleting "<<temp->next->data<<endl; 
//    delete temp->next; //pointing & deleting last node in list
//    temp->next=NULL;
//                
//    return oldList;
//}
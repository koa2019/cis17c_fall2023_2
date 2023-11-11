/*  Author: Danielle 
    Date:   10-22-23 @10:39 pm
    Purpose: 
            * Linked from first principles v3b_templateClass	
            * Turns in from a structure to a template<class> with a structure	
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
Link<int> *popFrnt(Link<int> *);      //Pull/pop a link from the front
Link<int> *popBack(Link<int> *);      //Pull/pop a link from the back

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    Link<int> *lnk1=fillLst(5);
    
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
    
    Link<int> *lnk0 = create(0);
    cout<<"\nCreated lnk"<<lnk0->data;
    
    cout<<"\nPushed front: "<<lnk0->data<<endl;
    pshFrnt(lnk1,lnk0); // Push lnk0 to front of lnk1    
    prntLst(lnk1);
    
    Link<int> *lnk6 = create(6);
    cout<<"\nCreated lnk"<<lnk6->data;
    cout<<"\nPushed back: "<<lnk6->data<<endl;
    pshBack(lnk1,lnk6); // pshBack(linkList, link want to push back)
    prntLst(lnk1);


    /*  HOW DO YOU FIND A NODE AND THEN INSERT IT AT THE FRONT ???????????    */
    //cout<<"\nPush front: "<<lnk1->lnkNext->lnkNext->data<<endl; // Push node 3 to front
    //fndPshFrnt(lnk1,lnk1->lnkNext->lnkNext); // Push node 3 to front
    
    lnk0=nullptr;
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
/******************************************************************************/
Link<int> *popFrnt(Link<int> *oldList){      
    
    // Allocate new temp pointer
    Link<int> *temp = new Link<int>;
    
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
Link<int> *popBack(Link<int> *oldList){ 
    
    // Allocate new temp pointer
    Link<int> *temp = new Link<int>;
    
    // Set temp's address to the oldList's address
    temp = oldList;   
  
    while(temp->lnkNext->lnkNext != NULL){         
       //ata<<"'s lnkNext is NOT NULL"<<endl; 
       
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



void prntLst(Link<int> *next){
    while(next!=NULL){ //while entire node is NOT NULL
        cout<<next->data<<endl;
        next=next->lnkNext;
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
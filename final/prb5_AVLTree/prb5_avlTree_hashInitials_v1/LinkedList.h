/* File:   LinkedList.h
 * Author: DanYell
 * Created on December 10, 2023, 2:13 AM
 * Purpose: Lab 4 simple vector Linked list v7
 * Referenced Lehr's midterm > SimpleVectorUsingLinkedList/LinkedList.h
 
 * v7:
 * Replaced simple vector's array with linked list.
 
 * https://github.com/ml1150258/CSC_CIS_17C/blob/master/Book/MidtermSpecific/SimpleVectorUsingLinkedList/LinkedList.h
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;   //Library Name-space

template<class T>
class LinkedList {
    private:
        struct Link{
            T data;		//Any integer data, to be changed any class with templates later 
            Link *linkPtr; //Next Link in the chain. Self Reference which when utilized forms a linked list
        }; 
        Link *prev; //Next Link in the chain. Makes it a doubly linked list. Self Reference which when utilized forms a linked list
        Link *head,*next,*tail,*temp,*found;
        fndLst(const T&);  //Determine address of link that contains the data
  
    public:
        LinkedList(const int); // Default Constructor
        ~LinkedList(); // void destroy(Link<int> *);
        void prntLst();        
        void pshBack(T&); //Push a link to the end. Lehr's addLst()
        void pshFrnt(T&); //Push a link to the head
        int popFrnt();      //Pull/pop a link from the head
        int popBck();      //Pull/pop a link from the back       
        void fillLst(int n=1);
        int  findLst(const T&);  //Determine what link contains the data
        int   cntLst();          //How many elements are in the list
        T     getObj(int);       //Return the object
        T   &getPtr(int);       //Return the pointer to the object    
};

/******************************************************************************/
//                  Like a Constructor, but for the head Link only 
// Output -> head  The address to the head of the allocated list.
/******************************************************************************/
template<class T>
LinkedList<T>::LinkedList(const int data){    
    head = new Link; //Allocate a link at the head of the list        
    head->data=data;    //Initialize with data. Alt deref (*link).data=num;
    head->linkPtr=NULL; //At the moment not pointing it to anything  
    //cout<<"Node = "<<head->data<<endl;
}

template<class T>
LinkedList<T>::~LinkedList(){
    do{
       temp=head->linkPtr;   //Point to the next link in the list
       delete head;          //Delete the head of the list
       head=temp;            //Swap the head
    }while(head!=NULL);
}

//Function Find the number of links in the list
//Input -> head  The address to the head of the allocated list.
//Output-> The number of links in the list
template<class T>
T LinkedList<T>::getObj(int indx){
    int n=0;                      //Initialize the counter
    temp=head;                   //Set the cursor to the head
    do{
        if(n==indx)return temp->data;
        n++;                      //Increment the counter
        temp=temp->linkPtr;       //Move to the next link
    }while(temp!=NULL);           //Loop until the end is reached
    return head->data;           //Return the counter value
}


//Function Find the number of links in the list
//Input -> head  The address to the head of the allocated list.
//Output-> The number of links in the list
template<class T>
T &LinkedList<T>::getPtr(int indx){
    int n=0;                      //Initialize the counter
    temp=head;                   //Set the cursor to the head
    do{
        if(n==indx)return temp->data;
        n++;                      //Increment the counter
        temp=temp->linkPtr;       //Move to the next link
    }while(temp!=NULL);           //Loop until the end is reached
    return head->data;           //Return the counter value
}
//Function Find the number of links in the list
//Input -> head  The address to the head of the allocated list.
//Output-> The number of links in the list
template<class T>
int LinkedList<T>::cntLst(){
    int n=0;            //Initialize the counter
    temp=head;   //Set the cursor to the head
    do{
        n++;            //Increment the counter
        temp=temp->linkPtr;//Move to the next link
    }while(temp!=NULL); //Loop until the end is reached
    return n;           //Return the counter value
}


//Function Find the address of the link that matches the data
//Input -> head  The address to the head of the allocated list.
//Output-> The Link<Object> address from the head where the data is found
template<class T>
LinkedList<T>::fndLst(const T &value){
    found=head;       //Set the cursor to move through the list
    do{
        if(found->data==value)return found;  //Address of data match
        found=found->linkPtr;                //Next link in the list
    }while(found!=NULL);                    //End of the list
    found=NULL;                           //Not found
}

/******************************************************************************/
//                        Pull/pop a link from the head
//https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/?ref=lbp
/******************************************************************************/
template<class T>
int LinkedList<T>::popFrnt(){   
    
    int index0 = head->data;// set with the first element in head   
    if (head) {
        Link *newHead = head->linkPtr; // Store 2nd node as new head
        //if (newHead) { // for doubly linked list
            //newHead->prev = nullptr;
        //}
        delete head;
        head = newHead;
    }
    return index0;
}


/******************************************************************************/
/*                  Pull/pop a link from the back                             */
/*                                                                            */
//https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
/******************************************************************************/
template<class T>
int LinkedList<T>::popBck(){ 
    int last = 0;    
    // Search for the 2nd to last element in list
    temp = head; // Set temp's address to the oldList's address  
    if (temp) { 
        while(temp->linkPtr->linkPtr != NULL){  

            /* move iterator forward by 1   */      
            temp = temp->linkPtr; //moves to lnk2 after 1st iteration  
        }   
        // if doubly linked list
        //if (tail->prev) {tail->prev->linkPtr = nullptr;
        //} else {head = nullptr;}
        /* Assign NULL to the second last node in the list.  */ 
        last = temp->linkPtr->data;//Set with last number in list
        delete temp->linkPtr; //pointing & deleting last node in list
        temp->linkPtr=NULL;  // set the new tail's pointer to null              
    }
    return last;
}



/******************************************************************************/
/*                     Push a link to the end  
 *          Function Add a link and data to the end of the list                               */
/******************************************************************************/
template<class T>
void LinkedList<T>::pshBack(T &newTailData){ //const int data){   (int newTailData){ 
    
    /*    Find the address of the last link in the list   */
    temp=head; //Declare pointers used to step through the list
    do{              
        //cout<<"node "<<temp->data<<endl;// Print current node        
        // Move iterator forward by     
        tail=temp;          //Point to the current link with a swap
        temp=temp->linkPtr;//Point to the next link
    }while(temp!=NULL);
    //cout<<"Outside Loop. iterator at "<<head->data<<endl;
    Link *add=new Link;        //Create the new link
    add->data=newTailData;            //Add the data
    add->linkPtr=NULL;//Set the pointer to NULL
    tail->linkPtr=add;         //Point to the new end of the list
}


/******************************************************************************/
/*                      Push a link to the head                              */
//                    Like Lehr's addLst but add to head
/*                      Swap old head to new head                             */
//  https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/ 
/******************************************************************************/
template<class T>
void LinkedList<T>::pshFrnt(T &data){ //const int data){     
    //temp=head; //Declare pointers used to step through the list
    Link *add=new Link;        //Create the new link
    add->data=data;            //Add the data
    add->linkPtr=NULL;         //Set the pointer to NULL
    if (!head) {
        head = add;
    } else {
        add->linkPtr = head;
        //head->prev = add; // if doubly linked list
        head = add;
    }
}

template<class T>
void LinkedList<T>::prntLst(){
    next=head;           //Create a pointer to the list
    cout<<"{";
    do{
        cout<<setw(2)<<next->data; //Print the contents of the link
        next=next->linkPtr;     //Go to the next link in the list
        if(next!=NULL){cout<<" ";}
        else {cout<<"}\n";}
    }while(next!=NULL);         //Loop until reaching the end
    
}





/******************************************************************************/
/*                  Pull/pop a link from the back                             */
/*                                                                            */
//https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
/******************************************************************************/
//template<class T>
//Link<int> LinkedList<T>::*popBck(Link<int> *oldList){ 
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
//    //    lnkList->linkPtr->linkPtr=lnk3;   from v1
//    while(temp->linkPtr->linkPtr != NULL){         
//        
//        //cout<<"\titerator on "<<temp->data<<endl;    
//        //cout<<"\tTRUE.  "<<temp->linkPtr->data<<"'s next is NOT NULL"<<endl; 
//       
//        /* move iterator forward by 1   */      
//        temp = temp->linkPtr; //moves to lnk2 after 1st iteration
//        //cout<<"\titerator moved to "<<temp->data<<endl<<endl;
//        
//    }   
//        
//    cout<<"Outside loop.  iterator at "<<temp->data<<endl;   
//    //cout<<"list's second last node is "<<temp->data<<endl<<endl;
//    
//    /* Assign NULL to the second last node in the list.  */ 
//    //cout<<"deleting "<<temp->linkPtr->data<<endl; 
//    delete temp->linkPtr; //pointing & deleting last node in list
//    temp->linkPtr=NULL;
//                
//    return oldList;
//}
#endif /* LINKEDLIST_H */


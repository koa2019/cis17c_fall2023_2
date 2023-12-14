/* File:   LinkedList.h
 * Author: DanYell
 * Created on December 10, 2023, 2:13 AM
 * 
 * Taking my code from LinkedList_5_dblLL and adding it in here.
 * I need to replace simple vector's array with a linked list.
 * 
 * Reference Lehr's midterm>SimpleVectorUsingLinkedList/LinkedList.h
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
            Link *next; //Next Link in the chain. Self Reference which when utilized forms a linked list
        }; 
        // Link *front,*next,*temp,*found;
        
    public:
        LinkedList(); // Default Constructor
        ~LinkedList(); // void destroy(Link<int> *);
        
        Link<int> *fillLst(int);
        void prntLst(Link<int> *);

        Link<int> *create(int);    //Create a Link with Data
        void pshFrnt(Link<int> *,Link<int> *); //Push a link to the front
        void pshBack(Link<int> *,Link<int> *); //Push a link to the end
        void fndPshFrnt(Link<int> *,Link<int> *); //Find and then Push a link to the end
        int popFrnt(Link<int>*);      //Pull/pop a link from the front
        int popFrnt(Link<int>**);      //Pull/pop a link from the front
        int popBack(Link<int>*);      //Pull/pop a link from the back
    
};

//Function Create a linked list and fill with data
//Input  -> n      The number of elements in the list to create
//Output -> front  The address to the front of the allocated list.
template<class T>
LinkedList<T>::LinkedList(const T &data){
    //Link<int> *newLink = new Link<int>;
    newLink->data=num;       //alt way  (*link).data=num;
    newLink->next=NULL;
    //Think of this part as the constructor
    //front=new Link;      //Allocate a link at the front of the list
    //front->data=data;    //Initialize with data
    //front->linkPtr=NULL; //At the moment not pointing it to anything
}


template<class T>
LinkedList<T>::~LinkedList(){
    while(front!=NULL){
        Link<int> *temp=front;
        front=front->next;
        delete temp;        
    }
    lnk9=nullptr;
    lnk6=nullptr;
}
#endif /* LINKEDLIST_H */


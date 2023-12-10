/*
    Author: Danielle
    Date:   10-22-23 @10PM
    Purpose:Linked from first principles
 */

#ifndef LINK_H
#define LINK_H
using namespace std;   //Library Name-space


//Composition of a Link
template<class T>
struct Link{
    T data;		//Any integer data, to be changed any class with templates later 
    Link *lnkNext; //Next Link in the chain. Self Reference which when utilized forms a linked list
};

#endif /* LINK_H */


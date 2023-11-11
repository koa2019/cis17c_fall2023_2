#include "ChoicesTemplate.h"
#include "Choices.h"   
#include <cstring>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <new> //bad_alloc exception
#include <cstdlib> //exit()
using namespace std; 

//Default constructor
template<class T>
ChoicesTemplate<T>::ChoicesTemplate() {   
    size =10;
    board=0;
    index=0;
}

//Constructor #2
template<class T>
ChoicesTemplate<T>::ChoicesTemplate(int s) {

    size = (s<2 && s>100) ? 20 : s;
    
    try {
        board = new T[size];
        indx = new int[size];
        
    } catch(bad_alloc){
        memError();
    }
    
    //Initialize both arrays 
    for(int i=0; i<size; i++) {        
        board[i]=rand()%26+96; // rand() lowercase letters from alphabet            
        indx[i] = i;
    }
    //setBoard();
}

//set array
template<class T>
void ChoicesTemplate<T>::setBoard(){
    //reinitialize both pointer arrays 
    for(int shuffle=0;shuffle<2; shuffle++){ //randomized values 2xs
        for(int i=0; i<size; i++) {
            board[i] = bChoice[rand()%SIZE17]; // fills with S=ship or B=blank
            indx[i] = i;
        }
    }
}

//Copy constructor
template<class T>
ChoicesTemplate<T>::ChoicesTemplate(const ChoicesTemplate &obj){
    size=obj.size;
    
    board = new T[size];
    indx = new T[size];
    
    if(board==0) { 
        memError();
    }
    
    for(int i=0; i<size; i++) {
            *(board+i) = *(obj.board+i); // fills with S=ship or B=blank
            *(indx+i) = i;
        }
}
    
//Destructor
template<class T>
ChoicesTemplate<T>::~ChoicesTemplate() {
    if(size>0) {
        delete [] board;
        delete [] indx;
    }
    //board=nullptr;
    //indx=nullptr;
}

template<class T>
void ChoicesTemplate<T>::memError(){
    cout<<"Error. Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}
    
template<class T>
void ChoicesTemplate<T>::subError(){
    cout<<"Error Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

template<class T>
T ChoicesTemplate<T>::get1BrdElmnt(int sub) const {
    if(sub<0 || sub >= size){subError();}
    return board[sub];
}

template<class T>
T ChoicesTemplate<T>::get1IndxElmnt(int sub) const {
    if(sub<0 || sub >= size){subError();}
    return indx[sub];
}

//***********************************************************
// overloaded [] operator bounds checking
//***********************************************************
template<class T>
T &ChoicesTemplate<T>::operator[](const int &sub){
    if(sub<0 || sub >= size){subError();}
    return board[sub];
    
}

// Prints game board
template<class T>
void ChoicesTemplate<T>::printBoard() const {
    cout << "\tGame Board.  S==Ship.\n";
    for(int i=0; i<getSize() ; i++) {
        cout<<setw(3)<< i;
    }
    cout<<endl;
    for(int i=0; i<getSize(); i++) {
        cout<<setw(3)<<get1BrdElmnt(i);       
    }
    cout<<endl<<endl;
}
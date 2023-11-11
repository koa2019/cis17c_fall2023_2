/*File:   ChoicesTemplate.h
 * Author: DanYell
 * Created on December 18, 2022, 6:45 PM
 */

#ifndef CHOICESTEMPLATE_H
#define CHOICESTEMPLATE_H
#include <new> //bad_alloc exception
#include <cstdlib> //exit()
#include <vector>
using namespace std;  //STD Name-space where Library is compiled

template <class T>
class ChoicesTemplate {
    
private:
    int size;
    T *board; // pointer to char array
    T *indx; //Index used in sorting the array
    char bChoice[18] = "S-Ss-Ss--S-S--Ss-"; // S=ship  B=blank
    void memError();    //bad memory allocation
    void subError();    //subscripts out of range
    
public:
    const int SIZE17 = 17; // # of characters in choices array   
    ChoicesTemplate();      //Default constructor
    ChoicesTemplate(int s); //Constructor #2
    
    //Copy constructor
    ChoicesTemplate(const ChoicesTemplate&);
    
    //Destructor
    ~ChoicesTemplate();
    
    //Mutator function
    void setBoard();
    
    // Accessor function  
    int getSize() const {return size;}
    T get1BrdElmnt(int) const;
    T get1IndxElmnt(int) const;
    T *getBoard() const {return board;}
    int *getIndx() const {return indx;}
    void printBoard() const;
    T &operator[](const int &);
};


#endif /* CHOICESTEMPLATE_H */


/* File:   Board.h
 * Author: DanYell
 * Created on December 16, 2022, 10:15 PM
*/
#ifndef BOARD_H
#define BOARD_H
#include <bits/stdc++.h>
using namespace std;  //STD Name-space where Library is compiled
class Board {
protected:
    int size;
    int nShips;
    deque<string> ships; // nShips and their names
    int *indx; //Index used in sorting the array
    char *board; // pointer to char array
    char bChoice[18] = "S-Ss-Ss--S-S--Ss-"; // S=ship  B=blank

public:
    const int SIZE17 = 17; // # of characters in choices array   
    Board();      //Default constructor
    Board(int s); //Constructor #2
    Board(const Board &);//copy constructor
    ~Board();//Destructor
    
    //Mutator function
    void setBoard();    
    
    // Accessor function    
    int  getBrdSize() const {return size;}
    char get1BrdElmnt(int i)const {return board[i];}
    char *getBoard() const {return board;}
    int  *getIndx() const {return indx;}
    void printBoard() const;     
    void setShips();                 // Set deque with nShips and their names
    void prntDeq(deque<string>&);    // Print ships
    void prntDeqRev(deque<string> &);// Print reverse ships
    void prntQue(queue<string> &);
};
#endif /* BOARD_H */


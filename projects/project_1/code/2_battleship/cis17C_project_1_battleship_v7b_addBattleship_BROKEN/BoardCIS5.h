/* File:   Board.h
 * Author: DanYell
 * Created on November 15, 2023, 9:55 PM *  
 *  cis17c_v7
*/
#ifndef BOARD_H
#define BOARD_H
#include <bits/stdc++.h> 
using namespace std;
const int ROWS = 3;
const int COLS = 9;   // number of cols in 2D array

class Board { 
public:
    bool isP1Turn;
    string plyrName;
    int round;  // Identifies which round player is currently in
    int  guessIndx;// Holds the player's guess
    int  numShps;  // number of ships player has on their board. Need at least 3 ships
    char board[ROWS][COLS]={};    
    //bool isSelected[NUM_CATGRY]; // Stops categories from being overwritten or displayed twice
    //int scores[NUM_CATGRY];     // points for each of 13 categories in scorecard
    //vector<int> selected;  // Create vector for the dice we're keeping for final points

    Board(); // Default Constructor
	//virtual ~Board();
    void fillGameBrd();// Read in file and initialize each player's game board
    void fllGArr();
    void fileSum();// confirm data that was read in is even and contains at least 3 ships
    //void askQQ(char &);// ask if they want to check their board against opponent's
    void confrmGuesBrd(); // confirms guess[][] filled correctly for both players
    void showGuess(int,int);// show each players guess 
    void prntBrd(char arr[][COLS]); //prints 2D	 remove in class
    void plyrBrd(int a,int b);
    void OppntBrd(int a,int b);// Print oppentent's board

    // Mutators
    //void recordScore(int category, int score); //category on scorecard
    void fillBoard();
    void get_isSelected() const; 
    void setFinalSC(Board &);
    void setRound(int r){round=r;}
    void setPName(string name){plyrName=name;}
    
    // Accessors
    void printBoard() const;
    void printFinalSC(string name="Player"); 
};
#endif /* BOARD_H */


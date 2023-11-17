/* File:   Board.h
 * Author: DanYell
 * Created on November 15, 2023, 9:55 PM
 *  
 *  cis17c_v7
*/
#ifndef BOARD_H
#define BOARD_H
#include <bits/stdc++.h> 
using namespace std;
//const int NUM_CATGRY=13;
const int ROWS = 3;
const int COLS = 9;   // number of cols in 2D array

class Board {    
//protected:
public:
    bool isP1Turn;
    string plyrName[2];
    int  p1GShps,
         p2GShps,
         numShp1, 
         numShp2, 
         count1, 
         count2;
    char board1[ROWS][COLS]={};
//    char board2[ROWS][COLS]={};
    char guessP1[ROWS][COLS]={};
//    char guessP2[ROWS][COLS]={};
    
    int round;         // Identifies which round player is currently in
    //bool isSelected[NUM_CATGRY]; // Stops categories from being overwritten or displayed twice
    //int scores[NUM_CATGRY];     // points for each of 13 categories in scorecard
    //int upperScore;   // Holds total points for upper scorecard section
    //int lowerScore;   // Holds total points for lower scorecard section
    //Dice dice[NUM_DICE];  // Aggregates instance of Dice Class
    //int diceArr[NUM_DICE]; // ? Are we using this cuz we have a local one in play() or do we need to connect it with local in play()
    //vector<int> selected;  // Create vector for the dice we're keeping for final points
    
//public:
    
    Board(); // Default Constructor
    void fillGameBrd();// Read in file and initialize each player's game board
    void fllGArr();
    void fileSum();// confirm data that was read in is even and contains at least 3 ships
    //void askQQ(char &);// ask if they want to check their board against opponent's
    void confrmGuesBrd(); // confirms guess[][] filled correctly for both players
    void showGuess(int,int);// show each players guess 
    void prntBrd(char arr[][COLS]); //prints 2D
    void plyrOppBrds(int a,int b);

    // Mutators
    //void recordScore(int category, int score); //category on scorecard
    void fillBoard();
    void get_isSelected() const;    
    //int  getTotalScore();
    //void getUpLowSums();
    void setFinalSC(Board &);
    void setRound(int r){round=r;}
    //void setDice(); 
    //void pushThisDice(int choice){  selected.push_back(choice - 1); }
    
    // Accessors
    void printBoard() const;
    void printFinalSC(string name="Player");
    //void printDice(Dice []) const;
    //int getDiceVal(int choice){ return dice[choice - 1].getValue(); }    
};
#endif /* BOARD_H */


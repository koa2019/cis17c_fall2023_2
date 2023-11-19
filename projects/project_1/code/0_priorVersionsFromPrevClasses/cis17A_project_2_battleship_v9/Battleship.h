/* File:   Battleship.h
 * Author: Danielle
 * Created: November 17, 2023, 1:16 AM
 * Purpose: Add this class to cis17c_project_1
 * Bug: Protected & public keywords aren't diff color
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "Player.h" 
#include <bits/stdc++.h>
using namespace std;
    // Global constants for Yahtzee Class
    enum nums {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN};
    const int MINSIZE  = 2;
    const int MAXRND   = 13;
    const int MAXROLLS = 3;
    const int SIZE17   = 17; // size of choices array 
    
// Score is derived from Player class. idk what that means. look it up later.
class Battleship{
protected:
    int   ttlGmes;
    int   ttlRnds;
    int   maxGmes;   // number of games
    bool  p1_crrt,     // player 1 correct
          p2_crrt;    // player 2 correct     
    int   MAX;       // max number for rand()       
    int   indx1;      // index for player 1's name
    int   indx2;     // index for player 2's name
    int   nGmsLft;   // number of games left       
    int   round;     // round
    int   numPlay;  // number players
    
    bool p1Winner;        // does user winner and have new high score
    int nPlayer;         // Player inputs how many players
    int *indx; // Keeps track of each player during during the game
    Player **player;   // Aggregates instance of User Class. Array of User's
    

public:   

    Battleship();       //Default constructor 
    Battleship(string);//constructor #2
    Battleship(int);   //constructor #3 for passes maxGmes    
    Battleship(const Battleship &); // Copy constructor    
    ~Battleship(){ 
        cout << "\nHit Battleship Destructor.\n"; 
        //de-allocate dynamic memory
        for (int p=0; p<numPlay; p++) {       
            delete player[p]; //Deletes the Data row by row
        } 
        delete [] player;
        delete [] indx;    
        //player=nullptr;
        //indx=nullptr;
    }
    class NegativeGames {}; //Exception class. Empty class declaration 

    //Mutators    
    void setMaxGmes(int num){maxGmes = num;}
    void setTtlGmes(int); // Set total games with try,catch, throw
    void setTtlRnds(int num){ttlRnds += num;}
    void setScore(int nPly, int gmes, int tGmes, int tRnds) {
        setMaxGmes(gmes);
        setTtlGmes(tGmes);
        setTtlRnds(tRnds);
    }
    bool play(int,int);  //returns if player's guess was correct or not
    bool start();
   
    
    //Accessors   
    int getMaxGmes()const {return maxGmes; }//Change to max hits & move to Player
    int getTtlGmes()const {return ttlGmes;}
    int getTtlRnds()const {return ttlRnds;}
    void rBanner();// print round banner   
    void prntScore(); // prints Score structure 
    void getBanner(string); // print banner
    void hitMiss(int &guess, char &i, bool isHit); // print message after each player guesses
    void prntP1P2Brd();
    void pause();// pauses game to allow user to view results before proceeding
};
#endif /* BATTLESHIP_H */


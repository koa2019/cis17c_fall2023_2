/* File:   Battleship.h
 * Author: Danielle
 * Created on November 15, 2023, 9:25 PM
*/

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "User.h"       // aggregates User class
#include "BoardCIS5.h"

// Global constants for Yahtzee Class
const int MINPLAYRS = 2;
const int MAXHITS = 3;
const int MAXSHIPS = 3;

class Battleship {
    
private:
        
    bool p1Winner;        // does user winner and have new high score
    int nPlayer;         // Player inputs how many players
    int *indx = nullptr; // Keeps track of each player during during the game
    User **player = nullptr;   // Aggregates instance of User Class. Array of User's
    Board guesBrd[MINPLAYRS];//replacing Yahtzee::scorecard[MINPLAYRS]
    Board board[MINPLAYRS];//replacing Yahtzee::finalSC[MINPLAYRS]
    //ScoreCard scorecard[MINPLAYRS];   // Aggregates instance of ScoreCard class
    //ScoreCard finalSC[MINPLAYRS];     // Aggregates instance of ScoreCard class
      
public:
    
    Battleship(); // Default Constructor
    ~Battleship(){ 
        cout<<"\nHit Battleship Destructor."; 
        delete [] player; 
        delete [] indx; 
    }

    // Mutators
    bool startGame(User &,const long);
    void play(int i,int &rnd);//remove rnd in class
    void setNPlayer();
    //void setP1Winner(Board [], string []);
    //void setP1Winner(ScoreCard [], string []);
    //bool isNewHiScore(User &,const long);
    //void selectDice(int);
    //void selectCategory(int,string,int rnd);//remove rnd in class
    
    // Accessors
    void getRules(); 
    void prntRound(int rnd);//remove rnd in class
    void pause(char ch='c');
    void displayOptions(int &);    
    //void getBrd(int i){ return board[i].prntBrd();}
    //void getGuesBrd(int i){ return guesBrd[i].prntBrd();}
    void prnt2PlyrBrd();
};
#endif /* BATTLESHIP_H */


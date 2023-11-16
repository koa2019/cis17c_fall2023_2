/* File:   Battleship.h
 * Author: Danielle
 * Created on November 15, 2023, 9:25 PM
*/

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "Dice.h"         // aggregates Dice class
#include "ScoreCard.h"   // aggregates ScoreCard class
#include "User.h"       // aggregates User class

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
    ScoreCard scorecard[MINPLAYRS];   // Aggregates instance of ScoreCard class
    ScoreCard finalSC[MINPLAYRS];     // Aggregates instance of ScoreCard class
      
public:
    
    Battleship(); // Default Constructor
    ~Battleship(){ 
        cout<<"\nHit Battleship Destructor."; 
        delete [] player; 
        delete [] indx; 
    }

    // Mutators
    bool startGame(User &,const long);
    void play(int i,int &);
    void setNPlayer();
    void setP1Winner(ScoreCard [], string []);
    bool isNewHiScore(User &,const long);
    void selectDice(int);
    void selectCategory(int,string,int);
    
    // Accessors
    void getRules(); 
    void prntRound(int);
    void pause(char ch='c');
    void displayOptions(int &);    
};
#endif /* BATTLESHIP_H */


/* File:   Player.h
 * Author: DanYell
 * Created on December 16, 2022, 10:37 PM
 * Player Class specifications
*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"  //Player aggregates and uses an instance of Board class
#include <bits/stdc++.h>
using namespace std;
class Player {
protected:
   
    //int fnSize=7;
    string fNames[7] = {"mom", "bart", "homer", "jillian", "ting", "victor", "cora"};
    string name; //char *name;     //player's name
    bool isRight;   //player's guess is correct or not
    int numWins;    //a player's number of wins
    int guess;     //guessing index of opponent's ship on game board
    int brdSize;    //game board size 20    
    //Board gameBrd; //Player will aggregate an instances of Board class
    Board gboard; //Player will aggregate an instances of Board class
    //char **guessArr; // player's guesses  --> guessP1[ROWS][COLS]={};   
 
public:    
    Player();        //Default constructor
    Player(string); //constructor #2    
    virtual ~Player(){cout<<"\nHit Player Destructor.\n";} //Destructor   
    
    // Setters
    //void setName(string str){ name = str; namSiz = name.size();} 
    string set2Upper(string); // convert string to all uppercase letters
    
    //Mutators
    //void setNumPlayrs(int num){nPlayrs=num;}
    void setName();
    void setName(string);//BUG
    void setIsRight(bool b){isRight=b;}
    void setWins(){numWins++;}
    void setWins(int n){numWins=n;}
    void setGuess(int randIndx){guess = randIndx;}//sets player's guess to rand [0,19]
    void setPlayer(int,bool,int,int);    
    
    //Accessors
    void askName();  // get player 1's name using pass by reference
    //int getNumPlayrs() const{return nPlayrs;}
    string getName() const {return name;}
    int getIsRight() const {return isRight;}
    int getNumWins() const {return numWins;}
    int getGuess() const {return guess;}
  
    //calls Board Accessor function
    const char get1gBrdElmnt(int i)const {return gboard.get1BrdElmnt(i);}
    void printGBoard()const; 
    //returns reference to *board
    const char *getGBoard() const {return gboard.getBoard();}
};
#endif /* PLAYER_H */


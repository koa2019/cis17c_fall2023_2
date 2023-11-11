/* File:   Score.h
 * Author: DanYell
 * Created on December 16, 2022, 10:41 PM
 * Bug: Protected & public keywords aren't diff color
 */

#ifndef SCORE_H
#define SCORE_H
using namespace std;
#include "Player.h" 

// Score is derived from Player class
class Score : public Player {
protected:
    int maxGmes;
    int ttlGmes;
    int ttlRnds;

public:
    
    //Exception class. Empty class declaration 
    class NegativeGames {};     
    const int SIZE17 = 17; //size of choices array 
    Score();//Default constructor 
    Score(string);//constructor #2
    Score(int);   //constructor #3 for passes maxGmes    
    Score(const Score &); // Copy constructor

    //Mutators    
    void setMaxGmes(int num) {maxGmes = num;}
    void setTtlGmes(int);
    void setTtlRnds(int num) {ttlRnds += num;}
    void setScore(int nPly, int gmes, int tGmes, int tRnds) {
        setMaxGmes(gmes);
        setTtlGmes(tGmes);
        setTtlRnds(tRnds);
    }

    //Accessors   
    int getMaxGmes()const {return maxGmes; }
    int getTtlGmes()const {return ttlGmes;}
    int getTtlRnds()const {return ttlRnds;}
    void prntScore()const; // prints Score structure 
    void getBanner(string); // print banner
    void hitMiss(int &guess, char &i, bool isHit); // print message after each player guesses
    //Score *fillScore(string [],char **);    // fill Score structure by playing game  
    //void setBoard(Score *score,char **ptr2D);   // sets 2D pointer with Score structure   
};

#endif /* SCORE_H */


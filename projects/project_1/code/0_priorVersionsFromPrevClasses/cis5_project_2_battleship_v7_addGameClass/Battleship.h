/* File:   Battleship.h
 * Author: Danielle
 * Created on November 15, 2023, 9:23 PM
 */
#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "Board.h"
#include <bits/stdc++.h> 
using namespace std;

const int MIN = 1; // minimum number for rand()
const int MAX = 16; // maximum number for rand()
const int SIZE7 = 7; // size for player 2 names array
const int SIZE8 = 8;

class Battleship {
protected:
    Board board; // Aggregate instance of Board class 
    char ans; // answer  
    char ch;
    char p1Guess; // player 1 guess
    char p2Guess; // player 2 guess
    char p1Ship1; // player 1 ship number 1
    char p2Ship1; // player 2 ship number 1
    bool p1_crrt; // player 1 correct
    bool p2_crrt; // player 2 correct
    bool ready; // ready to continue playing
    bool isHit;
    int rowIndx; // index for comparing player's guess to their opponent's board
    int colIndx; // index for comparing player's guess to their opponent's board 
    int maxGms; // number of games
    int round; // round   Board.h              
    int p1Win; // number of wins player 1 has
    int p2Win; // number of wins player 2 has
    int ttlGmes; // sum of both players number of wins
    int ttlRnds; // sum of total rounds played
    int winner;
    float avgRnds; // average rounds it takes to win
    string p1Name;
    string p2Name;
public:

    Battleship();
    //~Battleship(){cout<<"Hit Battleship Destructor.\n";
    //    bool isReady(char);   // returns bool value
    //    void askQQ(char &);// ask if they want to check their board against opponent's
    //    void swap1(string &,string &);
    //    void topPlyrs(string [],int,string [],int,string,vector<string> &);
    //    void upper(string &); // changes string to all uppercase letters
    //    void getName(string &);  // get player 1's name using pass by reference
    //    void copyAdd(string [],const int,string[],const int,string);
        string pickP2(string [],int);  // randomly picks a number for player 2
    //    int  binarySrch(string [],string &,int);
    //    void sortSel(vector<string> &);
    //    void sortBub(string [],int);       // sort names
    //    void runMenu(string, char &, char &, int,int,int,int,char [][9],char [][9],
    //                 char [][9],char [][9],int,int,int,int,int &,int&,string [],int,
    //                 string [],int,vector<string> &);
    //    void showStatic();
        void banner(string);      // display game 
    //    void hitMiss(bool,int,int);  // hit message for correct guess
    //    void hitMiss();        // try again message
    //    void instruc(string, const int, int =1); // instructions for players
    //    void scoresMsg(int,int,float);  // displays scores for both players
    //    void prntArr(string []);  // prints names[]
    //    void rBanner(int &);      // display the round number
    //    void sBanner(string,string,string,int,int);   // display scoreboard banner
        void pause();
};
#endif /* BATTLESHIP_H */


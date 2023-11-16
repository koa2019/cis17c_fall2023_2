/* File:   main.cpp
 * Author: Danielle 
 * Created: 11-15-23 9:18 PM
 * Purpose: cis5_project_2_battleship_v7
 * 
 * Version 7: 
 * Create Game class and move everything from main() to Game class.
 * I want to use this version for my CIS 17C project 1.
 * I'm using my Yahtzee class from cis17b_yahtzee_v29_presentation as 
 * a model.
 */

// System Libraries: 
#include <bits/stdc++.h> 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand(), EXIT_SUCCESS
#include <fstream>  // ofstream 
#include <cstring>  // string library
#include <ctime>    // time library for rand()
#include <cctype>   // toupper()
#include <vector>   // vector
using namespace std;

// User libraries
#include "Battleship.h"


// Global Constants
// Physics/Chemistry/Math/Conversions


// Function prototypes

//bool isReady(char);   // returns bool value
//void swap1(string &,string &);
//void topPlyrs(string [],int,string [],int,string,vector<string> &);
//void upper(string &); // changes string to all uppercase letters
//void getName(string &);  // get player 1's name using pass by reference
//void copyAdd(string [],const int,string[],const int,string);
//string pickP2(string [],int);  // randomly picks a number for player 2
//int  binarySrch(string [],string &,int);
//void sortSel(vector<string> &);
//void sortBub(string [],int);       // sort names
//void runMenu(string, char &, char &, int,int,int,int,char [][9],char [][9],
//             char [][9],char [][9],int,int,int,int,int &,int&,string [],int,
//             string [],int,vector<string> &);
//void showStatic();
//void banner(string);      // display game 
//void hitMiss(bool,int,int);  // hit message for correct guess
//void hitMiss();        // try again message
//void instruc(string, const int, int =1); // instructions for players
//void scoresMsg(int,int,float);  // displays scores for both players
//void prntArr(string []);  // prints names[]
//void rBanner(int &);      // display the round number
//void sBanner(string,string,string,int,int);   // display scoreboard banner
//void pause();

// *****Functions that I've moved to Board class *****
//void showGuess(int,int);// show each players guess 
//// Prints board and guess board
//void print2DArr(const char [][9],const char [][9],
//                const char [][9],const char [][9],const int,const int,int &,int &);
//void askQQ(char &);// ask if they want to check their board against opponent's
//void fileSum(int,int,int,int);// confirm data that was read in is even and contains at least 3 ships
//void fllGArr(char [][9],char [][9],char [], int, int, int &, int&);
//// confirms guess[][] filled correctly  
//void confrmGuesBrd(const char [][9], const char [][9],const int,const int,int, int);           
//void prntArr(const char [][9],int,int); //prints 2D
//void plyrShpBrd(int,int,const char [][9],const char [][9],const int,const int);
//void prntGuesBrd(int player,const char guess[][9],const int ROWS,const int COLS);
//void prntOppBrd(int opponnt,const char board[][9],const int ROWS,const int COLS);


// Program execution begins here
int main(int argc, char** argv) {

     
    // set random number seed
    srand(static_cast<unsigned int>(time(0)));

    Battleship game;  

    // exit code
    return 0;
}

/* File:   Game.h
 * Author: Danielle
 * Created on November 13, 2023, 10:40 PM
*/
#ifndef GAME_H
#define GAME_H
#include <bits/stdc++.h> 
using namespace std;  //STD Name-space where Library is compiled
//#include "User.h"       // aggregates User class

// Global constants for Yahtzee Class
const int MINSIZE = 2;
const int MAXRND = 13;
const int MAXROLLS = 3;

class Game {    
protected: 
    
    int size;
    deque<int> indx;
    string name; 
    string name2;
    unsigned short namSiz;  // length of name string
    int nShips;
    deque<string> ships;
    unordered_set<string> fnames;
    int fnSize;
    stack<string> stack;
    std::map<string,float> topPlyrs; 
      
public:   
    
    Game();//Default Constructor
    virtual~Game(){cout<<"\nHit Game Destructor\n";}    
    
    // Setters
    void setName(string str){ name = str; namSiz = name.size();}    
    string set2Upper(string); // convert string to all uppercase letters
    string getName();  // get player 1's name using pass by reference
    void setSet(); //unordered_set<string> 
    void setShips();//queue<string>&);
    void setStack(list<string>&);//(stack<string>&, list<string>&);
    void fillGuess(); //fill board with set<char> 
    void setDeqWthSize();//creates container filled [0,size]
    
    // Getters
    void start();
    string getMin();//returns min name
    void setTopPlyrs();//map<string,float>&);
    void getTopPlyrs();//map<string,float>&);
    void prntDeq(deque<string>&);
    void prntDeqRev(deque<string> &);
    void prntMap(map<string, float>&);// Prints player's hiScore
    void prntListFlt(list<float>&); // Scores
    void prntListStr(list<string>&); // first names 
    void prntQue(queue<string> &);
    void prntSetStr(unordered_set<string>&);// Prints a set of names   
    void prntStckFIFO();//stack<string>&);
    void prntStckRev();//stack<string>&);
    void shuffleThis();//shuffles list fnames
    void shuffleThis(deque<int>&);//shuffles int, char, string array BUT not a set container
    void pause();
};
#endif /* GAME_H */


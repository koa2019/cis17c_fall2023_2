/* File:   topPlyrsBrd.h
 * Author: Danielle
 * Created on November 19, 2023, 4:17 PM
*/

#ifndef TOPPLYRSBRD_H
#define TOPPLYRSBRD_H
//#include "AVLTree.h"
#include <bits/stdc++.h> 
using namespace std;  //STD Name-space where Library is compiled
class TopPlyrsBrd {    
protected: 
    
    //AVLTree avl; //Breaks it
    // deque member variables
    int deqFltSz;    // size of array.  Used with AVL.h
    deque<float> deqFlt;// index array. Used with AVL.h    
    int deqIntSz;    // size of array
    deque<int> deqIndx;// index array to handle 2+ players 
    
    string name; 
    string name2;
    unsigned short namSiz;  // length of name string
    unordered_set<string> fnames;
    int fnSize;
    stack<string> stack;
    std::map<string,float> topPlyrs;     
      
public:   
    
    TopPlyrsBrd();//Default Constructor
    virtual ~TopPlyrsBrd(){cout<<"\nHit TopPlyrsBrd Destructor";} 
    void run();
    
    // deque member functions
    void setDeqInt(); // sets an index container
    void prntDeqInt();// prints index container
    void shuffleThis(deque<int>&);//shuffles int, char, string array BUT not a set container  
    void setDeqFlt(); // sets container of floats
    void prntDeqFlt();// prints container of floats
    void shuffleThis(deque<float>&);//shuffles int, char, string array BUT not a set container
    
    
    // Setters
    void setName(string str){ name = str; namSiz = name.size();}    
    string set2Upper(string); // convert string to all uppercase letters
    string askName();  // get player 1's name using pass by reference
    void setSet(); //unordered_set<string>     
    void setStack(list<string>&);//(stack<string>&, list<string>&);
    void fillGuess(); //fill board with set<char> 
    void setDeqWthSize();//creates container filled [0,deqSize]
    void setTopPlyrs();//map<string,float>&);
    
    // Getters    
    string getMin();//returns min name
    void getTopPlyrs();//map<string,float>&);    
    void prntMap(map<string, float>&);// Prints player's hiScore
    void prntListFlt(list<float>&); // Scores
    void prntListStr(list<string>&); // first names 
    void prntQue(queue<string> &);
    void prntSetStr(unordered_set<string>&);// Prints a set of names   
    void prntStckFIFO();//stack<string>&);
    void prntStckRev();//stack<string>&);
    void shuffleThis();//shuffles list fnames
    void pause();    
};
#endif /* TOPPLYRSBRD_H */


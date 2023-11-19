/*File:   MySTL.h
 * Author: Danielle*
 * Created on November 15, 2023, 7:32 PM
 */
#ifndef MYSTL_H
#define MYSTL_H
#include <bits/stdc++.h> 
using namespace std;  //STD Name-space where Library is compiled
class MySTL {    
protected: 
    
    int size;//x
    deque<int> indx;//x
    string name; //x
    string name2;
    unsigned short namSiz;  // length of name string
    int nShips;//x
    deque<string> ships;//x
    unordered_set<string> fnames;
    int fnSize;
    stack<string> stack;
    std::map<string,float> topPlyrs; 
      
public:   
    
    MySTL();//Default Constructor
    virtual~MySTL(){cout<<"\nHit MySTL Destructor\n";}    
    
    // Setters
    void setName(string str){ name = str; namSiz = name.size();}    
    string set2Upper(string); // convert string to all uppercase letters
    string askName();  // get player 1's name using pass by reference
    void setShips();//X Board. queue<string>&);
    
    void setSet(); //unordered_set<string> 
    void setStack(list<string>&);//(stack<string>&, list<string>&);
    void fillGuess(); //fill board with set<char> 
    void setDeqWthSize();//creates container filled [0,size]
    
    // Getters
    void start();
    string getMin();//returns min name
    void setTopPlyrs();//map<string,float>&);
    void getTopPlyrs();//map<string,float>&);
    void prntDeq(deque<string>&);// X
    void prntDeqRev(deque<string> &);//X
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
#endif /* MYSTL_H */


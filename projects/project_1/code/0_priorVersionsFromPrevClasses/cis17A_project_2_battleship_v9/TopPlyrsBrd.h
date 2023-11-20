/* File:   topPlyrsBrd.h
 * Author: Danielle
 * Created on November 19, 2023, 4:17 PM
*/

#ifndef TOPPLYRSBRD_H
#define TOPPLYRSBRD_H
#include <bits/stdc++.h> 
using namespace std;  //STD Name-space where Library is compiled
class TopPlyrsBrd {    
protected: 
    int deqSize;
    deque<int> indx;
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
    void shuffleThis(deque<int>&);//shuffles int, char, string array BUT not a set container
    void pause();    
};
#endif /* TOPPLYRSBRD_H */


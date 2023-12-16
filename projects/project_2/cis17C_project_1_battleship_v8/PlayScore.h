/* File:   PlayScore.h
 * Author: DanYell
 * Created on December 18, 2022, 4:28 PM
 */

#ifndef PLAYSCORE_H
#define PLAYSCORE_H
#include <string>
#include "HighScores.h" //forward class declaration
using namespace std;  //STD Name-space where Library is compiled

class HighScores;//forward class declaration

class PlayScore {    
protected:
    static int nPlayScore;
    string fname="";
private:
    float prizeMoney;
    
public:
    PlayScore(){// Default Constructor
        fname="First name";
        prizeMoney=0;
        nPlayScore++;// increment static member count
        //cout<<"Static member PlayScore::nPlayScore = "<<getStatic()<<endl;         
    }
    
    PlayScore(string s){//Constructor #2
        fname=s;
        prizeMoney=0;
        nPlayScore++;// increment static member count
        //cout<<"Static member PlayScore::nPlayScore = "<<getStatic()<<endl; 
    }
    PlayScore(string s, float money){//Constructor #3
        fname=s;
        prizeMoney=money;
        nPlayScore++;// increment static member count
        //cout<<"Static member PlayScore::nPlayScore = "<<getStatic()<<endl; 
    }
    //Copy constructor
    PlayScore(const PlayScore &obj){
        fname=obj.fname;
        prizeMoney=obj.prizeMoney;
    }
    
    //Mutators
    void setName(string s){fname=s;}
    void setPSMoney(int num){prizeMoney=num;}
    
    //definition of member function that's a friend of Score class
    void addMoney1(float money){
        prizeMoney+=money;
    };
    void addMoney(float money, HighScores &hscore){
        float temp1 =hscore.getHSMoney();
        prizeMoney+=money;
        temp1 +=money;
        hscore.setHSMony(temp1);
    }
     
    //Accessors
    string getName()const {return fname;}
    float getPSMoney() const {return prizeMoney;}
    int getStatic() const {return nPlayScore;}
};
// Static member
int PlayScore::nPlayScore=0;

#endif /* PLAYSCORE_H */


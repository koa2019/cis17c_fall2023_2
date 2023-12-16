#include "Player.h"
#include <bits/stdc++.h>
#include <fstream>  // fstream 
#include <cmath>    // round()
//#include <iostream>   //Input/Output Library
//#include <iomanip>  // fixed, setprecision()
//#include <cstdlib>  // rand()
//#include <cstring>  // char [] library
//#include <string>   // length() library
//#include <ctime>    // time library for rand()
//#include <cctype>   // toupper()
using namespace std;  //STD Name-space where Library is compiled


//************************************************************
//    Default constructor
//************************************************************
Player::Player() {      
    cout<<"Hit Player Constructor\n";   
    fnSize=fNames.size();
    setName(); //name=set2Upper(fNames[rand()%6]);  
    isRight=false;
    numWins=0;
    guess=0;
    brdSize=20;    
}

//************************************************************
//    Constructor#2
//************************************************************
Player::Player(string nme) {  
    cout<<"Hit Player Constructor #2\n";
    fnSize=fNames.size();
    setName(nme);
    isRight=false;
    numWins=0;
    guess=0;
    brdSize=20;
}

//Player::~Player(){ //Destructor
//    cout<<"\nHit Player Destructor.\n"; 
//    if (strlen(name)>0){
//        delete [] name;            
//    }
//}


/*****************************************************************/
// 		Set player 1's name and convert to uppercase letters
/*****************************************************************/
void Player::askName(){ 
    string str="Danielle";
    cout << "\nPlayer 1: Enter your name\n";
    cin>>str; //change to ostream_iterator
    //cin.ignore();//cout<<str<<" "; //cout << endl; 
    if(str.length()<=0){name="Guest";}
    else{setName(str); } //convert user input into capital letters
}

//************************************************************
//    set member variables in class
//************************************************************ 
void Player::setPlayer(int numPly,bool correct, int num,int gussIndx){
        //setNumPlayrs(numPly);
        setName();
        setIsRight(correct);
        setWins(num);
        setGuess(gussIndx); 
}


//****************************************************************
//      sets a player's name
//****************************************************************
void Player::setName(string temp){
    name=set2Upper(temp);
}
void Player::setName(){
    name=set2Upper(getMin());
}


/*****************************************************************/
// 			Convert string to all uppercase letters
/*****************************************************************/
string Player::set2Upper(string str){ 
    transform(str.begin(), str.end(), str.begin(), ::toupper); 
    return str;
}

//****************************************************************
//           calls Choices Accessor function
//****************************************************************
void Player::printGBoard() const{
    gboard.printBoard();
}

/*****************************************************************/
// Picks a random number [0,fNames.size()-1], moves iterator
/*****************************************************************/
string Player::getMin(){        
    cout<<"\tLocating your opponent...\n";
    unordered_set<string>::iterator itr = fNames.begin();
    unordered_set<string>::iterator end = fNames.begin();
    end++;//itr++;
    int n = fnSize-1;
    int i = 1+(rand()%n);// change this to shuffle
    // Move iterator to this element in container
    std::advance(end, i);//https://stackoverflow.com/questions/20477545/element-at-index-in-a-stdset
    string last = *end;
    //cout<<"n="<<n<<"  fNames["<<i<<"] = "<<last<<endl;
    string min = std::min({*itr, last},
            [](const std::string_view s1, const std::string_view s2)
            {
                return s1.size() < s2.size();
            });
    cout<<"\tmin("<< *itr<<","<<last<<") = "<<min<<"\n\n";
    return min;
}


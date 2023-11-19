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
    //Player score();// create new instances of Score class   
    name=set2Upper(fNames[rand()%6]);
    //setName(fNames[rand()%6]);
    //name=fNames[rand()%6];
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
    //nPlayrs=2;
    setName(nme);
    //name=nme;
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
    //cin.ignore();
    cout<<str<<" ";
    cout << endl; 
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
// BUG  Need to clear the name. BUG when new name is shorter than old name,
//      sets a player's name
//      converts string to char array
//****************************************************************
void Player::setName(string temp){
    name=set2Upper(temp);
    //cout<<"1 Hit setName(string)\n";
    //string nme=set2Upper(temp);    
   
    // loop through the length of name string
    //for (int c=0; c<(temp.length()+1); c++) {        
        //name[c] = nme[c];
    //}
    //cout<<"2 Hit setName(string)\n";
}
//****************************************************************
//      sets 1 player's name randomly.
//      converts string to char array
//****************************************************************
void Player::setName(){
   
    int indx1, // index for player 1's name
        indx2; // index for player 2's name
    int size=sizeof(fNames)/sizeof(fNames[0]);
    
//    // loop through number of players when player's is an array
//    // make sure its 2 different names
//    for (int i=0; i<2; i++) {
//
//        // generate new random name for each player
//        if (i==0) {
            indx1 = rand()%size;           
//            
//        } else { //makes sure the same 2 names are NOT picked from the names array
//
//            do {
//                indx2 = rand()%size; 
//                
//            } while (indx2 = indx1);
//
//            indx1 = indx2; //? resets something
//        }
//
            string str = fNames[indx1];
            transform(str.begin(), str.end(), str.begin(), ::toupper); 
            
        // set player name by creating new char[] the size of string +1
        //player[i].name = new char[fNames[indx1].length() + 1];
        name = new char[str.length() + 1];
        
        // loop through the length of name string
        for (int c=0;c<(str.length()+1); c++) {

            // convert string to c-string and to uppercase. static_cast as char           
            //score->player[i].name[c] = (char) toupper(fNames[indx1].c_str()[c]);           
            name[c] = fNames[indx1].c_str()[c]; 
            //name[c] = (char) toupper(fNames[indx1].c_str()[c]);  
        }     
//    }
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




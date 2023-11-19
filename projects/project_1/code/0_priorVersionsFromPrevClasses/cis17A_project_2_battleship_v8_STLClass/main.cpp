/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-16-2022 @ 10:13 PM
 * Purpose: cis17a_project_2_battleship_v8
 *          I want to use this version for cis17c project 1
 * 
 * version 8:
 * Added STL Class in main and created a menu to allow user
 * to see STL concepts or play Battleship
 * 
 * v_7:
 * Code is based off of cis17A_project2_battleship_v5
 * Adding Battleship class and moving the game from main to a class.


 * To do: cis 17c
 * BUG! Player::setName(string)
 * Player destructor not going off
 * Battleship::prntScore()
 * Player **guessArr
 * revert how player guesses in play(). see cis5 or cis17a prior versions.
 * BUG! in play(). Need to create Guess board with class.
 * maxGames should be maxHits each player can take before losing.
 * Print game board and guess board again. See prior versions.prntScore()
 * look for shipLoc in prior versions
 * 
 *  
* To do: cis17a
 * fix ChoicesTemplate
 * fix bug in Battleship.h Protected & public keywords aren't diff color
 * add 3 ships to each player's profile
 * inherit a HighScore instance
*/

//System Libraries
#include <bits/stdc++.h> 
#include <iostream>   //Input/Output Library
#include <iomanip>  // fixed, setprecision()
#include <cstdlib>  // rand()
#include <cstring>  // char [] library
#include <string>   // length() library
#include <ctime>    // time library for rand()
#include <cctype>   // toupper()
#include <vector>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Battleship.h"
#include "MySTL.h"
//#include "PlayScore.h"  // forward class declaration for HighScores class
//#include "HighScores.h" // is friends with PlayScore class
//#include "ChoicesTemplate.h" // Converted Choices class to a template

//Global Constants not Variables

//Function Prototypes
//void copyConstFriendDemo();//showcase cis 17a project 2 concepts
void menu2();// Run STL concepts or play Battleship with Admin/User features


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int> (time(0)));    
    
    menu2();
    //MySTL mystl; // Run to test MySTL class functions  
    //Battleship game;// create new instances of Battleship class 
    //game.start();
    
    return 0;
}

// ***************Function Implementations************************
void menu2(){
    int choice = 0;
    cout<<"\n\n\tMenu\n"
        <<"1: Run CIS 17C concepts\n"
        <<"2: Play Battleship\n"
        <<"Enter a number: ";;
    cin>>choice;
    cin.ignore();    
    cout<<endl<<endl;
    switch(choice){            
        case 1: { MySTL mystl; break; } 
        default: { Battleship game;}// create new instances of Battleship class
    }
}

 //copyConstFriendDemo();  // Demo cis17a project 2 concepts    
//void copyConstFriendDemo(){
//    //********************************************
//    //Copy Constructor & static member Demo
//    //********************************************
//    PlayScore parent1("Dad");
//    PlayScore parent2("Mom");
//    cout<<"Copy parent1 to parent2\n";
//    cout<<"\nPlayScore class Static member = "<<parent1.getStatic()<<endl;   
//    cout<<"\nParent1: "<<parent1.getName()<<endl;
//    cout<<"Parent2: "<<parent2.getName()<<endl;
//    parent2=parent1;
//    cout<<"Parent1: "<<parent1.getName()<<endl;
//    cout<<"Parent2: "<<parent2.getName()<<endl;    
//     
//    //********************************************
//    //         Friend Class Demo
//    //********************************************
//    HighScores hscore;  
//    cout<<"HighScore Earnings "<<hscore.getHSMoney()<<endl;
//    hscore.setHSMony(200);
//    cout<<"HighScore         +1 = "<<hscore.getHSMoney()<<endl;
//    ++hscore;   //increase money by $1
//    parent1.setPSMoney(50);
//    parent1.addMoney1(55);     
//    cout<<"\n\n   Friend Class Demo:\n"
//        <<"HighScore Earnings "<<hscore.getHSMoney()<<endl         
//        <<"parent1 Earnings   "<<parent1.getPSMoney()<<endl
//        <<setw(18)<<" "<<"+1001\n";
//    parent1.addMoney(1001, hscore); 
//    cout<<"HighScore          "<<hscore.getHSMoney()<<endl          
//        <<"parent1            "<<parent1.getPSMoney()<<endl<<endl;
//    --hscore;   //decrease money by $1
//    --hscore;   //decrease money by $1
//    cout<<"HighScore Earnings "<<hscore.getHSMoney()<<endl;
//    
//    
//    //********************************************
//    //         Choices Template Demo
//    //********************************************
////    cout<<"\tChoices Template\n";
////    ChoicesTemplate<char> tempArr(20);
////    for(int i=0; i<MAX+1; i++) {
////        cout<<setw(3)<<tempArr[i];       
////    }
//     
//    }
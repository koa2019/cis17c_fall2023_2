/* File:    main.cpp
 * Author:  Danielle F
 * Created: 11-19-2023 @ 10:13 PM
 * Purpose: cis17C_project_1_battleship_v8
 * 
 * Code is based off of cis17a_project_2_battleship_v9
 * 
 * version 9:
 * STL Applied to Player.h: 
 * set2Upper() that has transform to Player::setName()
 * askName()
 * getMin()
 * 
 * STL Applied to Player.h:
 * deque<string>, prntDeq(),prntDeqRev()
 * 
 * STL Applied to TopPlyrBrd.h:
 * Copied the top player functions from MySTL 
 * 
 * 
 * Made setter functions  and cleaned up MySTL default contrcutor
 * Created TopPlyrsBrd and copied appropriate MySTL functions 


 * To do: cis 17c
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
#include "TopPlyrsBrd.h"
#include "PlayScore.h"  //rename to PlyrWins forward class declaration for HighScores class
#include "HighScores.h" //rename to HSPrize is friends with PlayScore class
//#include "ChoicesTemplate.h" // Converted Choices class to a template

//Global Constants not Variables

//Function Prototypes
void copyConstFriendDemo();//showcase cis 17a project 2 concepts
void menu2();// Run STL concepts or play Battleship with Admin/User features


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int> (time(0)));    
    
   // menu2();
    //MySTL mystl; // Run to test MySTL class functions  
    Battleship game;// create new instances of Battleship class 
    TopPlyrsBrd topPlyrs;
    // Move this to a PlayScore.cpp
    //copyConstFriendDemo();  // Demo cis17a project 2 concepts    
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
        case 1: { MySTL mystl2; break; } 
        default: { 
            Battleship game2; // create new instances of Battleship class
            TopPlyrsBrd topPlyrs2;
            //copyConstFriendDemo();  // Demo cis17a project 2 concepts 
        }
    }
}

 
void copyConstFriendDemo(){
    //********************************************
    //Copy Constructor & static member Demo
    //********************************************
    cout<<"\n\nCopy Constructor and static member Demo:\n"; 
    cout<<"****************************************\n\n";
    PlayScore parent1("Dad",66.01);
    cout<<"Static PlayScore::nPlayScore = "<<parent1.getStatic()<<endl;   
    PlayScore parent2("Mom");    
    cout<<"Static PlayScore::nPlayScore = "<<parent2.getStatic()<<endl<<endl;    
    cout<<"Copy parent1 to parent2"<<fixed<<setprecision(2);
    cout<<"\nParent1: "<<parent1.getName()<<" "<<parent1.getPSMoney()<<endl;
    cout<<"Parent2: "  <<parent2.getName()<<" "<<parent2.getPSMoney()<<endl;
    parent2=parent1;
    cout<<"Parent1: "<<parent1.getName()<<" "<<parent1.getPSMoney()<<endl;
    cout<<"Parent2: "<<parent2.getName()<<" "<<parent2.getPSMoney()<<endl;    
    cout<<"Static PlayScore::nPlayScore = "<<parent1.getStatic()<<endl<<endl<<endl;
    
    
    //********************************************
    //         Friend Class Demo
    //********************************************
    HighScores hscore;  
    cout<<"Friend Class Demo:\n";
    cout<<"******************\n\n";
    cout<<"HighScore Pot          : "<<setw(5)<<hscore.getHSMoney()<<endl;
    hscore.setHSMony(200);
    cout<<"HighScore +$200        : "<<hscore.getHSMoney()<<endl;
    ++hscore; //increase money by $1
    cout<<"HighScore operator++   : "<<hscore.getHSMoney()<<endl;       
    cout<<parent1.getName()<<" Earnings           : "<<parent1.getPSMoney()<<endl;
    parent1.addMoney1(hscore.getHSMoney());     
    cout<<parent1.getName()<<" + HighScore Pot    : "<<parent1.getPSMoney()<<endl;
    cout<<parent1.getName()<<" +$102 to total prize money\n";
    //Calls friend class function to reset HighScore::totPrzMony
    parent1.addMoney(102, hscore); 
    cout<<"New HighScore Pot      : "<<hscore.getHSMoney()<<endl;
    --hscore;   //decrease money by $1
    cout<<"HighScore operator--   : "<<hscore.getHSMoney()<<endl;    
    cout<<"HighScore Pot          : "<<hscore.getHSMoney()<<endl;
    
    
    //    //********************************************
    //    //         Choices Template Demo
    //    //********************************************
    ////    cout<<"\tChoices Template\n";
    ////    ChoicesTemplate<char> tempArr(20);
    ////    for(int i=0; i<MAX+1; i++) {
    ////        cout<<setw(3)<<tempArr[i];       
    ////    }
    //     
}
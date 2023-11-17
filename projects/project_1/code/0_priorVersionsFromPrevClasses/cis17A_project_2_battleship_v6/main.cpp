/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-16-2022 @ 10:13 PM
 * Purpose:  Adding Battleship class and moving the game from main to a class.
 * I want to use this version for cis17c project 1
 * 
 * cis17A_project2_battleship_v5
 * 
 * v5: 
	Created 3 new classes: HighScores, PlayScore and ChoicesTemplate.
	PlayScore has a static member and prints its value in main().
	PlayScore has a copy constructor that copies parent1 object into parent2 object.
	I attempted to make HighScores a friend of PlayScore but kept getting an error in HighScore that “PlayScore was not declared”. I commented out the code in main.
	I couldn’t convert Choices.h to a template without messing up Player class because it aggregates it. I copied Choices to ChoicesTemplate and ran it as a class with a char pointer array. I converted it to a vector template, but the program kept crashing. I commented out its instances in main().
	Added overloaded operator++ and operator—to HighScore 
	Made a base class call a derived class. Score calls a function of Player

 * To do: cis 17c
 * BUG! Player::setName(string)
 * Player destructor not going off
 * Score::prntScore()
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
 * fix bug in Score.h Protected & public keywords aren't diff color
 * add 3 ships to each player's profile
 * inherit a HighScore instance
*/

//System Libraries
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
//#include "Battleship.h"
#include "Score.h"
//#include "PlayScore.h"  // forward class declaration for HighScores class
//#include "HighScores.h" // is friends with PlayScore class
//#include "ChoicesTemplate.h" // Converted Choices class to a template


//Global Constants not Variables

//Function Prototypes
//void copyConstFriendDemo();//showcase cis 17a project 2 concepts

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int> (time(0)));    

    // Demo cis17a project 2 concepts              
    //copyConstFriendDemo();   
    
    // create new instances of Score class 
    Score score;
    //score.start();
    
    return 0;
}

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
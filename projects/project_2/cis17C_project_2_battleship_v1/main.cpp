/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-15-2023 @ 12 PM
 * Purpose: cis17C_project_2_battleship_v1
 * 
            * Your project should be >750 lines of code with concepts for this month.
            * Extend your project with:
            * recursions, 
            * recursive sorts, 
            * hashing, trees,
            * graphs. 
 
 * Danielle look at comments.txt  
 * 
 * cis17C_project_2_battleship_v1:
 * Implemented trees -> Used AVL to fill and balance a binary tree using deque
    
 * Implemented AVLTree.h in TopPlayers.cpp, but the code broke 
 * when i tried to moved AVLTree avl; declaration to TopPlayers.h
 * 
 * 

*/

//System Libraries
#include <bits/stdc++.h> 
#include <iostream>   //Input/Output Library
#include <iomanip>  // fixed, setprecision()
#include <cstdlib>  // rand()
#include <ctime>    // time library for rand()
#include <cstring>  // char [] library
#include <string>   // length() library
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
    //srand((unsigned int)time(NULL)); 
    srand(static_cast<unsigned int>(time(0)));    
    //rand()%90+10;//2 digit numbers    
    //char ch = 65+(rand()%26); //A-Z[65,90]
    
    
    // menu2();
    //MySTL mystl; // Run to test MySTL class functions  
    //Battleship game;// create new instances of Battleship class 
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
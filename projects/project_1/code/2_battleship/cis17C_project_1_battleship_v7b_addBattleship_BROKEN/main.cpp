/* File:    main.cpp
 * Author:  Danielle F
 * Created: 11-15-23
 * Purpose:  cis17c project 1 v7_ Convert Yahtzee classes to battleship
 * 
 * version 7: 
 * Keep User, Admin classes, BUT model cis5_battleship_v6 like Yahtzee class.
 * cis5_battleship doesn't have any classes, so I need to update it.
 * Need to randomize board because board2 isn't being read in anymore
 * version 6: Combined:
 *                     1. cis17b_yahtzee_v29_presentation
 *                     2. convertArray_to_STL_v8
    
Comments to User:
 * For ease of use, when you login in as a user or admin I have printed  
   their login info to the screen. Type it in when prompted.  
 * If it's your first time running this code, select 5 from the menu
   that runs in main(). This reset's the code by resetting the User's binary file 
   to 5 records. This way you can start with fresh code that I haven't tested on.
 * Yahtzee default construct will always create an array of players with a minimum
   of 2 players. If player choose 1 player, then the code won't show the 2nd
   player's scorecard.
 * Play() accepts a User object from main() and will only alter their hiScore
   if player 1 wins AND has a higher score then user object's hiScore. 
   Player 1 represents the User object that was passed to play().
   It is essential a shell object that allows User to play without
   alter any of their actual values unless they win.
 
 Admin/User To Do:  
 * Make User::readInputFile() read inputs from file again. isStrEqual() returns false. 
 * Add a bool variable to Admin as a flag for deleted records? 
 * DRY. Clean up repetitive code.
 * Have ~User do something other than cout a message. Program fails without it.
 
Yahtzee To Do: 
 * Destroy double ptr in Yahtzee class
 * Simplify getRules() 
 * After all testing is finished change bonusMin to 63 and MAX_ROUNDS to 13.
  
 Ask Lehr:
 * inBin.read(&binEmail[0]  ...better way?
 * Do we need User in yahtzee private members just because a function is passing it
 * How to aggregate a class when u only thing you want to add functions?
 */

//System Libraries
#include <bits/stdc++.h> 
#include <iostream>  //Input/Output Library
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <string>  //string
#include <cstring> //c-strings
#include <cctype> // tolower()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "User.h"
#include "Admin.h"
//#include "Yahtzee.h"// Runs the game as a guest
#include "MySTL.h"
#include "Battleship.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void getUserLogin();
void menu(); // Menu for Admin,User login, play game as a guest
void menu2();// Run STL concepts or play Battleship with Admin/User features
void runBattleship();// If you want to just test the game out, then run this block of code
   
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));    
    //menu2();  
    //menu(); // Menu for Admin,User login, play game as a guest
    MySTL mystl; // Run to test MySTL class functions
    //runBattleship();// If you want to just test the game out, then run this block of code
    
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
        default: { menu(); }
    }
}

// If you want to just test the game out, then run this block of code
void runBattleship(){
    User guest("Ashoka"); 
    cout<<"\ninside main() guest user object looks like: ";
    guest.printUsr();
    Battleship game2;  
    //game2.start();
    //game2.startGame(guest,10);
}

void menu(){
    int choice = 0;
    Admin admin;
    User user;     
    
    cout<<"\n\n\tMenu\n"
        <<"1: Admin Login\n"
        <<"2: Sign Up\n"
        <<"3: User Login\n"
        <<"4: Play Battleship as a guest\n"
        <<"5: Run STL concept functions\n"    
        <<"6: Reset binary and text files (for testing purposes)\n"
        <<"9: Exit\n"
        <<"Enter a number: ";
        cin>>choice;
        cin.ignore();
    
        switch(choice){
            
            case 1: // Admin login
            {               
                admin.adminLogin();
                break;
            } 
            case 2: // User sign up for new account
            {
               
                user.signUp();
                //cout<<"\ninside main() after signUp() object looks like: ";
                //user.printUsr();
                break;
            }
            case 3:  // User login. If successful, then play game          
            {      
                getUserLogin();                
                break;
            }             
            case 4: // Play Yahtzee as a guest
            {          
                User guest("Clone Trooper66"); 
                cout<<"\ninside main() guest user object looks like: ";
                guest.printUsr();
                Battleship game4;   
                //game4.start();
                //game4.startGame(guest,0);
                break;
            }
            case 5: // Run to showcase MySTL class functions
            { 
                MySTL mystl; 
            }
            case 6:   // Reset files by erasing binary & text file, then creates records in 
            {        // User binary with records. Use after testing & altering records.    
                user.readInputFile(); 
                break;
            }
            default: 
            {
                cout<<"\nGood Bye.\n";                
                exit(0);
            }
        }
}
void getUserLogin(){
    
    Admin admin;
    User user;
    
    int indx = admin.isUsrLogin();
    
    if(!(indx == -66)){

        cout<<"\n\nUser login was successful.\n"; 
        cout<<"\ninside main() admin1 object looks like: ";
        admin.printAdUsr(indx);                    


        // Create new User & copy admin values to user                    
        admin.copy2Usr(user,indx);    
        cout << "\nWelcome " << user.getName();
        user.printUsr(); 

        // Create new instance of Yahtzee class
        Battleship game1;

        long recordLoc = admin.getBegnFile(indx);

        if(recordLoc<0){ cout << "\nError finding record location\n"; return; }

        //Uncomment this after you connect User to Battleship
//        // if user is winner & has new hiScore, then print their update record
//        if(game1.startGame(user, recordLoc)) {                         
//
//            //cout<<"\n\ninside main() user object looks like: ";
//            //user.printUsr();                       
//
//            admin.readBin_setArray();
//            cout << "\nAdmin is reading updated binary file....\n";
//            admin.printAdUsr(user.getNumRec());   
//        }                                                    
    }
}
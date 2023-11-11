/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 10-28-2022 @ 4 PM
 * Purpose: CIS 17A Project 1. Covers chapters 9-12 in Tony Gaddis. Battleship v1
 Version 3: 
 Changed Player.name to a char[] instead of string for binary files.
 Created fillScore() to dynamically create and fill Score and Player structures.
 The function randomly selects a player's name from a static array and initializes
 .name member.
 Added enum and used it inside of for loops
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand()
#include <fstream>  // ofstream 
#include <cstring>  // char [] library
#include <string>   // length() library
#include <ctime>    // time library for rand()
#include <cctype>   // toupper()
#include <vector>   // vector
using namespace std;


// Global Constants
// Physics/Chemistry/Math/Conversions
const int COLS = 9; // number of cols in 2D array


enum day {
    MON, TUE, WED, THUR, FRI, SAT, SUN
};


//    char    board1[ROWS][COLS]={};    //look at github how to fill class>randomDyn2DArr
//    char    guessP1[ROWS][COLS]={};    

// User libraries
struct Player {
   
    char *name;
    int numWins;
    int shipLoc; // ship's location on game board
    char **board1; // player's game board 
    char **guessP1; // player's guesses
};

struct Score {
    int nPlayrs;
    int ttlRnds;
    Player *player;
};

// Function prototypes
Score *fillScore(string [], int);
void print(Score *);
void pause();
void banner(Score *, string);
void rBanner(int *);
void hitMiss(Score *, int, bool, int);

int main(int argc, char** argv) {// Program execution begins here

    // set random number seed
    srand(static_cast<unsigned int> (time(0)));

    // declare variables
    ifstream inFile; // for reading an existing file
    ofstream outFile; // for outputting to a file

    const int MIN = 1, // minimum number for rand()
            MAX = 14, // maximum number for rand()
            SIZE7 = 7,
            SIZE17 = 17, //choices array
            ROWS = 3;
    bool p1_crrt, // player 1 correct
            p2_crrt, // player 2 correct
            isHit; //which player's ship that was hit

    int indx1,
            indx2,
            maxGmes = 5, // number of games
            nGmsLft, // number of games left       
            round = 1, // round
            p1Guess, // player 1 guess
            p2Guess, // player 2 guess                
            p1Win = 0, // counter for player 1 wins
            p2Win = 0, // counter for player 2 wins
            ttlGmes = 0, // sum of both players number of wins
            ttlRnds = 0, // sum of total rounds played
            nPlayrs = 2, // number of players for players array                 
            shipHit;

    string names[SIZE7] = {"mom", "bart", "homer", "jillian", "ting", "victor", "danielle"};
    char guessP1[ROWS][COLS] = {};

    // open text file & catch error
    inFile.open("numPlayers.txt", ios::in);
    if (inFile) inFile >> nPlayrs;
    else {
        cout << "Error reading numPlayers.txt\n";
        nPlayrs = 2;
    }

    // pointer for rounds
    int *rndPtr = nullptr;
    rndPtr = &round;

    // creating 1 new Score structure
    Score *score = new Score; 
   
    // initializing structure with data
    score = fillScore(names, indx1);

    // print Scores structure members
    print(score);
    
    
    
   
   
    // create a file to write to
    outFile.open("scores.txt", ios::out);

    //void wrtFile(fstream &out,char fn[]){                                     //https://github.com/ml1150258/2021_Fall_CSC_CIS_17a/blob/master/Lab/RainOrShine/main.cpp
    char choices[SIZE17 + 1] = "SBSSBSSBSSBSSBSSB"; // S=ship  B=blank
    char *chcePtr = nullptr; // declare pointer to a char
    chcePtr = choices; // assigns address of choices array to choicePointer
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 10; col++) {
            outFile << *(chcePtr + (rand() % SIZE17)) << " ";
        }
        outFile << endl;
    }

    // read in maximum number of games that can be played from file
    //inFile >> maxGmes;
    nGmsLft = maxGmes; // set numberOfGamesLeft to equal maxGames

    //    while(ttlGmes<maxGmes){
    //        
    //        // initial variables to represent the location of each player's ship
    //        score->player[0].shipLoc = rand()%(MAX-MIN)+MIN; // random number between [1,14]
    //        score->player[1].shipLoc = rand()%(MAX-MIN)+MIN;
    //         
    //        // sets variables to default starting values
    //        p1_crrt = p2_crrt = false;
    //       
    //        // display game's introduction message     
    //        banner(score,"BATTLESHIP");         
    //        
    //        // loops until a player correctly guesses opponents ship location
    //        while((!p1_crrt) && (!p2_crrt)){
    //            
    //        // display round number banner
    //        rBanner(rndPtr); 
    //           
    //
    //    //*****************Player 1's Guess Starts Here **************************** 
    //           
    //            
    //            // display instructions 
    //            cout << endl << setw(16) << score->player[0].name << "\nGuess a number between 1 and " << MAX << endl;
    //            
    //            // Generates random number guess between [1,14]
    //            p1Guess = rand()%(MAX-MIN)+MIN;
    //
    //            // checks if player1 guess is correct
    //            if(p1Guess == score->player[1].shipLoc){
    //
    //                // increment player 1 number of wins
    //                p1Win++;
    //
    //                // set structure's member value for player 1
    //                score->player[0].numWins = p1Win;
    //                nGmsLft--;  // decrease number of total games
    //
    //                // reassign player 1's value for a correct guess
    //                p1_crrt = true;                             
    //
    //                // display HIT message for player 1's correct guess  
    //                isHit=true;
    //                shipHit=1;
    //                hitMiss(score,shipHit,isHit,p1Guess); // display MISS message for player 2's wrong guess  
    //              
    //            } else {  // if player1 guess is wrong 
    //                
    //                // display MISS message for player 1's wrong guess  
    //                isHit=false;                    
    //                hitMiss(score,shipHit,isHit,p1Guess); 
    //            }
    //
    //            // conditional only runs if player 1 misses player 2's ship
    //            if(!p1_crrt){
    //
    //                //*************** Player 2's Guess *************
    //                //**********************************************
    //                // display instructions to player 2
    //                cout << endl << setw(16) << score->player[1].name << "\nGuess a number between 1 and " << MAX << endl;
    //
    //                // program automatically generates a guess for player 2
    //                p2Guess = rand()%(MAX-MIN)+MIN;
    //
    //                // conditional checks if player 2 is correct
    //                if(p2Guess == score->player[0].shipLoc){
    //
    //                    // increment player 2 number of wins
    //                    p2Win++;
    //                    score->player[1].numWins = p2Win; 
    //                    nGmsLft--;  // decrease number of total games
    //                    
    //                    // reassign player 2's value for a correct guess
    //                    p2_crrt = true;
    //                    
    //                    // display HIT message for player 2's correct guess  
    //                    isHit=true;
    //                    shipHit=0;
    //                    hitMiss(score,shipHit,isHit,p2Guess); 
    //                
    //                } else { // display message for player 2's wrong guess   
    //                    isHit=false;                    
    //                    hitMiss(score,shipHit,isHit,p2Guess); 
    //                }
    //            }
    //
    //            // if both players guess wrong, then display message 
    //            if((!p1_crrt) && (!p2_crrt)){
    //                cout << endl << "You Both Missed. Try Again...\n\n";
    //            }
    //            
    //        } // ends while((!p1_crrt) && (!p2_crrt))
    //
    //        // Display scoreboard banner  
    //        banner(score,"SCOREBOARD");
    //        
    //        // calculate total number of games won & number rounds played
    //        ttlGmes = score->player[0].numWins + score->player[1].numWins;
    //        score->ttlRnds = ttlRnds + round; // sums the total number of rounds from all games        
    // 
    //        
    //        // checks maximum number of games has NOT been played
    //        if(ttlGmes<maxGmes){
    //            
    //            cout << nGmsLft << " of " << maxGmes << " max games left.\n\n\n";
    //            pause();        
    //            *rndPtr = 1; // reset round for next game                      
    //                    
    //        } else { // display end of game results
    //           
    //            cout << "Max number of games has been reached." << endl;
    //            cout << fixed << showpoint << setprecision(2);           
    //            cout << "# of games played: " << ttlGmes << " games \n"
    //                 << "Total # of rounds played: " << score->ttlRnds  << endl
    //                 << score->player[0].name << " won " << score->player[0].numWins << " games\n"
    //                 << score->player[1].name << " won " << score->player[1].numWins << " games\n";           
    //        }           
    //    }//ends while(ttlGmes<maxGmes);   

    // write scores and averages to file
    outFile << fixed << showpoint << setprecision(2);

    // close files
    inFile.close();
    outFile.close();

    //de-allocate dynamic memory
    delete []score->player;
    //delete namsPtr;
    //delete namePtr;
    delete score;
    //namsPtr=nullptr;
    //namePtr=nullptr;
    score = nullptr;
    chcePtr = nullptr;

    // exit code
    return 0;
}
void print(Score *score){
    
    // print structure's contents
    cout << "Number of players: " << score->nPlayrs << endl;
    for(int i=MON;i<score->nPlayrs;i++){
          cout << "player[" << i <<"] " << score->player[i].name << endl;
          
    }
}
Score *fillScore(string names[], int ind) {

    int indx1, indx2, size7 = 7;
    Score *score = new Score;
    score->nPlayrs = 2;
    score->player = new Player[score->nPlayrs];


    // loop through number of players
    for (int i = MON; i < score->nPlayrs; i++) {

        // generate new random index for each player
        if (i == 0) {
            
            indx1 = rand() % size7;
            //cout << i << "  indx1 = " << indx1 << " = " << names[indx1] << endl;

        } else { //makes sure the same 2 names are NOT picked from the names array

            do {
                indx2 = rand() % size7;
            } while (indx2 == indx1);

            //cout << i << "  indx2 = " << indx2 << " = " << names[indx2] << endl;

            indx1 = indx2;
        }

        // creating new char[] the size of string +1
        score->player[i].name = new char[names[indx1].length() + 1];

        for (int c = MON; c < names[indx1].length() + 1; c++) {

            // convert string to c-string and to uppercase. static_cast as char           
            score->player[i].name[c] = (char) toupper(names[indx1].c_str()[c]);
            //cout << (char) toupper(names[indx1].c_str()[c]) <<endl;
        }
    }     
    return score;
}

// display hit message when player guesses correctly
void hitMiss(Score *score, int i, bool isHit, int guess) {

    if (isHit) {
        cout << setw(15) << guess << " == "
                << score->player[i].shipLoc << endl;
        cout << setw(22) << "It\'s a HIT!\n" << endl;
    } else {
        cout << setw(15) << guess << endl << setw(22) << "It\'s a MISS!\n";
    }
}

// banner displays round number
void rBanner(int *rndPtr) {
    *rndPtr += 1;
    cout << endl << setw(26) << "********************************" << endl;
    cout << setw(18) << "Round " << *rndPtr << endl;
    cout << setw(26) << "********************************" << endl;
}

// displays game's name and instructions in a banner
void banner(Score *score, string title) {

    cout << "********************************\n" << setw(21) << title << endl;
    cout << setw(10) << setfill(' ') << score->player[0].name
            << setw(6) << setfill(' ') << right << "vs"
            << setw(12) << score->player[1].name << endl;

    if (title == "SCOREBOARD") {
        cout << setw(8) << score->player[0].numWins
                << setw(14) << score->player[1].numWins << endl;
    } else {
        cout << setw(2) << " " << "\nTry to guess the location of \n"
                << setw(6) << " " << "the computer\'s ship." << endl;
    }
}

// pause screen before game starts
void pause() {
    cout << "\nPress enter to continue. ";
    //cin.ignore();
    cin.get();
}
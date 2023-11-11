/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 10-28-2022 @ 4 PM
 * Purpose: CIS 17A Project 1. Covers chapters 9-12 in Tony Gaddis. Battleship v1
 Version 4:
 Changed choices from 2D to a new structure Choices. 
 I used that structure to write to a binary and text file.
 Then I looked for a specific rand() record, read it from the binary file.
 Confirmed the correct record was located by comparing it to the text file.
  
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
#include <vector>
#include <valarray>   // vector
using namespace std;


// Global Constants
// Physics/Chemistry/Math/Conversions
const int COLS10 = 10; // number of cols in 2D array

enum day {
    MON, TUE, WED, THUR, FRI, SAT, SUN
};

// User libraries

struct Choices {
    int size;
    char a;     //CHANGE TO ARRAY
};

struct Player {
    char *name;
    int numWins;
    int shipLoc; // ship's location on game board
    int rows;
    int cols;
    char **board; // player's game board  --> replaced static array board1[ROWS][COLS]={};    //look at github how to fill class>randomDyn2DArr
    //char **guessArr; // player's guesses  --> guessP1[ROWS][COLS]={};   
};

struct Score {
    int nPlayrs,
    maxGmes;
    int ttlRnds;
    Player *player;
};

// Function prototypes
Score *fillScore(string [], int);
void print(Score *);
void wrtTxt(fstream &, Choices *, int);
void wrtBin(fstream &, char *);
void pause();
void banner(Score *, string);
void rBanner(int *);
void hitMiss(Score *, int, bool, int);

int main(int argc, char** argv) {// Program execution begins here

    // set random number seed
    srand(static_cast<unsigned int> (time(0)));

    // declare variables  
    fstream binFile;
    fstream outFile; // for outputting to a file
    ifstream inFile; // for reading an existing file

    const int SIZE7 = 7,
            SIZE17 = 17,
            ROWS = 3;
    int indx1,
            indx2,
            numPlay = 0;


    string names[SIZE7] = {"mom", "bart", "homer", "jillian", "ting", "victor", "danielle"};

    // open text file & catch error
    inFile.open("numPlayers.txt", ios::in);
    if (inFile) inFile >> numPlay;
    else {
        cout << "Error reading numPlayers.txt\n";
        numPlay = 2;
    }

    // creating 1 new Score structure
    Score *score = new Score;

    // initializing structure with data
    score = fillScore(names, numPlay);

    // SET PLAYER'S GAME BOARDS UP
    int nRows = 2, nRecords = 20;
    char board[ROWS][COLS10] = {};


    //  WRITE & READ TO BINARY FILE    
    // open input and output binary file. if file does NOT exist, it is created
    binFile.open("data.bin", ios::out | ios::binary | ios::in);

    // create a file to write to
    outFile.open("choices.txt", ios::out);

    //void wrtFile(fstream &out,char fn[]){    -->                              //https://github.com/ml1150258/2021_Fall_CSC_CIS_17a/blob/master/Lab/RainOrShine/main.cpp
    char choices[SIZE17 + 1] = "SBSSBSSBSSBSSBSSB"; // S=ship  B=blank

    char *chcePtr = nullptr; // declare pointer to a char

    chcePtr = choices; // assigns address of choices array to choicePointer


    // set Choices structure, write to text file and write to binary file
    for (int record = 0; record < nRecords; record++) {

        Choices *choice = new Choices;

        choice->a = *(chcePtr + (rand() % SIZE17));

        wrtTxt(outFile, choice, record);

        binFile.write(reinterpret_cast<char *> (choice), sizeof (Choices));

        delete choice;
    }

    // fill 2D array 
    for (int record = 0; record < nRecords; record++) {

        //outFile << "record " << record << endl;

        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < COLS10; col++) {
                board[row][col] = *(chcePtr + (rand() % SIZE17));
                //outFile << board[row][col] << " ";
                //wrtTxt(outFile, board,row,col, record, SIZE17);
                //outFile << *(chcePtr + (rand() % SIZE17)) << " ";                
            }
            //outFile << endl;
        }
        //outFile << "\n\n";
    }
    
    // READ text and binary file
    int recInd = rand() % nRecords;
    cout << "Locate record #" << recInd << endl;

    cout << "sizeof(Choices) = " << sizeof (Choices) << endl;

    long cursor = 0L;

    Choices *choice = new Choices;

    cursor = recInd * sizeof (Choices);

    // set cursor to beginning of file so it can read that record
    binFile.seekg(cursor, ios::beg);

    // read 1 record from binary file & save to new pointer
    binFile.read(reinterpret_cast<char *> (choice), sizeof (Choices));

    cout << "binFile.dat contents:\n";
    cout << "record " << recInd << " = " << choice->a <<endl;



    // CREATE & SET dynamic 2D array inside of players for **board
    for (int p = 0; p < score->nPlayrs; p++) {
        score->player[p].rows = nRows;
        score->player[p].cols = COLS10;
        //cout << "rows= " << score->player[p].rows << endl;
        //cout << "cols= " << score->player[p].cols << endl;


        // create new array of rows inside of players->board for 2D array
        score->player[p].board = new char*[score->player[p].rows];

        // allocate each row with 10 columns because **board should be a 2D array
        for (int r = 0; r < score->player[p].rows; r++) {
            score->player[p].board[r] = new char[score->player[p].cols];
        }

        // set **board[][] BUG!  both players have same value of board[][]
        for (int row = 0; row < score->player[p].rows; row++) {
            for (int col = 0; col < score->player[p].cols; col++) {
                score->player[p].board[row][col] = board[row][col];
            }
        }
    }


    // print Scores structure members
    print(score);

    
    // close file
    binFile.close();
    inFile.close();
    outFile.close();


    //de-allocate dynamic memory
    for (int p = 0; p < score->nPlayrs; p++) {
        for (int row = 0; row < score->player[p].rows; row++) {
            delete []score->player[p].board[row]; //Deletes the Data row by row
        }
    }

    delete []score->player;
    delete score;
    score = nullptr;
    chcePtr = nullptr;

    // exit code
    return 0;
}

/***************FUNCTION DEFINITIONS**********************************/

// write contents of score structure to binary file
void wrtBin(fstream &binFile, char *chcePtr) {
    binFile.write(chcePtr, sizeof (chcePtr));
    // binFile.write(reinterpret_cast<char *> (*chcePtr), sizeof (char));
}

// write to text file
void wrtTxt(fstream &outFile, Choices *choice, int record) {

    outFile << "Record " << setw(2) << right << record << " ";
    outFile << setw(1) << choice->a << " \n";
}

// play game
Score *fillScore(string names[], int numPlay) {

    int MIN = 1, // minimum number for rand()
            MAX = 14, // maximum number for rand()
            SIZE7 = 7,
            SIZE17 = 17, //choices array
            ROWS = 3;
    bool p1_crrt, // player 1 correct
            p2_crrt, // player 2 correct
            isHit; //which player's ship that was hit
    int indx1,
            indx2,
            maxGmes = 2, // number of games
            nGmsLft, // number of games left       
            round = 1, // round
            p1Guess, // player 1 guess
            p2Guess, // player 2 guess                
            p1Win = 0, // counter for player 1 wins
            p2Win = 0, // counter for player 2 wins
            ttlGmes = 0, // sum of both players number of wins
            ttlRnds = 0, // sum of total rounds played                         
            shipHit;

    // create new pointer to Score structure
    Score *score = new Score;

    score->nPlayrs = numPlay;

    score->player = new Player[score->nPlayrs];

    score->maxGmes = maxGmes;

    // loop through number of players
    for (int i = MON; i < score->nPlayrs; i++) {

        // generate new random index for each player
        if (i == 0) {

            indx1 = rand() % SIZE7;
            //cout << i << "  indx1 = " << indx1 << " = " << names[indx1] << endl;

        } else { //makes sure the same 2 names are NOT picked from the names array

            do {
                indx2 = rand() % SIZE7;
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

    // pointer for rounds
    int *rndPtr = nullptr;
    rndPtr = &round;

    // read in maximum number of games that can be played from file
    nGmsLft = score->maxGmes; // set numberOfGamesLeft to equal maxGames

    while (ttlGmes < score->maxGmes) {

        // initial variables to represent the location of each player's ship
        score->player[0].shipLoc = rand() % (MAX - MIN) + MIN; // random number between [1,14]
        score->player[1].shipLoc = rand() % (MAX - MIN) + MIN;

        // sets variables to default starting values
        p1_crrt = p2_crrt = false;

        // display game's introduction message     
        banner(score, "BATTLESHIP");

        // loops until a player correctly guesses opponents ship location
        while ((!p1_crrt) && (!p2_crrt)) {

            // display round number banner
            rBanner(rndPtr);


            //*****************Player 1's Guess Starts Here **************************** 

            // display instructions 
            cout << endl << setw(10) << " " << score->player[0].name << "\n Guess a number between 1 and " << MAX << endl;

            // Generates random number guess between [1,14]
            p1Guess = rand() % (MAX - MIN) + MIN;

            // checks if player1 guess is correct
            if (p1Guess == score->player[1].shipLoc) {

                // increment player 1 number of wins
                p1Win++;

                // set structure's member value for player 1
                score->player[0].numWins = p1Win;
                nGmsLft--; // decrease number of total games

                // reassign player 1's value for a correct guess
                p1_crrt = true;

                // display HIT message for player 1's correct guess  
                isHit = true;
                shipHit = 1;
                hitMiss(score, shipHit, isHit, p1Guess); // display MISS message for player 2's wrong guess  

            } else { // if player1 guess is wrong 

                // display MISS message for player 1's wrong guess  
                isHit = false;
                hitMiss(score, shipHit, isHit, p1Guess);
            }

            // conditional only runs if player 1 misses player 2's ship
            if (!p1_crrt) {

                //*************** Player 2's Guess *************
                //**********************************************
                // display instructions to player 2
                cout << endl << setw(10)<<" " << score->player[1].name << "\n Guess a number between 1 and " << MAX << endl;

                // program automatically generates a guess for player 2
                p2Guess = rand() % (MAX - MIN) + MIN;

                // conditional checks if player 2 is correct
                if (p2Guess == score->player[0].shipLoc) {

                    // increment player 2 number of wins
                    p2Win++;
                    score->player[1].numWins = p2Win;
                    nGmsLft--; // decrease number of total games

                    // reassign player 2's value for a correct guess
                    p2_crrt = true;

                    // display HIT message for player 2's correct guess  
                    isHit = true;
                    shipHit = 0;
                    hitMiss(score, shipHit, isHit, p2Guess);

                } else { // display message for player 2's wrong guess   
                    isHit = false;
                    hitMiss(score, shipHit, isHit, p2Guess);
                }
            }

            // if both players guess wrong, then display message 
            if ((!p1_crrt) && (!p2_crrt)) {
                cout << endl << "  You Both Missed. Try Again...\n\n";
            }

        } // ends while((!p1_crrt) && (!p2_crrt))

        // Display scoreboard banner  
        banner(score, "SCOREBOARD");

        // calculate total number of games won & number rounds played
        ttlGmes = score->player[0].numWins + score->player[1].numWins;
        score->ttlRnds = ttlRnds + round; // sums the total number of rounds from all games        


        // checks maximum number of games has NOT been played
        if (ttlGmes < score->maxGmes) {

            cout << endl << setw(6) << setfill(' ') << nGmsLft << " of " << score->maxGmes << " max games left.\n"
                    << setw(4) << setfill(' ') << "Total # of rounds it took to win: " << score->ttlRnds << endl << endl;

            pause();
            *rndPtr = 1; // reset round for next game                      

        } else { // display end of game results               

            cout << fixed << showpoint << setprecision(2);
            cout << endl << score->maxGmes << " out of " << ttlGmes << " games played.\n\n\n";
        }
    }//ends while(ttlGmes < score->maxGmes); 

    return score;
}


void print(Score *score) { // print Score structure member's

    // print structure's contents
    cout << "\n Scores Structure Results\n" 
         << " Number of players: " << score->nPlayrs << endl;
    cout << " Max # of games: " << score->maxGmes << endl
         << setw(4) << setfill(' ') << " Total # of rounds it took to win: " << score->ttlRnds << endl << endl;

    for (int p = MON; p < score->nPlayrs; p++) {

        cout << " player[" << p << "] " << score->player[p].name << endl;
        cout << " # of wins:         " << score->player[p].numWins << endl
             << " Ship's Location:   " << score->player[p].shipLoc << endl;

        cout << " **board:\n";
        for (int row = 0; row < score->player[p].rows; row++) {
            for (int col = 0; col < score->player[p].cols; col++) {
                cout << score->player[p].board[row][col] << " ";
            }
            cout<<endl;
        }
        cout << endl << endl;
    }
}


// display hit message when player guesses correctly
void hitMiss(Score *score, int i, bool isHit, int guess) {

    if (isHit) {
        cout << setw(10) << guess << " == " << score->player[i].shipLoc << endl;
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
        cout << setw(2) << " " << "\n   Try to guess the location of \n"
             << setw(6) << " " << "the computer\'s ship." << endl;
    }
}

// pause screen before game starts
void pause() {
    cout << "\nPress enter to continue. ";
    //cin.ignore();
    cin.get();
}
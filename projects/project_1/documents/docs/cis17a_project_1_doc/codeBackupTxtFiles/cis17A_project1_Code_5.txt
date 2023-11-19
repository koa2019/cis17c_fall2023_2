/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 10-29-2022 @ 4 PM
 * Purpose: CIS 17A Project 1. Covers chapters 9-12 in Tony Gaddis. Battleship v1
 Version 5:
 Wrote to Choices & Scores structures to separate binary files because I can't
 get scores to read from binary correctly.
 Had choices binary pick a random letter and then switched it back to reference
 chcePtr that points to array of Ships or blanks.
 Fixed scores->board[][] bug by randomly picking a row and col inside of its brackets.
 Got rid of inFile and set number of players inside fillScore().
 Cleaned up play() by printing end of game results in the printScore();
 PrintScore() displays their oppontent's corresponding row, so you can compare for correct guesses.
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

enum day {
    MON, TUE, WED, THUR, FRI, SAT, SUN
};

// User libraries

struct Choices {
    int size;
    char *a; //CHANGE TO ARRAY
};

struct Player {     // structure represents a single player
    char *name;
    int numWins;    // a player's number of wins
    int shipLoc;    // ship's location on game board
    int brdIndx;    // row index for board[][]
    int brdCol;     // column index for board[][]
    int rows;       // number of rows in board[][]
    int cols;       // number of cols in board[][]
    char **board; // player's game board  --> replaced static array board1[ROWS][COLS]={};    //look at github how to fill class>randomDyn2DArr
    //char **guessArr; // player's guesses  --> guessP1[ROWS][COLS]={};   
};

struct Score {
    int nPlayrs;
    int maxGmes;
    int ttlGams;
    int ttlRnds;
    Player *player;
    //Choices *choices;
};

// Function prototypes
Score *fillScore(string []);
void prntScore(Score *);
void wrtTxt1(fstream&, Choices *, int); //write Choices structure
void wrtTxt2(fstream&, Score *, int); //write Score structure
void wrtBin1(fstream &, char *);
Score *readBin2(fstream &, int);
void pause();
void banner(Score *, string);
void rBanner(int *);
void hitMiss(Score *, int, bool, int);

int main(int argc, char** argv) {// Program execution begins here

    // set random number seed
    srand(static_cast<unsigned int> (time(0)));

    // declare variables  
    fstream binFile; // write Choices structure to binary file
    fstream binFile2; // write Scores structure to binary file
    fstream outFile; // write Choices structure to text file
    fstream outFile2; // write Scores structure to text file
   

    const int COLS10 = 10; // number of cols in 2D array

    const int SIZE7 = 7,
              SIZE17 = 17,
              ROWS = 2;
    int       indx1,
              indx2;

    string names[SIZE7] = {"mom", "bart", "homer", "jillian", "ting", "victor", "danielle"};

     
    // creating 1 new Score structure
    Score *score = new Score;

    // initializing structure with data
    score = fillScore(names);

    // SET PLAYER'S GAME BOARDS UP
    int nRows = 2;
    char board[ROWS][COLS10] = {};    

   
    //void wrtFile(fstream &out,char fn[]){    example-->             //https://github.com/ml1150258/2021_Fall_CSC_CIS_17a/blob/master/Lab/RainOrShine/main.cpp
    char choices[SIZE17 + 1] = "SBSSBSSBSSBSSBSSB"; // S=ship  B=blank

    char *chcePtr = nullptr; // declare pointer to a char

    chcePtr = choices; // assigns address of choices array to choicePointer

    // fill 2D array with game board. ships or blank spaces
    int  nRecords = 20;
    for (int record = 0; record < nRecords; record++) {

        for (int row = 0; row < nRows; row++) {
            for (int col = 0; col < COLS10; col++) {
                
                // setting char[][] to a random value from choices[]
                board[row][col] = *(chcePtr + (rand()%SIZE17));
            }
        }
    }

    // CREATE & SET dynamic 2D array inside of players for **board
    for (int p = 0; p < score->nPlayrs; p++) {
        score->player[p].rows = nRows;  // set rows to 2
        score->player[p].cols = COLS10; // set columns to 2


        // create new array of rows inside of players->board for 2D array
        score->player[p].board = new char*[score->player[p].rows];

        // allocate each row with 10 columns because **board should be a 2D array
        for (int r = 0; r < score->player[p].rows; r++) {
            score->player[p].board[r] = new char[score->player[p].cols];
        }

        // set **board[][] BUG!  both players have same value of board[][]
        for (int row = 0; row < score->player[p].rows; row++) {
            for (int col = 0; col < score->player[p].cols; col++) {
                
                // Setting structure to a rand() value from 2D char[][]
                score->player[p].board[row][col] = board[rand()%nRows][rand()%COLS10];
            }
        }
    }
    
    // Print Score Structure
    prntScore(score);
    
    
    
    /***********        1  Write Binary Files   **************/
    
    //  Write Choices structure & Read TO BINARY FILE    
    binFile.open("choices.bin", ios::out | ios::binary | ios::in);

    // Create text file to write to
    outFile.open("choices.txt", ios::out);

    // Create 20 records of Choice structures in binary & text files
    for (int record = 0; record < nRecords; record++) {
        
        Choices *choice = new Choices;
        choice->a = new char[nRows*COLS10];
        
        //choice->a[record] = rand() % 26 + 65; //change this back to ref choices[]
        choice->a[record] = *(chcePtr+(rand()%SIZE17));

        wrtTxt1(outFile, choice, record);

        binFile.write(reinterpret_cast<char *> (choice), sizeof (Choices));

        delete choice;
    }

    /***********    1 Read Binary Files   **************/
    
    int recInd = rand() % nRecords;
    cout << " Reading choices.bin... Locating record # " << recInd << endl;

    long cursor = 0L;

    Choices *choice = new Choices;

    // calculates number of bytes by multiplying index & size of data types in file
    cursor = recInd * sizeof(Choices);
    //cout<<"looking for record = "<<recInd<<" * sizeof(Choices) = "<<sizeof(Choices)<<"  cursor size = "<<cursor<<endl;

    // set cursor to beginning of file so it can read that record
    binFile.seekg(cursor, ios::beg);

    // read 1 record from binary file & save to new pointer
    binFile.read(reinterpret_cast<char *> (choice), sizeof (Choices));

    cout << " Found record # " << recInd << " = " << static_cast<char> (choice->a[recInd]) << endl;

    delete choice;

    
    
    /***********   2 Write Binary Files   **************/
    
    //   write 20 records of Scores structure to binary & read it back correctly
    binFile2.open("scores.bin", ios::out | ios::binary | ios::in);
    outFile2.open("scores.txt", ios::out | ios::in);    
    
    // write 20 records to binary and text files
    for (int record = 0; record < 20; record++) {

        binFile2.write(reinterpret_cast<char *> (&score), sizeof (Score));
        
        wrtTxt2(outFile2, score, record);
    }

    /***********   2 Read Binary Files   **************/
    
    // Access 1 random record in binary file and confirm by comparing it to text file
    recInd = rand() % nRecords;    
    cout << "\n Reading scores.bin... Locating record #" << recInd << endl;
    
    Score *oneRec = readBin2(binFile2, recInd);

    // print a single record of a Score structure 
    cout << " Found record " << recInd << endl;   
    cout << " oneRec->ttlRnds " << oneRec->maxGmes << endl;
    //cout << oneRec->player[0].name << endl << oneRec->player[0].name << endl ;
    

    
    // close file    
    binFile.close();
    binFile2.close();
    outFile.close();
    outFile2.close();


    //de-allocate dynamic memory
    for (int p = 0; p < score->nPlayrs; p++) {
        for (int row = 0; row < score->player[p].rows; row++) {
            delete []score->player[p].board[row]; //Deletes the Data row by row
        }
    }
    delete []choice->a;
    delete []score->player;
    delete score;
    delete oneRec;
    score = nullptr;
    chcePtr = nullptr;

    // exit code
    return 0;
}

/***************FUNCTION DEFINITIONS**********************************/


// write contents of score structure to binary file
Score *readBin2(fstream &binFile2, int record) {
    long cursor = 0L;

    Score *oneRec = new Score;

    // calculates number of bytes by multiplying index & size of data types in file
    cursor = record * sizeof (Score);
    //cout<<"looking for record = "<<recInd<<" * sizeof(Choices) = "<<sizeof(Choices)<<"  cursor size = "<<cursor<<endl;

    // set cursor to beginning of file so it can read that record
    binFile2.seekg(cursor, ios::beg);

    // read 1 record from binary file & save to new pointer
    binFile2.read(reinterpret_cast<char *> (oneRec), sizeof (Score));

    return oneRec;
}


// write contents of score structure to binary file
void wrtBin1(fstream &binFile, char *chcePtr) {

}


// write to text file
void wrtTxt1(fstream &outFile, Choices *choice, int record) {

    outFile << "Record " << setw(2) << right << record << " ";
    outFile << setw(1) << choice->a[record] << " \n";
}


// write to text files
void wrtTxt2(fstream &outFile2, Score *score, int record) {

    // write structure's contents
    outFile2 << setw(4) <<" " << "Score Record #" << record << endl;
    outFile2 << "Max games: " << score->maxGmes << endl << setw(4) << setfill(' ')
             << "Total rounds in 1 game: " << score->ttlRnds << endl;

    for (int p = MON; p < score->nPlayrs; p++) {

        outFile2 << setw(4) <<" " << score->player[p].name << endl;

        outFile2 << "# of wins:       "<< score->player[p].numWins << endl
                 << "Ship's Location: " << score->player[p].shipLoc << endl;

        outFile2 << setw(8) << "Game board:\n";

        // write 2D array for game board
        for (int row = 0; row < score->player[p].rows; row++) {
            for (int col = 0; col < score->player[p].cols; col++) {
                outFile2 << score->player[p].board[row][col] << " ";
            }
            outFile2 << endl;
        }
    }
    outFile2 << endl;
}


// print Score structure
void prntScore(Score *score) { // print Score structure member's

    // Display scoreboard banner  
    banner(score, "SCOREBOARD");

    cout << endl <<"   "<< score->maxGmes << " out of " << score->ttlGams << " games played.\n";
    cout << "   Total rounds in 1 game: " << score->ttlRnds << endl << endl;

    cout << " Player 1's Ship Location:   " << score->player[0].shipLoc << endl
            << " Player 2's Ship Location:   " << score->player[1].shipLoc << endl << endl;

        for (int row = 0; row < score->player[0].rows; row++) {
            cout << " Player 1's Game board Row " << row << ": ";
            for (int col = 0; col < score->player[0].cols; col++) {
                cout << score->player[0].board[row][col] << " ";
            }
            cout << "\n Player 2's Game board Row " << row << ": ";
            for (int col = 0; col < score->player[0].cols; col++) {
                cout << score->player[1].board[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;

}


// play game
Score *fillScore(string names[]) {

    int     MIN = 1, // minimum number for rand()
            MAX = 14, // maximum number for rand()
            SIZE7 = 7,  // size of names array
            SIZE17 = 17; //size of choices array
            //ROWS = 2;   // number of rows
    bool    p1_crrt, // player 1 correct
            p2_crrt, // player 2 correct
            isHit; //which player's ship that was hit
    int     indx1,
            indx2,
            maxGmes = 2, // number of games
            nGmsLft, // number of games left       
            round = 0, // round
            p1Guess, // player 1 guess
            p2Guess, // player 2 guess                
            p1Win = 0, // counter for player 1 wins
            p2Win = 0, // counter for player 2 wins
            ttlGmes = 0, // sum of both players number of wins
            ttlRnds = 0, // sum of total rounds played                         
            shipHit,
            numPlay=2;

    // create new pointer to Score structure
    Score *score = new Score;

    score->nPlayrs = numPlay;  
    
    score->maxGmes = maxGmes;
    
    // create a pointer to Player's structure and create array size of 2
    score->player = new Player[score->nPlayrs];

    // loop through number of players
    for (int i = MON; i < score->nPlayrs; i++) {

        // generate new random name for each player
        if (i == 0) {

            indx1 = rand()%SIZE7;            

        } else { //makes sure the same 2 names are NOT picked from the names array

            do {
                indx2 = rand() % SIZE7;
            } while (indx2 == indx1);

            indx1 = indx2;
        }

        // creating new char[] the size of string +1
        score->player[i].name = new char[names[indx1].length() + 1];

        // loop through the length of name string
        for (int c = MON; c < names[indx1].length() + 1; c++) {

            // convert string to c-string and to uppercase. static_cast as char           
            score->player[i].name[c] = (char) toupper(names[indx1].c_str()[c]);           
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
        banner(score,"BATTLESHIP");

        // loops until a player correctly guesses opponents ship location
        while ((!p1_crrt) && (!p2_crrt)) {

            // display round number banner
            rBanner(rndPtr);

            //*****************Player 1's Guess Starts Here **************************** 

            // display instructions 
            cout << endl << setw(12) << " " << score->player[0].name << "\n Guess a number between 1 and " << MAX << endl;

            // Generates random number guess between [1,14]
            p1Guess = rand()%(MAX-MIN)+MIN;

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
                cout << endl << setw(12) << " " << score->player[1].name << "\n Guess a number between 1 and " << MAX << endl;

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
            if ((!p1_crrt) && (!p2_crrt)) cout << endl << "  You Both Missed. Try Again...\n\n";
            
        } // ends while((!p1_crrt) && (!p2_crrt))
       
        // calculate total number of games won & number rounds played
        ttlGmes = score->player[0].numWins + score->player[1].numWins;
        score->ttlGams = ttlGmes;
        score->ttlRnds = ttlRnds + round; // sums the total number of rounds from all games        

        // checks maximum number of games has NOT been played
        if (ttlGmes < score->maxGmes) {
            
            cout << endl << setw(6) << setfill(' ') << nGmsLft << " of " << score->maxGmes << " max games left.\n"
                 << setw(4) << setfill(' ') << "Total # of rounds it took to win: " << score->ttlRnds << endl << endl;
            pause();            
        }           
        *rndPtr = 1; // reset round for next game 
        
    }//ends while(ttlGmes < score->maxGmes); 
    
    return score;
}

// display hit message when player guesses correctly
void hitMiss(Score *score, int i, bool isHit, int guess) {

    if (isHit) {
        cout << setw(12) << guess << " == " << score->player[i].shipLoc << endl;
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
    cout << "********************************\n";
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
    cout << "\nPress enter to continue. \n\n";
    //cin.ignore();
    cin.get();
}
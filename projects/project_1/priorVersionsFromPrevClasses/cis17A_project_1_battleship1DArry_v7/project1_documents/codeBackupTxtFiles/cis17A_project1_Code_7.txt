/* File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 11-05-2022 @ 9 PM
 * Purpose: CIS 17A Project 1. Covers chapters 9-12 in Tony Gaddis. Battleship v1
   Version 7:
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand()
#include <fstream>  // fstream 
#include <cstring>  // char [] library
#include <string>   // length() library
#include <ctime>    // time library for rand()
#include <cctype>   // toupper()
using namespace std;

// User libraries
#include "Choices.h"
#include "Player.h"
#include "Score.h"

// Global Constants
// Physics/Chemistry/Math/Conversions
enum nums {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN
};


// Function prototypes
Choices *fillChoice(char *,const int);    // fills Choice structure 
void wrtTxt1(fstream&,Choices *,int);     //write Choices structure to text file
void wrtBin1(fstream &,Choices *);      // write Choices structure to binary file
Choices *readBin1(fstream &,int);       // read binary file
Score *fillScore(string [],char **);    // fill Score structure by playing game
bool play(Score *,int,int,int &);       // run's each player's guess
char **fill2DPtr(char *,const int);     // fills a dynamic 2D pointer
void setBoard(Score *score,char **ptr2D);   // sets 2D pointer with Score structure
void prntScore(Score *);    // prints Score structure
void pause();                   // pauses game to allow user to view results before proceeding
void banner(Score *,string);    // print banner
int *rBanner(int &);            // print round banner
void hitMiss(Score *,int,int,bool);     // print message after each player guesses

int main(int argc, char** argv) {// Program execution begins here

    // set random number seed
    srand(static_cast<unsigned int> (time(0)));

    // declare variables  
    fstream binFile; // write Choices structure to binary file
    fstream outFile; // write Choices structure to text file
   
    const int SIZE17 = 17;  // # of characters in choices array            
    int       nRecords = 20,
              recInd;   // index for random record 
    string    names[SEVEN] = {"mom", "bart", "homer", "jillian", "ting", "victor", "danielle"};

    
    // Fill game board with ships or blanks
    //char gBoard[SIZE17 + 1] = "SbSsaSsehSjSwpSsx"; // S=ship  B=blank
    char gBoard[SIZE17 + 1] = "SbSsBSsbBSBSbbSsb"; // S=ship  B=blank
    
    char *bordPtr = nullptr; // declare pointer to a char
    
    bordPtr = gBoard;       // assigns address of gBoard array to bordPtr

    // 2D array to represent a player's game board   
    char **board2D = nullptr;    

    // Call fill2Darr func to fill **board2D with random letters from *bordPtr
    board2D = fill2DPtr(bordPtr,SIZE17);
     
    // creating 1 new Score structure
    Score *score = new Score;

    // Initialize pointer to Score by calling fillScore function
    score = fillScore(names,board2D);

    // fill **board within Score structure
    setBoard(score,board2D);    
    
    /***********    1  Write Choices structure to binary file   **************/
       
    binFile.open("2choices.bin", ios::in|ios::out|ios::binary); 
    if(!binFile) cout <<"Error opening choices.bin\n";
    
    outFile.open("choices.txt", ios::in|ios::out);  // Create text file to write to

    // Create 20 records of Choice structures in binary & text files
    for (int record = 0; record < nRecords; record++) {
        
        // Declare pointer & set with a Choice structure
        Choices *choice = fillChoice(bordPtr,SIZE17); 
        
        // write each instance of Choice to binary & text files
        wrtTxt1(outFile,choice,record);
        wrtBin1(binFile,choice);       
        delete choice;
    }

    /***********    1 Read Binary Files   **************/
    
    recInd = rand() % nRecords;   
    Choices *choice = readBin1(binFile,recInd);    
    cout << "Reading choices.bin...\nLocating record #"<<recInd<<"\nFound Choices record # " << recInd << "\n";   
    for(int i=ZERO;i<choice->size;i++){        
        cout << choice->arr[choice->indx[i]];
        if(i%TEN==NINE) cout<<endl;                    
    }
    delete choice;
    
    // close file    
    binFile.close();   
    outFile.close();

    //de-allocate dynamic memory
    for (int p = 0; p < score->nPlayrs; p++) {
        for (int row = 0; row < score->player[p].rows; row++) {
            delete []score->player[p].board[row]; //Deletes the Data row by row
        }
    }
    //delete []choice->a;
    delete []score->player;
    delete score;   
    score = nullptr;
    bordPtr = nullptr;

    // exit code
    return 0;
}

/*************      FUNCTION DEFINITIONS      ***************/

void setBoard(Score *score,char **board2D){   
    
    // Create & Set dynamic 2D array inside of players for **board
    for (int p = 0; p < score->nPlayrs; p++) {
        score->player[p].rows = TWO;  // set rows to 2
        score->player[p].cols = TEN; // set columns to 10


        // create new array of rows inside of players->board for 2D array
        score->player[p].board = new char*[score->player[p].rows];

        // allocate each row with 10 columns because **board should be a 2D array
        for (int r = 0; r < score->player[p].rows; r++) {
            score->player[p].board[r] = new char[score->player[p].cols];
        }

        //set **board[][] with  
        cout<<score->player[p].name << " board in Score structure: \n";
        int r,c;
        for (int row = 0; row < score->player[p].rows; row++) {
            for (int col = 0; col < score->player[p].cols; col++) {
                
                r=rand()%TWO;
                c=rand()%TEN;
                
                // Setting structure to a rand() value from 2D char[][]
                score->player[p].board[row][col] = board2D[r][c];
                cout<<  score->player[p].board[row][col];
                if(col%10==9) cout<<endl;
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

// fill **pointer
char **fill2DPtr(char *bordPtr,const int SIZE17){
    
    char **ptr2D = nullptr;

    ptr2D = new char*[TWO];
    
    for (int row = 0; row < TWO; row++) {
        ptr2D[row] = new char[TEN];
    }
    
    // fill 2D array with game board with a random char from gBoard[]     
    for (int row = 0; row < TWO; row++) {
        for (int col = 0; col < TEN; col++) { 
            
            // setting 2D array to a random value from gBoard[] 
            //board[row][col] = *(bordPtr + (rand()%SIZE17));   
            ptr2D[row][col] = *(bordPtr + (rand()%SIZE17));  
        }
    }
    return ptr2D;
}

// read binary file and return one record 
Choices *readBin1(fstream &binFile,int recInd){
    int count=0;    
    long cursor = 0L;

    Choices *choice = new Choices;
   
    // Find the record by finding the size of one Choice structure & 
    // multiplying it by the index we're looking for
    while(++count<=recInd){
        
        // set cursor to beginning of file       
        binFile.seekg(cursor,ios::beg);
        
        // reading  size of char arr[]
        binFile.read(reinterpret_cast<char *>(&choice->size),sizeof(int));
        
        // calculates # of bytes by multiplying index & size of each data types in Choice structure
        cursor += ( sizeof(int) + choice->size*sizeof(char) + choice->size*sizeof(int));
    }   
    //cout << "cursor " << cursor << " bits\n";
    
    // set cursor to beginning of file so it can read that record
    binFile.seekg(cursor, ios::beg);

    // read 1 record from binary file & save to new pointer
    binFile.read(reinterpret_cast<char *> (&choice->size), sizeof(int));    
    choice->arr = new char[choice->size]; // allocate memory for char[]
    binFile.read(reinterpret_cast<char *>(choice->arr),choice->size*sizeof(char));
    choice->indx = new int[choice->size];
    binFile.read(reinterpret_cast<char *>(choice->indx),choice->size*sizeof(int));
    
    return choice;
}

// Declare & fill 1 instances of Choice structure
Choices *fillChoice(char *bordPtr,const int SIZE17){    
        Choices *choice = new Choices;
        choice->size = TWO*TEN;        
        choice->arr = new char[choice->size];
        choice->indx = new int[choice->size];
        
        //Fill array inside of Choice structure
        for(int i=0;i<choice->size;i++){
            choice->arr[i]=*(bordPtr+(rand()%SIZE17)); // fills with S=ship or B=blank
            //choice->arr[i]=rand() % 26 + 65; // rand() letters from alphabet
            choice->indx[i]=i;
        }  
    return choice;
}


// write Choices structure to binary file
void wrtBin1(fstream &binFile, Choices *choice) {
    binFile.write(reinterpret_cast<char *> (&choice->size), sizeof (int));
    binFile.write(reinterpret_cast<char *> (choice->arr),choice->size*sizeof(char));
    binFile.write(reinterpret_cast<char *> (choice->indx),choice->size*sizeof(int));        
}

// write Choices structure to text file
void wrtTxt1(fstream &outFile, Choices *choice, int recInd) {
    int perLine=TEN;
    outFile << "Record " << setw(2) << right << recInd << " \n";
    for(int i=0;i<choice->size;i++){
        outFile << setw(2) << choice->arr[choice->indx[i]];
        if(i%perLine==(perLine-1))outFile<<endl;
    }
    outFile<<endl;
}


//  print Score structure member's
void prntScore(Score *score) { 

    // Display scoreboard banner  
    banner(score, "SCOREBOARD");
 
    cout <<"\n         "<< score->ttlGams << " games left.\n";
    cout << "   Total rounds in this game: " << score->ttlRnds << endl << endl;

    cout << " Player 1's Ship Location:   " << score->player[0].shipLoc << endl
            << " Player 2's Ship Location:   " << score->player[1].shipLoc << endl << endl;

    for (int p=ZERO; p < score->player[p].rows; p++) {
        cout << "         Player "<<p+1<<"'s Game board \n";
        for (int row = 0; row < score->player[p].rows; row++) {
            for (int col = 0; col < score->player[p].cols; col++) {             
           
                cout<< "&" << score->player[p].board[row][col];
                if(col%TEN==NINE) cout<<endl;
            }           
        }
    }       
    cout << endl << endl;
}


// play game
Score *fillScore(string names[],char **bordPtr) {

    int     MAX = TEN*2, // maximum number for rand()          
            SIZE17 = 17; //size of choices array           
    bool    p1_crrt,     // player 1 correct
            p2_crrt;    // player 2 correct       
    int     indx1,       // index for player 1's name
            indx2,       // index for player 2's name
            maxGmes = FIVE, // number of games
            nGmsLft,      // number of games left       
            round = ZERO, // round
            numPlay = TWO;

    // create new pointer to Score structure
    Score *score = new Score;

    score->nPlayrs = numPlay;      
    score->maxGmes = maxGmes;
    score->ttlGams = ZERO;
    
    // create a pointer to Player's structure and create array size of 2
    score->player = new Player[score->nPlayrs];

    // loop through number of players
    for (int i = ZERO; i < score->nPlayrs; i++) {

        // generate new random name for each player
        if (i == ZERO) {

            indx1 = rand()%SEVEN;            

        } else { //makes sure the same 2 names are NOT picked from the names array

            do {
                indx2 = rand() % SEVEN;
            } while (indx2 == indx1);

            indx1 = indx2;
        }

        // creating new char[] the size of string +1
        score->player[i].name = new char[names[indx1].length() + 1];

        // loop through the length of name string
        for (int c = ZERO; c < names[indx1].length() + 1; c++) {

            // convert string to c-string and to uppercase. static_cast as char           
            score->player[i].name[c] = (char) toupper(names[indx1].c_str()[c]);           
        }
        
        // set each player's number of wins to zero
        score->player[i].numWins = 0;
    }

    // pointer for rounds
    int *rndPtr = nullptr;

    // read in maximum number of games that can be played from file
    nGmsLft = score->maxGmes; // set numberOfGamesLeft to equal maxGames
    
    while (nGmsLft>ZERO) {
       
        // initial variables to represent the location of each player's ship
        score->player[0].shipLoc = rand() % (ZERO+MAX); // random number between [1,14]
        score->player[1].shipLoc = rand() % (ZERO+MAX);

        // sets variables to default starting values
        p1_crrt = p2_crrt = false;

        // display game's introduction message     
        banner(score,"BATTLESHIP");

        // loops until a player correctly guesses opponents ship location
        while ((!p1_crrt) && (!p2_crrt)) {

            // display round number banner
            rndPtr = rBanner(round);

            // Player 1's Guess   
            p1_crrt = play(score,0,1,round);
          
            // conditional only runs if player 1 misses player 2's ship
            // Player 2's Guess 
            if(!p1_crrt) {   
                p2_crrt = play(score,1,0,round); 
            }

            // if both players guess wrong, then display message 
            if ((!p1_crrt) && (!p2_crrt)) cout << endl << "  You Both Missed. Try Again...\n\n";
            
        } // ends while((!p1_crrt) && (!p2_crrt))
        
        nGmsLft--;
        score->ttlGams = nGmsLft;
        prntScore(score);
        
        // checks maximum number of games has NOT been played
        if(nGmsLft>ZERO) pause();            
           
        // reset variables for next game
        *rndPtr = 0;          
        p1_crrt = p2_crrt = false; 
        
    } // ends while(nGmsLft> ZERO)
    
    return score;
}

// returns if player's guess is correct or not
bool play(Score *score,int a, int b, int &round){
   
    int     MAX = 20, // maximum number for rand()          
            SIZE17 = 17; //size of choices array     
    int     maxGmes = 3, // number of games           
            pGuess,      // player 1 guess                          
            numWins,      // counter for player 1 wins
            ttlGmes,    // sum of both players number of wins
            ttlRnds = ZERO; // sum of total rounds played                         
           
            // display instructions 
            cout << endl << setw(12) << " " << score->player[a].name << "\n Guess a number between "<<ZERO<<" and " << MAX-1 << endl;

            // Generates random number guess between [1,14]
            pGuess = rand()%(ZERO+MAX);

            // checks if player guess is correct
            if (pGuess == score->player[b].shipLoc) {
                
                numWins = score->player[a].numWins+1;    // increment player 1 number of wins                
                
                // set structure's member value for player 
                score->player[a].numWins = numWins;                
                score->player[a].isRight = true;                             
     
                // calculate total number of games won & number rounds played
                ttlGmes = score->player[a].numWins + score->player[b].numWins;
                score->ttlGams = ttlGmes;
                score->ttlRnds = ttlRnds + round; // sums the total number of rounds from all games        
                
                // display HIT message for player's correct guess 
                hitMiss(score, pGuess, b, true); // display MISS message for player 2's wrong guess                             
                return true;      
            } 
            
            // if player1 guess is wrong display MISS message 
            score->player[a].isRight = false;           
            hitMiss(score, pGuess,b, false);                           
            return false;                
}

// display hit message when player guesses correctly
void hitMiss(Score *score, int pGuess, int b, bool isHit) {

    if (isHit) {
        cout << setw(12) << pGuess << " == " << score->player[b].shipLoc << endl;
        cout << setw(22) << "It\'s a HIT!\n" << endl;
    } else {
        cout << setw(15) << pGuess << endl << setw(22) << "It\'s a MISS!\n";
    }
}

// banner displays round number
int *rBanner(int &round) {
    
    int *rndPtr = nullptr;
    round += 1;
    rndPtr = &round;
    cout << endl << setw(26) << "********************************" << endl;
    cout << setw(18) << "Round " << *rndPtr << endl;
    cout << setw(26) << "********************************" << endl;
    return rndPtr;
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
             << setw(6) << " " << "your opponent\'s ship." << endl;
    }
}

// pause screen before game starts
void pause() {
    cout << "\nPress enter to continue. \n\n";   
    cin.get();
}
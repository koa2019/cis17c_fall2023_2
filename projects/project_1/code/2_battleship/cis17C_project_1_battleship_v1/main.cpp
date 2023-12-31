/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on June 4, 2022,  4:28 PM
 * Purpose: CIS 17C Project 1
 * Version 1: Is based off my CIS 5 project 2 version 6 code.
 */

// System Libraries: 
#include <bits/stdc++.h>
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand(), EXIT_SUCCESS
#include <fstream>  // ofstream 
#include <cstring>  // string library
#include <string>
#include <ctime>    // time library for rand()
#include <cctype>   // toupper()
#include <climits> // char and int maximums
#include <cfloat>  //float maximum
#include <vector>   // vector
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions


// Function prototypes
unordered_set<string> setP2Names(string,string&);
unordered_set<string> pushFrntSet(string,string&); 
std::map<string, float> setTopPlyrs(unordered_set<string> &);
void topPlyrs(unordered_set<string> &);
void prntMapUnO(map<string, float>&);// Prints topPlyrs & hiScores
void prntStrSet(unordered_set<string>&);// Prints player 1 & player 2's names

//void pause();
//void banner(string);      // display game 
//void cGssArr(const char [][9], const char [][9],const int,const int,int, int); // confirms guess[][] filled correctly             
//void chckArr(char &);
//void fileSum(int,int,int,int);
//void fllGArr(char [][9],char [][9],char [], int, int, int &, int&);
void getName(string &);  // get player 1's name using pass by reference
//void hitMiss(bool,int,int);  // hit message for correct guess
//void hitMiss();        // try again message
//void instruc(string, const int, int =1); // instructions for players
//bool isReady(char);   // returns bool value
//void runMenu(string, char &, char &, int,int,int,int,char [][9],char [][9],
//             char [][9],char [][9],int,int,int,int,int &,int&,int,
//             unordered_set<string> &,int);

//string pickP2(string [],int);  // randomly picks a number for player 2
//void plyrShpBrd(int,int,const char [][9],const char [][9],const int,const int);
//void print2DArr(const char [][9],const char [][9],
//                const char [][9],const char [][9],const int,const int,int &,int &);
//void prntArr(string []);  // prints names[]
//void prntArr(const char [][9],int,int); //prints 2D
//void rBanner(int &);      // display the round number
//void sBanner(string,string,string,int,int);   // display scoreboard banner
//void sortSel();//Sorts last week's top scores
//void scoresMsg(int,int,float);  // displays scores for both players
//void showGuess(int,int);
//void showStatic();
//void swap1(string &,string &);
//void upper(string &); // changes string to all uppercase letters


// Program execution begins here
int main(int argc, char** argv) {

    // set random number seed
    srand(static_cast<unsigned int>(time(0)));

    // declare variables   
    ifstream     inFile1; // for reading an existing file
    ifstream     inFile2;
    ofstream     outFile; // for outputting to a file

    const int    MIN = 1, // minimum number for rand()
                 MAX = 16; // maximum number for rand()
    const int    SIZE7 = 7,  // size for player 2 names array
                 SIZE8 = 8;
    const int    ROWS = 3,
                 COLS = 9;   // number of cols in 2D array
    const int    SIZE17=17;    // choice array size
    
    bool         p1_crrt, // player 1 correct
                 p2_crrt, // player 2 correct
                 ready,   // ready to continue playing
                 isHit;
    
    char         ans, // answer  
                 ch,                 
                 p1Guess=0, // player 1 guess
                 p2Guess, // player 2 guess
                 p1Ship1, // player 1 ship number 1
                 p2Ship1; // player 2 ship number 1
            
    int          rowIndx,// index for comparing player's guess to their opponent's board
                 colIndx, // index for comparing player's guess to their opponent's board 
                 maxGms=0, // number of games
                 round=0, // round                 
                 p1Win=0, // number of wins player 1 has
                 p2Win=0, // number of wins player 2 has
                 ttlGmes=0,   // sum of both players number of wins
                 ttlRnds=0,   // sum of total rounds played
                 p1GShps,
                 p2GShps,
                 numShp1, 
                 numShp2, 
                 count1, 
                 count2,
                 winner;
    
    float        avgRnds;   // average rounds it takes to win
    
    string       p1Name = "Danielle", 
                 name2 = " ";
                
    char         board1[ROWS][COLS]={};
    char         board2[ROWS][COLS]={};
    char         guessP1[ROWS][COLS]={};
    char         guessP2[ROWS][COLS]={};
    
    // will be used to fill each player's guess[][]
    char choices[SIZE17]={'S','B','S','S','B','S','S','B','S','S','B','S','S','B','S','S','B'};
     
    // ask for player 1's name
    getName(p1Name);
    
    // Initialize names set & Push string into set
    unordered_set<string> names = pushFrntSet(p1Name,name2);
    cout << "\nSet Unsorted: Players \n";
    prntStrSet(names);
    
    
    // ***************************************
    // ****** SET UP GAME STARTS HERE ********
    // ***************************************
    
    
    // open an existing file that holds max number of games a user can play
    //inFile.open("maxNGms.txt");  
    //inFile1.open("board1.txt",ios::in);
    //inFile2.open("board2.txt",ios::in);
    //outFile.open("scores.txt");  // create a file to output to   
    
//    // initialize counters to zero      
//    numShp1=numShp2=count1=count2=0;
//
//    // read in data from file and initialize each player's game board[][]
//    // with a S(ship) or a B(blank)   
//    
//    char in1[]={'B','B','B','B','B','S','B','B','S','B','B','B','B','B','B','S'};
//    
//    for(int nRows=1; nRows<ROWS; nRows++){
//        for(int nCols=1,i=0; nCols<COLS ;nCols++,i++3){
//            
//            board1[nRows][nCols]=in1[i];  //inFile1>>board1[nRows][nCols];  
//            if(board1[nRows][nCols]=='S') { 
//                numShp1++;  // count how many ships player 1 has in their array
//            }
//            count1++;   // count how many items were read in
//            inFile2 >> board2[nRows][nCols];
//            if(board2[nRows][nCols]=='S'){
//                numShp2++;  // count how many ships player 1 has in their array
//            }
//            count2++;   // count how many items were read in
//        }        
//    }       

 
   
//    // fill guess[] [] with choices[]
//    fllGArr(guessP1,guessP2,choices,ROWS,COLS,p1GShps,p2GShps);     

    // show switch menu
//    runMenu(p1Name,ch,ans,count1,count2,numShp1,numShp2,guessP1,guessP2,board1,board2,
//       p1GShps,p2GShps,ROWS,COLS,maxGms,winner,SIZE7,names,SIZE8);

    
//    // display game's introduction message
//    string gameNme = "BATTLE";
//    banner(gameNme);  
//    
//    // get player 2's name from an array of names
//    cout << "\nLocating your opponent online......\n"; 
//    cout << setw(12) << p1Name << " vs " << name2 << "!" << endl;
//
//    pause();
//    
//    //***************************************
//    //******** GAME STARTS HERE**************
//    //***************************************
//              
//    // sets games flag & counting variables to their default values
//    p1_crrt = p2_crrt = false;     
//    rowIndx=colIndx=1;
//   
//    // loops until a player correctly guesses opponents ship location
//    while((!p1_crrt) && (!p2_crrt)){
//
//        rBanner(round); // display round number banner
//
//        //*************** Player 1's Guess ************* 
//        //**********************************************        
//      
//        instruc(p1Name,MAX);    // display instructions to player 1          
//
//        // set variables to the their 1st array's indices
//        p1Guess = guessP1[rowIndx][colIndx];
//        p2Ship1 = board2[rowIndx][colIndx];
//        showGuess(rowIndx,colIndx); // show players guess 
//
//        // checks if player1 guess is correct
//        if((p1Guess=='S') && (p2Ship1=='S')){                 
//
//            numShp2--;  // decrease number of ships player 2 has left                        
//            p1Win++;    // increment player 1 number of wins 
//            isHit=true;  // reset flag                            
//            hitMiss(isHit,p1Guess,p2Ship1);  // display HIT message for correct guess
//            chckArr(ans); // ask if they want to check arrays
//            
//            // validates user's input
//            ready=isReady(ans);
//
//            if(ready) {
//                
//                // display opposing 2D arrays to confirm it was a hit
//                plyrShpBrd(1,2,guessP1,board2,ROWS,COLS);
//                pause();
//            }
//
//            // checks if player 1's number of wins equals max games 
//            if(maxGms==p1Win) p1_crrt = true;   // reassign player 1's value for a correct guess                          
//                                                                              
//        } else { // else when player 1 guess is wrong 
//            isHit=false;    // reset flag
//            hitMiss(isHit,p1Guess,p2Ship1); // display MISS message for wrong guess
//        }
//
//        // conditional only runs if player 1 misses player 2's ship
//        if(!p1_crrt){
//
//            //**********************************************
//            //*************** Player 2's Guess *************
//            //**********************************************                
//
//            instruc(name2,MAX);  // display instructions to player 2                
//
//            // program generates random number guess
//            p2Guess = guessP2[rowIndx][colIndx];
//            p1Ship1= board1[rowIndx][colIndx];            
//            showGuess(rowIndx,colIndx);
//
//            // conditional checks if player 2's guess is correct
//            // program automatically generated  guess for player 2                           
//             if((p2Guess=='S') && (p1Ship1=='S')){  
//
//                numShp1--;  // decrement number of ships player 1 has                                        
//                p2Win++;    // increment player 2 number of wins
//                isHit=true;   // reset flag                                  
//                hitMiss(isHit,p2Guess, p1Ship1);    // display HIT message for correct guess  
//
//                chckArr(ans);
//
//                // conditional validates user's input
//                ready=isReady(ans);
//                if(ready){
//                    plyrShpBrd(2,1,guessP2,board1,ROWS,COLS);                   
//                    pause();
//                }
//
//                // checks to see if player has won the
//                if(maxGms==p2Win) p2_crrt = true;   // reassign player 1's value for a correct guess                          
//                
//            } else {  // else when player 2 guess is wrong 
//                isHit=false;
//                hitMiss(isHit,p2Guess,p1Ship1); // display MISS message for player 2's wrong guess  
//            }
//        } // ends player 2's turn
//        
//        // increment index that controls the guess[][] & board[][]
//        if(colIndx<=8) colIndx++;                           
//
//        // if both players guessed wrong, then       
//        if((!p1_crrt) && (!p2_crrt)){
//
//            // increases row and resets column
//            if( (colIndx>8) && (rowIndx<=2)) {
//                rowIndx++; 
//                colIndx=1;
//            }
//
//            // makes sure game ends if neither player  has guessed their opponents ship's location correctly
//            if(round>=16){
//                p1_crrt=p2_crrt=true;
//                cout<<"You've reached the max # of rounds.\n\n";
//
//            } else hitMiss();   // display try again message when both players guess wrong
//        }            
//    } // ends while(!p1_crrt) && (!p2_crrt)
//
//    // calculate total number of games won & number rounds played
//    ttlGmes = p1Win+p2Win;
//    ttlRnds += round; // sums the total number of rounds from all games
//    avgRnds = static_cast<float>(ttlRnds)/ttlGmes;
//    
//    // call function to display both player's scores
//    sBanner("SCOREBOARD", p1Name, name2, p1Win, p2Win);      
//    scoresMsg(ttlGmes, ttlRnds, avgRnds);     
//
//    pause();    // pause game so player can see the scores
//     
//    // **********************************************
//    // ******** SORT & SEARCH NAMES SECTION *********
//    // **********************************************
//    
//    // Sort & search names   
//    topPlyrs(names);
//
//    // write scores and averages to file
//    outFile << fixed << showpoint << setprecision(2);
//    outFile << "Player 1 wins: " << p1Win << endl
//            << "Player 2 wins: " << p2Win << endl
//            << ttlGmes << " of " << maxGms << " max games were played.\n";
     
    // close files being read in and written to
    //inFile1.close();   
    //inFile2.close();    
    //outFile.close();   

    // exit code
    return 0;
}

//*********************************************************************
/*                              STL                                   */
//*********************************************************************

// function controls the sort and search section
void topPlyrs(unordered_set<string> &names){ 
    
    // Initialize unordered map with pair(topPlyrs,scores)
    std::map<string, float> topPlyrs; 
    topPlyrs = setTopPlyrs(names);
   
    // bubble sort names & print sorted array
   
    // Print map (key,value) pairs of high scores
    cout << "\nSorted: This week's Top Players \n";
    prntMapUnO(topPlyrs);
    
    string sName;
    cout<<endl<<endl<<"Enter a player's name to return\nwhat place they're in this week. ";
    cin >> sName; cout<<endl;
    // using transform() function and ::toupper in STL 
    transform(sName.begin(), sName.end(), sName.begin(), ::toupper); 
    auto it = topPlyrs.find(sName); 
    if(it==topPlyrs.end()){
       cout<<"Sorry, "<<sName<<" wasn't found.\n";
    } else { 
        // Finds player's spot in score board
        int count=1;
        for(auto i=topPlyrs.begin(); i!=it;i++,++count){}
        cout << (*it).first <<" is in the "
             << count<<" spot of this week's top player\nwith "
             << (*it).second <<" points.\n\n";
    }
    
    //pause(); // pause game so player can view the search findings
   
    // Sorts last week's top scores. 
    //sortSel();   
  }


// Initialize unordered map with pair(topPlyrs,scores)
std::map<string, float> setTopPlyrs(unordered_set<string> &names){     
    float scores[]={98.98, 99.69, 99.81, 99.43, 101.9, 99.71, 99.24, 99.78}; 
    int j=0; 
    std::map<string, float> topPlyrs;  
    std::map <string,float>::iterator itmap = topPlyrs.begin();
    std::unordered_set<string>::iterator itr = names.begin();
    
    // Initialize map with a pair("name", hiScore)
    for (itr = names.begin(); itr!=names.end(); itr++) {      
        topPlyrs.insert( 
        std::pair<std::string, float>(*itr, scores[j])); 
        //cout<<"j="<<j<<" ("<<*itr<<", "<<scores<<") "<<endl;
        j++; 
    }    
    // Print map (key,value) pairs of high scores
    cout << "\nUnsorted: This week's Top Players \n";
    prntMapUnO(topPlyrs);
    return topPlyrs;
}
 

// Push string to front of set
unordered_set<string> pushFrntSet(string p1Name,string &name2){
    
    // Initialize set with string array values
    unordered_set<string> p2Names = setP2Names(p1Name,name2);    
    //cout<<"set<string> p2Names =\n";
    //prntStrSet(p2Names);  
    
    
    // copy all of player 2's name into a new array 
    unordered_set<string> names(p2Names.begin(), p2Names.end());   

    // add player 1's name to the end of the names[] 
    names.insert(p1Name);
    //cout<<"Combined 2 sets and then inserted "<<p1Name<<" in front:\n";
    //prntStrSet(names);
    return names;
}


unordered_set<string> setP2Names(string p1Name,string &name2){    
    // Copy array to a set
    string nameAry[]={"MARTY", "BART", "ALEX", "CHRIS", "GABE", "VICTOR", "JILLIAN"}; 
    int n = sizeof(nameAry)/sizeof(nameAry[0]);
    name2=nameAry[rand()%(n)];    
    unordered_set<string> p2Names;    
    for(int i=0;i<n;i++){ p2Names.insert(nameAry[i]);}
    //prntStrSet(p2Names);    
    return p2Names;
}

// Print map (key,value) pairs of topPlyrs & high scores
void prntMapUnO(map<string, float> &map){
    int i=1;
    std::map <string, float>::iterator itmap = map.begin();
    cout<<"Map Top Player's Scores\n";
    for (itmap = map.begin(); itmap!=map.end(); itmap++) {
        cout<<i++<<". "<<"("<<setw(8)<<left
            << itmap->first <<","<< itmap->second <<")\n";
    }
}

// Prints names set container
void prntStrSet(unordered_set<string> &set){
    int i=1;
    std::unordered_set<string>::iterator itr;
    for (itr = set.begin(); itr != set.end(); itr++) {
        cout<<i++<<". "<<*itr<<endl;
    }
    cout<<endl<<endl;
}



//*********************************************************************
//*             Array FUNCTION                                        *
//*********************************************************************


//// selection sort with vectors
//void sortSel(){    
//   
//    vector<string> vNames{"MICKEY", "JERRY", "STEPH", "MARTY", "BART", "MOM", "ROBERT", "GAMER1"};
//   
//    cout << "\nLast Week's Top Players \n";
//    for(auto ele : vNames)
//        cout << ele << endl;
//    cout << endl;
//    
//    int    minIndx, last=0; 
//    string minVal;    
//    
//    last=(vNames.size()-1); // don't need to go the last index cause we check it by the end of loop's 1st run
//    
//    for(int start=0; start<last; start++){
//        
//        minIndx = start; // set smallest index to zero
//        minVal=vNames[start]; // set smallest value to array's 1st index
//        
//        // start loop at array's[1]
//        for(int indx=(start+1);indx<vNames.size();indx++){            
//        
//            // if its neighbor index is smaller than it
//            if(vNames[indx] < minVal){ 
//                
//                // reassign smallest to that array's index and its value
//                minVal = vNames[indx];
//                minIndx = indx;
//            }  
//        } // swap their values
//        swap1(vNames[minIndx], vNames[start]);
//    }    
//    cout << "Vector Selection Sort: Last Week's Top Players \n";
//    for(auto ele : vNames)
//        cout << ele << endl;
//    cout << endl;
//}
//
//// swap indices
//void swap1(string &a, string &b){
//    
//    string temp;
//    temp=a;
//    a=b;
//    b=temp;
//}
//
//// displays each players scores and win average
//void scoresMsg(int ttlGmes, int ttlRnds, float avgRnds){
//    
//    showStatic(); // show how many games have been played
//    cout << fixed << showpoint << setprecision(2); 
//                cout << "Averages for " << ttlGmes << " games \n"
//                     << "Total # of rounds played: " << ttlRnds << endl                    
//                     << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
//                     << ceil(avgRnds) << endl;
//}
//
//// show each players guess 
//void showGuess(int row,int col){
//    char colLttr = col==1 ? 'A':
//                   col==2 ? 'B':
//                   col==3 ? 'C':
//                   col==4 ? 'D':
//                   col==5 ? 'E':
//                   col==6 ? 'F':
//                   col==7 ? 'G':
//                   col==8 ? 'H': '?';
//   
//    cout << setw(13) << "Col " << colLttr 
//         << " Row " << row <<endl;   
//}
//
//// static variable for games
//void showStatic(){
//    static int games=1;
//    cout << "\nTotal # Games Played = " << games << endl;
//    games++;
//}
//
//// display scoreboard banner
//void sBanner(string str, string p1Name, string name2, int p1Win, int p2Win){
//    
//    
//    // Display scoreboard banner       
//        for(int k=0; k<=2; k++){
//            ((k==0)||(k==2)) ? cout << "********************************\n"
//                    : (k==1) ? cout << setw(21) << str << endl
//                    : cout << "Error in scoreboard banner.\n";
//        }
//        cout << setw(7) << " " << p1Name << setw(4) << "vs" << setw(3) << " " 
//             << right << name2 << endl;
//        cout << setw(8) << p1Win << setw(16) << p2Win << endl;
//}
//
//// banner displays round number
//void rBanner(int &r){
//        ++r;
//        cout << endl << setw(26) << "********************************" << endl;
//        cout << setw(18) << "Round " << r << endl;
//        cout << setw(26) << "********************************" << endl;                     
//}
//
//// prntArr []
//void prntArr(const char arr[][9],int ROWS, int COLS){
//    for(int pRows=1; pRows<ROWS; pRows++){         
//        for(int pCols=1; pCols<COLS; pCols++){
//            cout << arr[pRows][pCols] << "  ";           
//}}}
//
//// prntArr names[]
//void prntArr(string arr[]){
//    for(int i=0;i<8;i++){ cout << i+1 << ". " << arr[i] << endl;}
//    cout << endl;
//}
//
//// 
//void print2DArr(const char guessP1[][9], const char guessP2[][9],
//                const char board1[][9],const char board2[][9], 
//                const int ROWS,const int COLS,int &maxGms,int &winner){
//    
//    unsigned int hit1,hit2,rIndx1,rIndx2,cIndx1,cIndx2;
//    char g1,g2,b1,b2;
//    hit1=hit2=rIndx1=rIndx2=cIndx1=cIndx2=0;
//    
//    // get how many ship hits each player should get during this game
//     for(int pRows=1; pRows<ROWS; pRows++){        
//        for(int pCols=1; pCols<COLS; pCols++){
//            g1=guessP1[pRows][pCols];
//            b2=board2[pRows][pCols];
//            if((g1=='S') && (b2=='S')){
//                hit1++;
//                if(hit1==1){
//                rIndx1=pRows;
//                cIndx1=pCols;
//                }
//            }
//        }         
//    }
//    for(int row2=1; row2<ROWS; row2++){    
//        for(int col2=1; col2<COLS; col2++){            
//            g2=guessP2[row2][col2];
//            b1=board1[row2][col2];
//            if((g2=='S') && (b1=='S')){
//                hit2++;
//                if(hit2==1){                   
//                rIndx2=row2;
//                cIndx2=col2;
//                }
//            }
//        }         
//    }
//    
//    // sets max number of games and returns which player to use for a conditional in main()
//    if(hit1>hit2){
//        maxGms=hit1;
//        winner=1;
//    }else if(hit1<hit2) {
//        maxGms=hit2;
//        winner=2;
//    } else{
//        maxGms=hit1;
//        winner=2;
//    }
//    
//    plyrShpBrd(1,2,guessP1,board2,ROWS,COLS); 
//    cout << "\nPlayer 1 expected # of HITS: "<< hit1 << endl
//         << "1st HIT in round [" << rIndx1<<"]["<<cIndx1<<"]" <<endl<<endl;  
//   
//    plyrShpBrd(2,1,guessP2,board1,ROWS,COLS); 
//    cout << "\nPlayer 2 expected # of HITS: " << hit2 << endl
//         << "1st HIT in round [" << rIndx2 <<"]["<<cIndx2<<"]" <<endl<<endl;          
//}
//
//// 
//void plyrShpBrd(int player,int opponnt,const char guess[][9],const char board[][9], 
//                const int ROWS,const int COLS){
//    
//    cout << endl << setw(19)<<" "<< "A1 B1 C1 D1 E1 F1 G1 H1 A2 B2 C2 D2 E2 F2 G2 H2\n";
//         
//    cout << "Player "<<player<< " Guesses:  ";    
//    prntArr(guess,ROWS,COLS);
//    cout << endl;
//    
//    cout << "Opponent's Board:  " ;
//    prntArr(board,ROWS,COLS);
//    
//}
//
//
//
//
////  prompt user  
////void runMenu(string p1Name, char &ch, char &ans, int count1,int count2,int numShp1,int numShp2,
////             char guessP1[][9],char guessP2[][9],char board1[][9],char board2[][9],
////             int p1GShps,int p2GShps,int ROWS,int COLS,int &maxGms, int &winner,
////             int SIZE7,unordered_set<string> &names,int SIZE8){
////    do {
////         
////        cout << endl << p1Name << " your game has successfully loaded. \n"
////             << "Press 1: to see a summary of the files that were read.\n"
////             << "Press 2: to confirm Guess[][] filled correctly\n"
////             << "Press 3: to confirm my game board[][] was read the data in correctly\n"
////             << "        and to that the guess[][] were randomly filled.\n"
////             << "Press 4: to start your game.\n"
////             << "Press 5: to run Top Player's Board.\n"
////             << "Press 6: to exit.\n";
////        cin  >> ch;
////
////        switch(ch){       
////            case '1': fileSum(count1,count2,numShp1,numShp2); break;
////            void cGssArr(const char [][9], const char [][9],const int,const int,int, int); // confirms guess[][] filled correctly
////
////            case '2': cGssArr(guessP1, guessP2,ROWS,COLS,p1GShps,p2GShps);break;
////            case '3': print2DArr(guessP1, guessP2,board1,board2,ROWS,COLS,maxGms,winner); break;       
////            case '5': topPlyrs(names);// Sort & search names  
////            case '6': exit(EXIT_SUCCESS); break;
////            default: cout << setw(9)<< " " << "Loading.......\n";
////        }
////
////        if(ch=='1' || ch=='2' || ch=='3'|| ch=='5'){    
////            cout << "Run Menu again?\n";
////            cin >> ans;
////        } else ans='n';
////    
////    // continue doing all the statements above until ans does not equal y or Y
////    } while((ans=='y')||(ans=='Y')); 
////}
//
//// validates user's input
//bool isReady(char ans){
//    // conditional validates user's input
//    if(ans=='y'){                
//        return true;
//    } else if(ans=='Y'){                
//        return true;
//    } else return false;            
//}
//
//// display instructions to player
//void instruc(string player, const int MAX, int min){
//    
//    cout << endl << setw(2) << " " << "Try to guess the location of \n"
//         << setw(6) << " " << "your opponent\'s ship." << endl
//         << endl << setw(12)<< " " << player  << endl 
//         << setw(2) << " " << "Guess a letter between A-H\n"
//         << setw(2) << " " << "and a number between " << min << " and " << MAX/8 << endl;
//}
//
//// display hit message when player guesses correctly
//void hitMiss(bool isHit, int guess, int shipLoc){
//    
//    cout << setw(13) << static_cast<char>(guess) << " == " << static_cast<char>(shipLoc) << endl;   
//    
//    if(isHit) cout << setw(20) << "It\'s a HIT!\n" << endl;
//    else cout << setw(22) << "It\'s a MISS!\n";
//}
//
//// display try again message when both player's guessed wrong
//void hitMiss(){
//    cout << endl << "You Both Missed. Try Again..." << endl << endl;
//}
//
//// get player 1's name
//void getName(string &name1){          
//    //cout << "\nPlayer 1: Enter your name ";
//    //cin >> name1; cout << endl;   
//    // using transform() function and ::toupper in STL 
//    transform(name1.begin(), name1.end(), name1.begin(), ::toupper);
//}
//
//// randomly fill guess[][] until at least one of the player's has 3 ships in their array
//void fllGArr(char guessP1[][9],char guessP2[][9],char choices[],int ROWS,int COLS,int &p1GShps, int &p2GShps){
//    int size=17;
//    p1GShps=p2GShps=0;  // initialize both players number of ships to zero
//    bool minMet;        // minimum number of ships==3
//
//    do{
//        minMet=false;   // set flag
//
//        for(int gRow=1; gRow<ROWS; gRow++){
//            for(int gCol=1; gCol<COLS; gCol++){
//
//                // automatically set player 1's guess[][] randomly from choices[] 
//                guessP1[gRow][gCol]=choices[rand()%size]; // saves either a 'S' or 'B' 
//
//                // track how many ships player 1's array has
//                if(guessP1[gRow][gCol]=='S'){
//                    p1GShps++;                    
//                    if(p1GShps==3) minMet=true;   // reassign value to flag                                           
//                }
//                // automatically set player 2's guess[][] randomly from choices[] 
//                guessP2[gRow][gCol]=choices[rand()%size]; 
//
//                // track how many ships player 1's array has
//                if(guessP2[gRow][gCol]=='S'){
//                    p2GShps++; 
//                   if(p2GShps==3) minMet=true;   // reassign value to flag
//                }
//            }        
//        }       
//    } while(!minMet); 
//}
//
//// confirm data that was read in is even and contains at least 3 ships
//void fileSum(int count1, int count2, int numShp1, int numShp2){   
//    cout << endl << setw(3)<<" " << "Read in " << setw(6)<< " " << "P1 Board" << setw(5)<< " "<< "P2 Board" << endl;
//    cout << "Total # chars " << setw(8) << right << count1 << "\t \t" << count2 << "\n";
//    cout << "Total # ships " << setw(8) << right << numShp1 << "\t \t" << numShp2 << "\n\n";    
//}
//
//
//// 
//void chckArr(char &ans){
//    cout << "Would you like to confirm it was a hit? ";
//    cin >> ans;
//}
//
//// display data from both player's guess arrays. 
//void cGssArr(const char guessP1[][9], const char guessP2[][9],
//             const int ROWS,const int COLS, int p1GShps, int p2GShps){
//    
//    cout << "\nConfirming Guess arrays are random and have at least 3 S in one array\n";
//    cout << setw(4) << " " << "P1 Guesses"<<endl; 
//    prntArr(guessP1,ROWS,COLS);
//    cout <<"\nP1 # Ships : " << p1GShps <<endl<<endl;
//    
//    cout << setw(4) << " " << "P2 Guesses\n";
//    prntArr(guessP2,ROWS,COLS);
//    cout << endl << "P2 # Ships : " << p2GShps << endl<<endl;         
//}
//
//// displays game's name and instructions in a banner
//void banner(string str){    
//    // reassign variables value
//    str="BATTLESHIP";     
//    for(int i=0; i<=2; i++){
//        if(i==0 || i==2){
//            for(int j=0; j<32; j++) {
//                cout << "*";       
//            } cout << endl;
//        } else  cout << setw(21) << str << endl;               
//    }        
//}

// pause screen before game starts
void pause(){    
    cout << "\nPress enter to continue. ";
    cin.ignore();
    cin.get();   
}
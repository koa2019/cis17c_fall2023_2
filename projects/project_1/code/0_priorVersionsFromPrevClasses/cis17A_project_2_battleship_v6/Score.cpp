#include "Score.h"
#include <iostream>   //Input/Output Library
#include <iomanip>  // fixed, setprecision()
#include <cstring>  // char [] library
#include <string>   // length() library
#include <cctype>  //toupper()
#include <bits/stdc++.h>
using namespace std;

//***********************************************************
//     Default constructor 
//***********************************************************
Score::Score(){
    cout<<"Hit Score Constructor\n"; 
    maxGmes = 5;
    ttlGmes = 0;
    ttlRnds = 0;   
    MAX = 19;    // maximum number for rand()       
    indx1 = 0;   // index for player 1's name
    indx2 = 1;   // index for player 2's name
    maxGmes = 3; // number of games
    nGmsLft = maxGmes; // number of games left       
    round = 1;    // round
    
    /*  Code below is from cis17b_Yahtzee_v29*/
    nPlayer = MINSIZE; 
    p1Winner = false;
    
    // Create array of index to keep track of each player
    indx = new int[nPlayer];
    
    // Initialize array
    for (int i=0; i < nPlayer; i++) {         
        indx[i] = i;
    }
  
    // creating double pointers. An array of Classes
    player = new Player*[nPlayer]; 
    
    // BUG! IN Player::Constructor#2
    //    // Creating each individual player by calling User constructor 
    //    // Every player is initially set with a name of Player i
    //    // change player 1's name inside of play();    
    //    for (int i = 0; i < nPlayer; i++) {  
    //        
    //        int num = i+1;
    //        stringstream stream;  // convert int to string
    //        stream << num;
    //        string str2;
    //        stream >> str2;  // save converted int to a string variable
    //        string str1 = "Player " + str2;
    //        cout<<"str1 = "<<str1<<endl;
    //        player[indx[i]] = new Player(str1); // Constructor#2
    //    } 
    player[0] = new Player;
    player[1] = new Player;
    //player[0] = new Player("Player 1"); // Constructor#2
    //player[1] = new Player("Computer"); // Constructor#2
    cout<<"End Score Constructor\n"; 
    start();
}

//**********************************************************
//              Controls rounds
//**********************************************************
//bool Yahtzee::startGame(User &user, const long recordLoc){
//bool Score::start(Player &user){//passing guest user or logged user
bool Score::start(){        
    
    //********************************************
    //         Battleship play starts here
    //********************************************

    // read in maximum number of games that can be played from file
    nGmsLft = getMaxGmes(); // set numberOfGamesLeft to equal maxGames
    
    while (nGmsLft>0) {
       
        // sets variables to default starting values
        p1_crrt = p2_crrt = false;

        // display game's introduction message 
        getBanner("BATTLESHIP");        
        cout<<"\n\t"<<player[indx[0]]->getName()<<" vs "<<player[indx[1]]->getName()<<endl;
        
        // loops until a player correctly guesses opponents ship location
        while ((!p1_crrt) && (!p2_crrt)) {

            // display round number banner
            rBanner();

            // Player 1's Guess                       
            p1_crrt = play(indx[0],indx[1]);
            pause();
            
            // If player 1's turn is over
            if(!p1_crrt){ 
                // Player 2's Guess  
                p2_crrt = play(indx[1],indx[0]);   
                pause();
            }

            // if both players guess wrong, then display message 
            if ((!p1_crrt) && (!p2_crrt)) {
                cout << endl << "  You Both Missed. Try Again...\n\n";
                pause();
            }
            
        } // ends while((!p1_crrt) && (!p2_crrt))
        
        // Game over
        nGmsLft--;
        
        try {setTtlGmes(nGmsLft);}            
        catch(Score::NegativeGames){cout<<"Error. Negative games.\n";}         
        
        prntScore();
         
        // checks maximum number of games has NOT been played
        if(nGmsLft>0) {pause();}          
           
        // reset variables for next game
        round=1;          
        p1_crrt = p2_crrt = false; 
        
    } // ends while(nGmsLft> ZERO)
 
    return p1Winner;
}


//****************************************************************
//      Player's guess is random number between [0,19]
//     Returns if player's guess is correct or not     
//****************************************************************
bool Score::play(int a,int b){
   
    cout<<setw(1)<<" "<<player[a]->getName()<<" Guess a number between 0-19\n\n";         
    int num = rand()%19;    
    player[a]->setGuess(num);
    
    int guessIndx = player[a]->getGuess(); 
    
    // get 1 guess board element from Choices class
    char oppntPos = player[b]->get1gBrdElmnt(guessIndx);
    
    cout<<player[a]->getName()<<"'s random guess index: "<< guessIndx<<"\n";   
    cout<<player[b]->getName()<<"'s  guessBoard["<<guessIndx<<"] "<<oppntPos<<endl<<endl;

    // checks if player guess is correct
    //if (pGuess == player[b].shipLoc) {
    if(oppntPos=='S' || oppntPos=='s') { 
        player[a]->setWins();                             
        player[a]->setIsRight(true);
        setTtlRnds(round); // sums the total number of rounds from all games        
        hitMiss(guessIndx,oppntPos,true);//(pGuess,i,isHit) 
        return true;      
    } 
    else{
        // if player guess is wrong display MISS message 
        player[a]->setIsRight(false);   
        hitMiss(guessIndx,oppntPos,false);//(pGuess,i,isHit)  
        char ans='Y';
        while(ans=='Y'){
            cout<<"Would you like to see the game boards? Y/N\n";
            cin>>ans;
            if(ans=='Y' || ans=='y'){ prntP1P2Brd();}
            return false;
        }
    }       
    return false;
}

//******************************************
//      banner displays round number
//******************************************
void Score::rBanner() {  
    cout << endl << setw(26) << "********************************" << endl;
    cout << setw(18) << "Round " << round << endl;
    cout << setw(26) << "********************************" << endl;
    round++;
}


//////***********************************************************
//////    Constructor #2
//////***********************************************************
////Score::Score(string name){
////    setName(name);
////    maxGmes = 3;
////    ttlGmes = 0;
////    ttlRnds = 0;
////}
//
//////***********************************************************
//////    Constructor #3
//////***********************************************************
////Score::Score(int maxGam){
////    setName("Guest 3");
////    maxGmes = maxGam;
////    ttlGmes = 0;
////    ttlRnds = 0;
////}
//
////***********************************************************
////   Copy constructor
////***********************************************************
//Score::Score(const Score &obj) {
//    maxGmes = obj.maxGmes;
//    ttlGmes = obj.ttlGmes;
//    ttlRnds = obj.ttlRnds;
//}

//***********************************************************
//   set total games with try,catch, throw
//***********************************************************
void Score::setTtlGmes(int num){    
    if(num>=0) {ttlGmes = num; }      
    else {throw NegativeGames();}
}

//***********************************************************
//  Print scoreboard. Need to inherit player[0] & [1]
//***********************************************************
void Score::prntScore(){ 

    // Display scoreboard banner  
    string str="SCOREBOARD";
    getBanner(str);
    
    cout<<"\n\tMax Hits: "<< maxGmes << endl;
    cout <<"         "<< ttlGmes << " hits left.\n";
    cout << "   Total rounds played this game: " << ttlRnds << endl << endl;
    
    // LOOK for shipLoc in prior versions and fix print out
    //cout <<player[0]->getName()<<"'s Ship Location:   " << player[0]->shipLoc << endl
         //<<player[1]->getName()<<"'s Ship Location:   " << player[1]->shipLoc << endl << endl;
//
//    for (int p=ZERO; p< player[p].rows; p++) {//        
//        cout << "         Player "<<p+1<<"'s Game board \n";//        
//        for (int row = 0; row < player[p].rows; row++) {//            
//            for (int col = 0; col < player[p].cols; col++) {   
//                cout<< "&" << player[p].board[row][col];
//                if(col%TEN==NINE) cout<<endl;
//            }           
//        }
//    }    
    prntP1P2Brd();
    cout << endl << endl;
}

void Score::prntP1P2Brd(){
    // Game ends & Prints each player's game board
    cout<<"\n\n\t\t"<<player[indx[0]]->getName()<<"'s Game Board\n";
    player[indx[0]]->printGBoard();       
    cout<<"\t\t"<<player[indx[1]]->getName()<<"'s Game Board\n";
    player[indx[1]]->printGBoard();   
}
//******************************************************************************
//      Displays game's name and instructions in a banner
//******************************************************************************
void Score::getBanner(string title) {

    cout << "\n********************************\n" << setw(21) << title << endl;
    cout << "********************************\n";
    cout << setw(10) << setfill(' ') << player[0]->getName()
         << setw(6) << setfill(' ') << right << "vs"
         << setw(10) << player[1]->getName() << endl;
    
    if (title=="SCOREBOARD") {
        cout << setw(8)  << player[0]->getNumWins()
             << setw(14) << player[1]->getNumWins() << endl;
    } else {
        cout << setw(2) << " " << "\n   Try to guess the location of \n"
             << setw(6) << " " << "your opponent\'s ship." << endl;
    }
}



//******************************************************************************
//  Display hit message when player guesses correctly
//******************************************************************************
void Score::hitMiss(int &pGuess, char &i, bool isHit) {
    if (isHit) {
        cout << setw(12) << pGuess << " == " << i << endl;
        //cout << setw(12) << pGuess << " == " << player[b].shipLoc << endl;
        cout << setw(22) << "It\'s a HIT!\n" << endl;        
    } else {
        cout << setw(12) << pGuess << " != " << i << endl;
        cout << setw(15) << pGuess << endl << setw(22) << "It\'s a MISS!\n";
    }
}

//******************************************
// pause screen before game starts
//******************************************
void Score::pause() {
    cout << "\nPress enter to continue. \n\n";   
    cin.get();
    //cin.ignore();
}






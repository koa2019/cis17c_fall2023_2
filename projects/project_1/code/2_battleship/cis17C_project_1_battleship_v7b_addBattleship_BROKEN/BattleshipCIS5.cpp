#include <iostream>
#include <iomanip>
#include "BattleshipCIS5.h"
//#include "ScoreCard.h"   // aggregates instance of ScoreCard class
#include "User.h"       // aggregates instance of User class
using namespace std;
//**********************************************************
//                  Default Constructor
//**********************************************************
Battleship::Battleship() {
    
    nPlayer = MINPLAYRS; 
    p1Winner = false;
    
    // Create array of index to keep track of each player
    indx = new int[nPlayer];
    
    // Initialize array
    for (int i=0; i < nPlayer; i++) {         
        indx[i] = i;
    }
  
    // creating double pointers. An array of Classes
    player = new User*[nPlayer]; 
    
    
    // Creating each individual player by calling User constructor 
    // Every player is initially set with a name of Player i
    // Player 1's name will be changed inside of play()    
    for (int i = 0; i < nPlayer; i++) {          
        int num = i+1;
        stringstream stream;  // convert int to string
        stream << num;
        string str2;
        stream >> str2;  // save converted int to a string variable
        string str1 = "Player " + str2;
        player[indx[i]] = new User(str1); 
    }
        
}


//**********************************************************
//              Controls rounds
//**********************************************************
bool Battleship::startGame(User &user, const long recordLoc){
    
    // Reset player 1's name with user's name
    player[indx[0]]->setName(user.getName());    
    
    // Create array for player's name
    string name[nPlayer] = {player[indx[0]]->getName(), player[indx[1]]->getName() };
    
    //setNPlayer();  // Get number of players
    //getRules(); // Print rules    
    
    
    // f user selected 2 player game, then print message 
    if(nPlayer > 1){cout<<endl<<setw(20)<<name[0]<<setw(4)<<" vs "<<name[1]<<endl;} 
    pause();
     
    // Game runs for 13 rounds. 1 round per category
    for (int rnd = 0; rnd < MAXHITS ; rnd++) {

        // Player 1's turn begins
        prntRound(rnd);       
        //finalSC[indx[0]].setRound(rnd+1);
        play(indx[0], rnd); 

        // If user selected 2 player game, then begin player 2's turn
        if(nPlayer > 1 && rnd < MAXHITS) {             
            //finalSC[indx[1]].setRound(rnd+1);
            play(indx[1], rnd); 
        }       
     } // ends round for(rnd < 13 )            

    p1Winner=true;
    //setP1Winner(finalSC, name);  // Print player's final scorecards
    return p1Winner;
//    if(!p1Winner){ // if player 1 is NOT winner        
//        cout<<"\n\nGood Game!\n"; 
//        return false;         
//    } else {
//        return isNewHiScore(user,recordLoc); // return whether or not p1 has new hiScor
//    }
}


//**********************************************************
//              This player's turn
//**********************************************************
void Battleship::play(int a, int &rnd){
   
}

void Battleship::prnt2PlyrBrd(){
//    cout<<"\nPlayer Game Board:\n"; 
//    player[indx[0]].getBrd(indx[0]);//prntBrd(board);
//    cout<<"\nPlayer Guess Board:\n";
//    player[indx[0]].getGuesBrd(indx[0]);//prntBrd(guesBrd);
//    cout<<"\n\n\nPlayer 2 Game Board:\n";
//    prntBrd(board2); 
//    cout<<"\nPlayer 2 Guess Board:\n";
//    prntBrd(guessP2); 
}

//*****************************************************************
//              Select category to save to final scorecard
//*****************************************************************
//void Battleship::selectCategory(int a, string name, int rnd){
//    
//   a = (a<0) ? 0 : a;
//   rnd = (rnd<0) ? 0 : rnd;
//   
//   // Ask player to pick category & set player's final scorecard object                
//   finalSC[indx[a]].setFinalSC(scorecard[indx[a]]);  
//   
//
//   // set player's total score each time finalSC is changed
//   player[indx[a]]->setHiScore(finalSC[indx[a]].getTotalScore());
//
//
//   // Only print finalSC when it's NOT the last round
//   // if it's NOT the last round, then print player's final scorecard
//   if(rnd != MAXHITS-1){ 
//       finalSC[a].printFinalSC(name); 
//   }
//
//    else { // If it IS the last round AND there is 2 players,
//          // AND it's player 1's turn, then print their final scorecard
//       
//       if((nPlayer > 1) && (a == 0)){ 
//           finalSC[a].printFinalSC( name); 
//       
//       } else { 
//           cout<<"Tallying your final score...\n"; 
//           pause();
//       }
//    }
//}

    
//*****************************************************************
//          Get winner and Print player's final scorecard 
//*****************************************************************
//
//bool Battleship::isNewHiScore(User &user, const long recordLoc){
//             
//    /* Player 1 represents the user object. ONLY change their values if p1 wins.
//       Check is p1's score from this game is larger than their hiScore stored in binary file */
//    if(user.isHiScore( player[indx[0]]->getHiScore() )){            
//
//        // Reset user's hiSCore and update binary & text file            
//        user.setHiScore( player[indx[0]]->getHiScore() );
//
//        cout << "\n\tNew High Score of " << user.getHiScore() << "!\n";
//        //user.printUsr();
//
//        // Certain printout depending on if User is logged in or not
//        if(user.getName() == "Guest"){ cout<<"\n\tSign up or Login to save your score.\n"; }
//
//        else { 
//            user.reWrtBin(recordLoc); // rewrites this record in binary & text files 
//            cout << "\nUpdating binary...."; 
//        }
//        return true; // player 1 HAS new high score                
//    } 
//        
//    return false; // player 1 does NOT have new high score 
//}
    

//*****************************************************************
//          Get winner and Print player's final scorecard 
//*****************************************************************

//void Battleship::setP1Winner(ScoreCard finalSC[], string name[]){
//   
//    
//    //finalSC[0].setRound(MAXHITS);            // Set round to last round for each player, so it'll 
//    //finalSC[1].setRound(MAXHITS);            // check if they hit upperScore bonus in printFinalSC()
//    finalSC[0].printFinalSC( name[0] ); // Print player 1's final scorecard 
//    
//    if(nPlayer > 1) { finalSC[1].printFinalSC( name[1] ); }  // Print player 2's final scorecard 
//    
//    cout << "\n\n\t\tGame Over!\n";
//    
//    if(nPlayer > 1) { // If there is more than 1 player
//    
//        cout << endl << setw(20) << name[0] << setw(4) << " vs " << name[1] << endl;
//        cout << setw(20)  << player[0]->getHiScore() << setw(4) << " vs " << player[1]->getHiScore();
//        
//        string msg;
//        
//        // Check is p1 is winner, tie or loser
//        if( player[0]->getHiScore() > player[1]->getHiScore() )
//        {
//           msg = name[0] + " won!\n"; 
//           p1Winner = true;
//            
//        } else if(player[0]->getHiScore() == player[1]->getHiScore()){
//        
//            msg ="Tie Game!\n";
//            p1Winner = true;
//            
//        } else { 
//            
//            p1Winner = false; 
//            msg = "Uh-Oh..." + name[1] + " won!\n";
//        }
//        
//        cout << "\n\n\t\t" << msg ;
//        
//    } else { p1Winner = true; } // if nPlayer == 1, then p1 automatically winner
//}


//*****************************************************************
//        Print player's options and return their choice
//*****************************************************************
void Battleship::displayOptions(int &ans) {
    
    cout << "\nOptions:" << endl;
    cout << "1: Select which dice you want to keep\n   before rolling again." << endl;
    cout << "2: Pick category and end your turn" << endl;
    cout << "3: Roll again." << endl;
    cout << "4: Exit" << endl;
    cout << "Enter a number: ";    
    
    while (!(cin >> ans) || ans < 1 || ans > 4) {
        cout << "Invalid choice. Please enter a number between 1 and 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


//****************************************************
//              Get # of player & validate input
//****************************************************
void Battleship::setNPlayer(){
    
    const int MAXPLYR = 2;
    int num = 1;
    do {
        cout<<"\n\nHow many players?\nEnter number between 1 and 2:  ";
        cin >> num;
    } while(!(num >= 1 && num <= MAXPLYR));
    nPlayer = num;
    cin.ignore();
}


//******************************************
//              Print round
//******************************************
void Battleship::prntRound(int i){    
    i = (i < 0 ) ? 0 : i;    
    cout << endl << endl;
    cout << "|" << string(40, '-') << "|" << endl;
    cout << "|" << setw(20) << "Round " << i + 1 << setw(20) << "|" << endl;
    cout << "|" << string(40, '-') << "|" << endl;
}


//******************************************
//      pause screen before continuing
//******************************************
void Battleship::pause(char ch) {    
    string msg = ch=='r' ? "roll" : "continue";    
    cout<<endl<<setw(6)<<' '<<"Press enter to " << msg << ".";   
    cin.get();
}


//******************************************
//          Print rules
//******************************************
void Battleship::getRules(){    
    cout << "WELCOME TO YAHTZEE!!" << endl << endl;
}
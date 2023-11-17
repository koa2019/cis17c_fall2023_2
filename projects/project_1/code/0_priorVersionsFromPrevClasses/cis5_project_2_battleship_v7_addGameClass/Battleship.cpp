#include "Battleship.h"
#include <bits/stdc++.h> 
#include <fstream>  // ofstream 
using namespace std;

//******************************************************************************
//                     Default Constructor
//                       SET UP GAME 
//******************************************************************************

Battleship::Battleship() {

    // sets games flag & counting variables to their default values
    ans = ' '; // answer  
    ch = ' ';
    p1Guess = 0; // player 1 guess
    p2Guess = ' '; // player 2 guess
    p1Ship1 = ' '; // player 1 ship number 1
    p2Ship1 = ' '; // player 2 ship number 1
    p1_crrt = false;
    p2_crrt = false;
    ready = false;
    isHit = false;
    rowIndx = 1;
    colIndx = 1;
    maxGms = 0; // number of games
    round = 0; // round   Board.h              
    p1Win = 0; // number of wins player 1 has
    p2Win = 0; // number of wins player 2 has
    ttlGmes = 0; // sum of both players number of wins
    ttlRnds = 0; // sum of total rounds played
    winner = 0;
    avgRnds = 0.0f; // average rounds it takes to win
    p1Name = "Danielle";
    p2Name = "Computer";

    // will be used to fill each player's guess[][]
    string p2Names[] = {"MIKE", "BART", "JANIS", "STEPHANIE", "TING", "VICTOR", "JILLIAN"};
    string names[8] = {}; // create new array to hold player 1 & player 2's names
    vector<string> vNames{"VICTOR", "DANI", "STEPHANIE", "MIKE", "BART", "JANIS", "MICHELLE", "JILLIAN"};





    //    // show switch menu
    //    runMenu(p1Name,ch,ans,count1,count2,numShp1,numShp2,guessP1,guessP2,board1,board2,
    //       p1GShps,p2GShps,ROWS,COLS,maxGms,winner,p2Names,SIZE7,names,SIZE8,vNames);
    
        
        // display game's introduction message
        banner("BATTLE");  
        
        // get player 2's name from an array of names
        p2Name = pickP2(p2Names,SIZE7);
        cout << setw(12) << p1Name << " vs " << p2Name << "!" << endl;
    
        pause();
        
        //***************************************
        //******** GAME STARTS HERE**************
        //***************************************
                  

       
    //    // loops until a player correctly guesses opponents ship location
    //    while((!p1_crrt) && (!p2_crrt)){
    //
    //        rBanner(round); // display round number banner
    
            //*************** Player 1's Guess ************* 
            //**********************************************        
          
    //        instruc(p1Name,MAX);    // display instructions to player 1          
    //
    //        // set variables to the their 1st array's indices
    //        p1Guess = guessP1[rowIndx][colIndx];
    //        p2Ship1 = board2[rowIndx][colIndx];
    //        //showGuess(rowIndx,colIndx); // Board.h show players guess 
    //
    //        // checks if player1 guess is correct
    //        if((p1Guess=='S') && (p2Ship1=='S')){                 
    //
    //            numShp2--;  // decrease number of ships player 2 has left                        
    //            p1Win++;    // increment player 1 number of wins 
    //            isHit=true;  // reset flag                            
    //            hitMiss(isHit,p1Guess,p2Ship1);  // display HIT message for correct guess
    //            askQQ(ans); // ask if they want to check arrays
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
    //            instruc(p2Name,MAX);  // display instructions to player 2                
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
    //                askQQ(ans);
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
    //    sBanner("SCOREBOARD", p1Name, p2Name, p1Win, p2Win);      
    //    scoresMsg(ttlGmes, ttlRnds, avgRnds);     
    //
    //    pause();    // pause game so player can see the scores
    //     
    //    // **********************************************
    //    // ******** SORT & SEARCH NAMES SECTION *********
    //    // **********************************************
    //    
    //    // call function to sort & search names   
    //    topPlyrs(p2Names,SIZE7,names,SIZE8,p1Name,vNames);

    //    ofstream     outFile; // for outputting to a file
    //    outFile.open("scores.txt");  // create a file to output to   
    //    // write scores and averages to file
    //    outFile << fixed << showpoint << setprecision(2);
    //    outFile << "Player 1 wins: " << p1Win << endl
    //            << "Player 2 wins: " << p2Win << endl
    //            << ttlGmes << " of " << maxGms << " max games were played.\n";    
    //    
    //    outFile.close();   
}


////*********************************************************************
////******************* Function Implementations ****************************
////*********************************************************************
//
//// changes string to all capital letters
//void Battleship::upper(string &name){
//    char ch;
//    string temp="";
//    
//    for(int i=0;i<name.length();i++){
//        ch = toupper(name[i]);
//        temp +=ch;
//    }
//    name=temp;
//}
//
//// function controls the sort and search section
//void Battleship::topPlyrs(string p2Names[],int SIZE7,string names[],int SIZE8, string p1Name,
//              vector<string> &vNames){
//   // copy contents of one array to another array and add player1's name
//   copyAdd(p2Names,SIZE7,names,SIZE8,p1Name);
//   
//   // print names array
//   cout << "\nThis week's Top Players \n";
//   prntArr(names);
//   
//   // bubble sort names & print sorted array
//   sortBub(names,SIZE8);
//   float scores[SIZE8]={98.98, 99.84, 99.81, 99.80, 99.78, 99.74, 99.71, 99.69};
//   cout << "Bubble Sort: Top Player's \n";
//   
//   // print parallel arrays
//   for(int i=0; i<SIZE8; i++){       
//            cout << setw(3)<< i+1 << ". "<<setw(12)
//                 << left << names[i] << setw(6) << " "
//                 << scores[i] << endl;
//    }
//    cout << endl;
//   
//   string sName;
//   cout << "Enter a player's name to return what place they're in this week. \n";
//   cin >> sName;
//   int score = binarySrch(names,sName,SIZE8);
//   if(score==-1){
//       cout << "Sorry, " << sName << " wasn't found.\n";
//   } else cout << sName << " is in the " << score+1 << " spot of this week's top player.\n\n";
//   
//   pause(); // pause game so player can view the search findings
//   
//   // selection sort
//   sortSel(vNames);   
//  }
//
//// selection sort with vectors
//void Battleship::sortSel(vector<string> &vNames){    
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
//// bubble sort. compare neighboring indices one at a time
//void Battleship::sortBub(string names[], int size){
//    
//    bool swap;
//    int maxElmt=size-1; // (8-1)=7. holds subscript of last element that will be compared to its neighbor
//    
//    do {
//        swap=false; // set flag
//        
//        // loop 0 thru 7
//        for(int i=0;i<maxElmt;i++){
//            if(names[i] > names[i+1]){ // "VICTOR" > "JILLIAN" ?
//                
//                // swap index values
//                swap1(names[i],names[(i+1)]);
//                
//                // reset flag value  
//                swap=true;                           
//            }
//        }       
//        maxElmt--; // decrement. biggest value is at last index, so now restart loop to run to one less last index
//    } while(swap); // while there's still indices to left to swap
//}
//
//// swap indices
//void Battleship::swap1(string &a, string &b){
//    
//    string temp;
//    temp=a;
//    a=b;
//    b=temp;
//}
//
//// displays each players scores and win average
//void Battleship::scoresMsg(int ttlGmes, int ttlRnds, float avgRnds){
//    
//    showStatic(); // show how many games have been played
//    cout << fixed << showpoint << setprecision(2); 
//                cout << "Averages for " << ttlGmes << " games \n"
//                     << "Total # of rounds played: " << ttlRnds << endl                    
//                     << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
//                     << ceil(avgRnds) << endl;
//}
//
//
//
//// static variable for games
//void Battleship::showStatic(){
//    static int games=1;
//    cout << "\nTotal # Games Played = " << games << endl;
//    games++;
//}
//
//// display scoreboard banner
//void Battleship::sBanner(string str, string p1Name, string p2Name, int p1Win, int p2Win){   
//    
//    // Display scoreboard banner       
//        for(int k=0; k<=2; k++){
//            ((k==0)||(k==2)) ? cout << "********************************\n"
//                    : (k==1) ? cout << setw(21) << str << endl
//                    : cout << "Error in scoreboard banner.\n";
//        }
//        cout << setw(7) << " " << p1Name << setw(4) << "vs" << setw(3) << " " 
//             << right << p2Name << endl;
//        cout << setw(8) << p1Win << setw(16) << p2Win << endl;
//}
//
//// banner displays round number
//void Battleship::rBanner(int &r){
//        ++r;
//        cout << endl << setw(26) << "********************************" << endl;
//        cout << setw(18) << "Round " << r << endl;
//        cout << setw(26) << "********************************" << endl;                     
//}
//
//// prntArr names[]
//void Battleship::prntArr(string arr[]){
//
//    for(int i=0;i<8;i++){
//        cout << i+1 << ". " << arr[i] << endl;
//    }
//    cout << endl;
//}


// randomly picks a name from an array as player 2's name
string Battleship::pickP2(string p2Names[], int SIZE7){    
    cout << "\nLocating your opponent online......\n";    
    string name2=p2Names[rand()%(SIZE7)];     
    return name2;
}

// pause screen before game starts
void Battleship::pause(){    
    cout << "\nPress enter to continue. ";
    cin.ignore();
    cin.get();   
}

////  prompt user  
//void Battleship::runMenu(string p1Name, char &ch, char &ans, int count1,int count2,int numShp1,int numShp2,
//             char guessP1[][9],char guessP2[][9],char board1[][9],char board2[][9],
//             int p1GShps,int p2GShps,int ROWS,int COLS,int &maxGms, int &winner,
//             string p2Names[],int SIZE7,string names[],int SIZE8, vector<string> &vNames){
//    do {
//         
//        cout << endl << p1Name << " your game has successfully loaded. \n"
//             << "Press 1: to see a summary of the files that were read.\n"
//             << "Press 2: to confirm Guess[][] filled correctly\n"
//             << "Press 3: to confirm my game board[][] was read the data in correctly\n"
//             << "        and to that the guess[][] were randomly filled.\n"
//             << "Press 4: to start your game.\n"
//             << "Press 5: to run Top Player's Board.\n"
//             << "Press 6: to exit.\n";
//        cin  >> ch;

//        switch(ch){       
//            case '1': fileSum(count1,count2,numShp1,numShp2); break;
//            //void confrmGuesBrd(const char [][9], const char [][9],const int,const int,int, int); // confirms guess[][] filled correctly
//
//            case '2': confrmGuesBrd(guessP1, guessP2,ROWS,COLS,p1GShps,p2GShps);break;
//            case '3': print2DArr(guessP1, guessP2,board1,board2,ROWS,COLS,maxGms,winner); break;       
//            case '5': topPlyrs(p2Names,SIZE7,names,SIZE8,p1Name,vNames);
//            case '6': exit(EXIT_SUCCESS); break;
//            default: cout << setw(9)<< " " << "Loading.......\n";
//        }
//
//        if(ch=='1' || ch=='2' || ch=='3'|| ch=='5'){    
//            cout << "Run Menu again?\n";
//            cin >> ans;
//        } else ans='n';
//    
//    // continue doing all the statements above until ans does not equal y or Y
//    } while((ans=='y')||(ans=='Y')); 
//}
//
//// validates user's input
//bool Battleship::isReady(char ans){
//    // conditional validates user's input
//    if(ans=='y'){                
//        return true;
//    } else if(ans=='Y'){                
//        return true;
//    } else return false;            
//}
//
//// display instructions to player
//void Battleship::instruc(string player, const int MAX, int min){    
//    cout << endl << setw(2) << " " << "Try to guess the location of \n"
//         << setw(6) << " " << "your opponent\'s ship." << endl
//         << endl << setw(12)<< " " << player  << endl 
//         << setw(2) << " " << "Guess a letter between A-H\n"
//         << setw(2) << " " << "and a number between " << min << " and " << MAX/8 << endl;
//}

//// display hit message when player guesses correctly
//void Battleship::hitMiss(bool isHit, int guess, int shipLoc){
//    
//    cout << setw(13) << static_cast<char>(guess)
//         << " == " << static_cast<char>(shipLoc) << endl; 
//    if(isHit) cout << setw(20) << "It\'s a HIT!\n" << endl;
//    else cout << setw(22) << "It\'s a MISS!\n";
//}
//
//// display try again message when both player's guessed wrong
//void Battleship::hitMiss(){
//    cout << endl << "You Both Missed. Try Again..." << endl << endl;
//}
//
//// get player 1's name
//void Battleship::getName(string &name1){   
//    cout << "\nPlayer 1: Enter your name ";
//    cin >> name1; 
//    cout << endl;    
//    upper(name1);  // call function to convert user input into capital letters
//}
//
//
//// save player 1 and all of player 2's names to a new array
//void Battleship::copyAdd(string p2Names[],const int SIZE7, string names[], const int SIZE8, string p1Name){
//   
//   // copy all of player 2's name into a new array 
//   for(int i=0;i<SIZE7;i++){
//       names[i]=p2Names[i];
//   }
//   
//   // calculate the last index for names[]
//   unsigned int last = SIZE8-1;
//   
//   // add player 1's name to the end of the names[]
//   names[last]=p1Name;      
//}
//
//// 
//void Battleship::askQQ(char &ans){
//    cout<<"Would you like to confirm it was a hit? ";
//    cin>>ans;
//}
//
//
//// binary search 
// int Battleship::binarySrch(string names[], string &name, int SIZE8){
//    
//    int indx=0,
//        first=0,
//        last=SIZE8-1,
//        middle,
//        position=-1;
//    
//    bool found=false;
//    
//    upper(name);    // change string to all uppercase letters
//    
//    while(!found && first<=last){ // search between indices [0,7]
//        
//        middle = (first + last)/2; // middle index
//        if(names[middle]==name){ // check if middle indx equals name
//            found=true;
//            position=middle;
//           
//          // if name ASCii value is smaller then its in lower half of array  
//        } else if(names[middle]>name){ 
//            last= middle-1;
//          
//          // if name ASCii value is smaller then its in upper half of array
//        } else first = middle+1;  
//    }      
//    return position;
//}

// displays game's name and instructions in a banner
void Battleship::banner(string str){    
    // reassign variables value
    str="BATTLESHIP";     
    for(int i=0; i<=2; i++){
        if(i==0 || i==2){
            for(int j=0; j<32; j++) { cout << "*";} cout<<endl;
        } else {cout << setw(21) << str << endl;}               
    }
}



//  Moved these to Board.cpp and edited them


//// display data from both player's guess arrays. 
//void Battleship::confrmGuesBrd(const char guessP1[][9], const char guessP2[][9],
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
//void plyrShpBrd(int player,int opponnt,const char guess[][9],const char board[][9], 
//                const int ROWS,const int COLS){  
//    cout << endl << setw(19)<<" "<< "A1 B1 C1 D1 E1 F1 G1 H1 A2 B2 C2 D2 E2 F2 G2 H2\n";  
//    prntGuesBrd(player,guess,ROWS,COLS);  
//    prntOppBrd(opponnt,board,ROWS,COLS);
//}
//void prntGuesBrd(int player,const char guess[][9],const int ROWS,const int COLS){
//   cout << endl << setw(19)<<" "<< "A1 B1 C1 D1 E1 F1 G1 H1 A2 B2 C2 D2 E2 F2 G2 H2\n";         
//   cout << "Player "<<player<< " Guesses:  ";    
//   prntArr(guess,ROWS,COLS);
//   cout << endl;  
//}
//
//void prntOppBrd(int opponnt,const char board[][9],const int ROWS,const int COLS){
//    cout << endl << setw(19)<<" "<< "A1 B1 C1 D1 E1 F1 G1 H1 A2 B2 C2 D2 E2 F2 G2 H2\n";
//    cout << "Opponent's Board:  ";
//    prntArr(board,ROWS,COLS);
//}

//void plyrShpBrd(int player,int opponnt,const char guess[][9],const char board[][9], 
//                const int ROWS,const int COLS){    
//    cout << endl << setw(19)<<" "<< "A1 B1 C1 D1 E1 F1 G1 H1 A2 B2 C2 D2 E2 F2 G2 H2\n";         
//   cout << "Player "<<player<< " Guesses:  ";    
//   prntArr(guess,ROWS,COLS);
//   cout << endl;  
//    cout << endl << setw(19)<<" "<< "A1 B1 C1 D1 E1 F1 G1 H1 A2 B2 C2 D2 E2 F2 G2 H2\n";
//    cout << "Opponent's Board:  ";
//    prntArr(board,ROWS,COLS);
//}

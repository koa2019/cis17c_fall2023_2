#include "Board.h"
#include <bits/stdc++.h> 
#include <fstream>  // ofstream 
using namespace std;


//******************************************************************************
//                     Default Constructor
//                     SET UP GAME Boards
//******************************************************************************
Board::Board(){
    
    // initialize counters to zero
    p1GShps=p2GShps=numShp1=numShp2=count1=count2=0;
    isP1Turn=true;
    plyrName[0]="Ventress Opress";
    plyrName[1]="Darth Maul";  
    
    // Read in file and initialize each player's game board
    fillGameBrd();
    
    // fill 2D guess container with random choices[]
    fllGArr();   
    fileSum();
    confrmGuesBrd(); // confirms guess[][] filled correctly for both players
    //char ans='Y';
    //askQQ(ans); // ask if they want to check their board against opponent's
  
    cout<<"\nPlayer 1 Game Board:\n"; 
    prntBrd(board1);
    cout<<"\nPlayer 1 Guess Board:\n";
    prntBrd(guessP1);
    cout<<"\n\n\nPlayer 2 Game Board:\n";
    prntBrd(board2); 
    cout<<"\nPlayer 2 Guess Board:\n";
    prntBrd(guessP2);   
    //plyrOppBrds(0,1,guessP1,board2); // when its player 1's turn
    //plyrOppBrds(1,0,guessP2,board1); // when its player 2's turn
    
    cout<<"\n\n\n\tEND of Board Class\n\n\n";
}

// Make this work
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


//void Board::askQQ(char &ans){
//    cout<<"\n\nWould you like to confirm it was a hit?\n";
//    cin>>ans;
//}

// show each players guess 
void Board::showGuess(int row,int col){
    char colLttr = col==1 ? 'A':
                   col==2 ? 'B':
                   col==3 ? 'C':
                   col==4 ? 'D':
                   col==5 ? 'E':
                   col==6 ? 'F':
                   col==7 ? 'G':
                   col==8 ? 'H': '?';   
    cout << setw(13) << "Col " << colLttr 
         << " Row " << row <<endl;   
}

// confirm data that was read in is even and contains at least 3 ships
void Board::fileSum(){   
    cout << endl << setw(3)<<" " << "Read in " << setw(6)<< " " << "P1 Board" << setw(5)<< " "<< "P2 Board" << endl;
    cout << "Total # chars " << setw(8) << right << count1 << "\t \t" << count2 << "\n";
    cout << "Total # ships " << setw(8) << right << numShp1 << "\t \t" << numShp2 << "\n\n";    
}


// Confirms both player's guess Boards were randomly filled
// AND have at least 3 ships in each of them. 
void Board::confrmGuesBrd(){    
    cout<<"\n Confirming Guess Boards are random\n and they have at least 3 ships in one array\n\n";
    cout<<setw(1)<<" "<<"P1 Guess Board"<<endl; 
    cout<<" P1 # Ships : "<<p1GShps<<endl;
    prntBrd(guessP1);    
    cout<<endl<<endl<<endl<<setw(1)<<" "<<"P2 Guess Board\n";
    cout<<" P2 # Ships : "<<p2GShps<<endl;         
    prntBrd(guessP2);
}

// randomly fill guess[][] until at least one of the player's has 3 ships in their array
void Board::fllGArr(){
    char choices[]={'S','B','S','S','B','S','S','B','S','S','B','S','S','B','S','S','B'};
    int size=17; //sizeof(choices)/sizeof(choices[0]);   
    bool minMet;        // minimum number of ships==3

    do{
        minMet=false;// set flag

        for(int gRow=1; gRow<ROWS; gRow++){
            for(int gCol=1; gCol<COLS; gCol++){

                // automatically set player 1's guess[][] randomly from choices[] 
                guessP1[gRow][gCol]=choices[rand()%size]; // saves either a 'S' or 'B' 

                // track how many ships player 1's array has
                if(guessP1[gRow][gCol]=='S'){
                    p1GShps++;                    
                    if(p1GShps==3) minMet=true;   // reassign value to flag                                           
                }
                // automatically set player 2's guess[][] randomly from choices[] 
                guessP2[gRow][gCol]=choices[rand()%size]; 

                // track how many ships player 1's array has
                if(guessP2[gRow][gCol]=='S'){
                    p2GShps++; 
                   if(p2GShps==3) minMet=true;   // reassign value to flag
                }
            }        
        }       
    } while(!minMet); 
}

// prntBrd []
void Board::prntBrd(char arr[][COLS]){    
    cout<<setw(1)<<" "<<"A1 B1 C1 D1 E1 F1 G1 H1 A2 B2 C2 D2 E2 F2 G2 H2\n"; 
    cout<<setw(1)<<" ";
    for(int pRows=1; pRows<ROWS; pRows++){         
        for(int pCols=1; pCols<COLS; pCols++){
            cout << arr[pRows][pCols] << "  ";           
        }             
    }
}
void Board::plyrOppBrds(int a,int b){   
    string p1  = plyrName[a]; p1+=" Guess Board:  ";
    cout<<endl<<p1<<endl;         
    prntBrd(guessP1);//This bug will fix itself when guess and boards turn into ptrs
    
    // Opponent's board
    string opp = plyrName[b]; opp+="'s Board:  ";
    prntBrd(board2);
    cout<<endl;  
}
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


// Read in file and initialize each player's game board
void Board::fillGameBrd(){
    
    ifstream    inFile1; // for reading an existing file
    ifstream    inFile2; 
    // open an existing file that holds max number of games a user can play
    //inFile.open("maxNGms.txt");
    inFile1.open("board1.txt",ios::in);   
    inFile2.open("board2.txt",ios::in);   
    
    // read in data from file and initialize each player's game board[][]
    // with a S(ship) or a B(blank)   
    for(int nRows=1; nRows<ROWS; nRows++){
        for(int nCols=1; nCols<COLS ;nCols++){
            
            inFile1 >> board1[nRows][nCols];   
            if(board1[nRows][nCols]=='S') { 
                numShp1++;  // count how many ships player 1 has in their array
            }
            count1++;   // count how many items were read in
            inFile2 >> board2[nRows][nCols];
            if(board2[nRows][nCols]=='S'){
                numShp2++;  // count how many ships player 1 has in their array
            }
            count2++;   // count how many items were read in
        }        
    } 
        // close files being read in and written to
    inFile1.close();
    inFile2.close();
}


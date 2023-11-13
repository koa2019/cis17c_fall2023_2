/* File:   main.cpp
 * Author: Danielle 
 * Created: 11-11-23  9:30 PM
 * Purpose: cis17C_Project_1_battleship_v5
 *  
 * Version 5: 
 * Implemented queue with number of ships each player has.
 * queue<string> ships, setShips(), prntQue(); 

 * To do:
 * Make topPlyr() print by highest to lowest scores
 */

// System Libraries: 
#include <bits/stdc++.h> 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <cstring>  // string library
#include <string>
#include <ctime>    // time library for rand()
#include <cctype>
#include <climits> // char and int maximums
#include <cfloat>  //float maximum
#include <vector>   // vector
#include <iterator>
#include <algorithm>// shuffle, min
#include <map>
#include <set>
#include <queue>
#include <random> // used for shuffle
#include <array> // used for shuffle
#include <chrono>
#include <unordered_set>// used for shuffle
#include <string_view>
#include <unordered_set>
#include <unordered_set>//min

using namespace std;

// User libraries

// Global Constants
// Physics/Chemistry/Math/Conversions


// STL Function prototypes
void concepts();
void constructor();
void setNames(unordered_set<string>&);
void setShips(queue<string>&);
void setStack(stack<string>&, list<string>&);

void fillGuess();
string getMin(unordered_set<string>&);//returns min name
string getName();  // get player 1's name using pass by reference
unordered_set<string> setSet(); 
map<string, float> setTopPlyrs(unordered_set<string> &);
void topPlyrs(unordered_set<string> &);
void pause();
void prntMap(map<string, float>&);// Prints topPlyrs & hiScores
void prntList(list<float> &); // High Scores
void prntQue(queue<string> &);
void prntSetStr(unordered_set<string>&);// Prints player 1 & player 2's names
void prntStackStr(stack<string>&);
string set2Upper(string name="name"); // convert string to all uppercase letters
void shuffleThis();//shuffles int, char, string array BUT not a set container


// Array Function prototypes
void menu();
void fillGuess(char [][9],char [][9],char [], int, int, int &, int&);
void cGssArr(const char [][9], const char [][9],const int,const int,int, int); // confirms guess[][] filled correctly             
void banner(string);      // display game 
int  binarySrch(string [],string &,int);
void chkAnswr(char &);
void copyAdd(string [],const int,string[],const int,string);
void fileSum(int,int,int,int);
void hitMiss(bool,int,int);  // hit message for correct guess
void hitMiss();        // try again message
void instruc(string, const int, int =1); // instructions for players
bool isReady(char);   // returns bool value
void runMenu(string,char&,char&,int,int,int,int,char[][9],char[][9],
             char[][9],char[][9],int,int,int,int,int&,int&,unordered_set<string>&,vector<string>&);
void play();
void plyrShpBrd(int,int,const char [][9],const char [][9],const int,const int);
void print2DArr(const char [][9],const char [][9],
                const char [][9],const char [][9],const int,const int,int &,int &);
void prntArr(string []);  // prints names[]
void prntArr(const char [][9],int,int); //prints 2D
void rBanner(int &);      // display the round number
void sBanner(string,string,string,int,int);   // display scoreboard banner
string pickP2Name(string [],int);  // randomly picks a number for player 2
void sortSel(vector<string> &);
void scoresMsg(int,int,float);  // displays scores for both players
void showGuess(int,int);
void showStatic();
void sortBub(string [],int);       // sort names
void swap1(string &,string &);
void topPlyrs(string [],int,string [],int,string,vector<string> &);



// Program execution begins here
int main(int argc, char** argv) {
    // set random number seed
    srand(static_cast<unsigned int>(time(0)));   
    //menu();  
    concepts();
    //constructor();    
    return 0;
}


//*********************************************************************
/*                       STL Functions                               */
//*********************************************************************
void concepts(){
    
    string p1Name = "GUEST", 
           name2 = "COMPUTER";     
    
    // Set name and Push into set       
    p1Name=getName();  // Set player 1's name to uppercase case 
    unordered_set<string> names = setSet();
    names.insert(p1Name); // add player 1's name to names container
    cout<<"Utilized transform() and ::toupper for string inputs.\n";
    cout<<"Combined 2 sets and then inserted "<<p1Name<<".\n\n";
    cout<<"Set Unsorted Players: \n";
    prntSetStr(names);    
    pause();
    name2 = getMin(names);
    cout<<setw(2)<<p1Name<<" vs "<<name2<< "!\n\n";  
    pause();
    // Sort & search names   
    topPlyrs(names);
    pause();
    
    // Stack
    //stack<string> fnames;//"MARTY", "BART", "ALEX", "CHOPPER", "MAUL", "ANAKIN", "KENOBI"
    //setNames(fnames);
    //cout<<"Set initialized with a stack of names\n";
    //prntSetStr(fnames);
    
    // Queue
    queue<string> ships;
    setShips(ships);      
    cout<<"\tQueue Container\nEach player has 3 ships that can be hit.\n"; 
    prntQue(ships);
    cout<<endl<<right;   
    
    // CHANGE FROM Stack TO MAPS
    fillGuess();
    
 }

void constructor(){
//    queue<string> ships;
//    setShips(ships);      
//    cout<<"\tQueue Container\nEach player has 3 ships that can be hit.\n"; 
//    prntQue(ships);
//    fillGuess();
    

    //string p1Name = "minnie", 
           //name2 = "COMPUTER";         
    // Set name and Push into set       
    //p1Name=getName();  // Set player 1's name to uppercase case 
    unordered_set<string> names;
    setNames(names);
    // add player 1's name to the end of the names[] 
    //names.insert(p1Name);
    //cout<<"Added player 1's name, "<<p1Name<<endl;
    //prntSetStr(names);
}


void setNames(unordered_set<string> &names){    
       
    list<string> list{"MARTY", "BART", "ALEX", "CHOPPER", "MAUL", "ANAKIN", "KENOBI"};
    cout<<"List of player 2 names\n";
    for(auto &i : list){cout<<i<<endl;}cout<<endl;
            
    // Initialize stack with a list
    stack<string> stack;//setStack(stack);
    std::list<string>::iterator it = list.begin();
    for(int n=0;n<list.size();n++, it++){ stack.push(*it);}
    cout<<"Stack initialized with a list of names\n";
    prntStackStr(stack);
    
    // copy stack into set of names
    //it = stack.begin();
  //names(stack.begin(), stack.end());
    //cout<<"CHANGE TO SET WITH STACK.\n";
    //prntSetStr(names);
   
    
}

// Loops through list and pushes a name to the stack
void setStack(stack<string> &stack, list<string> &list){
    // Initialize stack with list values
    std::list<string>::iterator it = list.begin();
    for(int n=0;n<list.size();n++, it++){ stack.push(*it);}
    //prntStackStr(stack);
}

// Recursive function to print stack elements
// from bottom to top without changing their order
// https://www.geeksforgeeks.org/print-stack-elements-from-bottom-to-top/
void fillGuess(){
    int     p1GShps=0,// # ships in p1 guess container
            p2GShps=0;// # ships in p2 guess container
    // Used to fill each player's guess[][]
    char choices[]={'b','B','S','S','B','s','S','B','S','B','B','s','S','B','S','b'};
    
    stack<char> guessP1;    
    int n = sizeof(choices)/sizeof(choices[0]); 
    cout<<"Stack Container\n";
    //cout<<"choices size = "<<n<<endl;
    for(int i=0; i<n;i++){
        //shuffleThis();
        guessP1.push(choices[rand()%n]);
    }
        
    // Print stack filled with random guesses
    //PrintStack(guessP1);
    //cout<<"\nstack guessP1.size = "<<guessP1.size()<<endl;
    stack<char> temp;
    while (guessP1.empty() == false)
    {
        temp.push(guessP1.top());
        guessP1.pop();
    }       
   
    cout<<setw(15)<<" "<<"Player 1 Guesses Board"<<endl; 
    cout<<setw(5)<<" "<<"A1 B1 C1 D1 E1 F1 G1 H1 A2 B2 C2 D2 E2 F2 G2 H2\n"<<setw(5)<<" ";
    while (temp.empty() == false)
    {        
        char t = temp.top();
        if(t=='S'||t=='s'){p1GShps++;}
        cout<<t<<"  ";
        temp.pop();
 
        // To restore contents of
        // the original stack.
        guessP1.push(t);  
    }    
    //Need at least 3 ships to make sure there's at least win
    cout<<"\nP1 numShips: "<<p1GShps<<endl;
}

void setShips(queue<string> &ships){
    ships.push("ship1");
    ships.push("ship2");
    ships.push("ship3");    
}
void prntQue(queue<string> &ships){
    queue<string> temp1;
    while(!ships.empty()){
        temp1.push(ships.front());
        ships.pop();
    }
    while (temp1.empty() == false)
    {        
        string t1 = temp1.front();        
        cout<<t1<<" \n";
        temp1.pop(); 
        // To restore contents of the original stack.
        ships.push(t1);  
    }    
}
// Add a for loop to find the shortest name in names set container
string getMin(unordered_set<string> &names){        
    unordered_set<string>::iterator itr = names.begin();
    unordered_set<string>::iterator end = names.begin();
    itr++;
    int n=names.size()-1;
    int i= 1+(rand()%n);
    std::advance(end, i);//https://stackoverflow.com/questions/20477545/element-at-index-in-a-stdset
    string last = *end;
    //cout<<"n="<<n<<"  names["<<i<<"] = "<<last<<endl;
    string min = std::min({*itr, last},
            [](const std::string_view s1, const std::string_view s2)
            {
                return s1.size() < s2.size();
            });
    cout<<setw(2)<<"min("<< *itr<<","<<last<<") = "<<min<<"\n\n";
    return min;
}

// function controls the sort and search section
void topPlyrs(unordered_set<string> &names){ 
    
    // Initialize unordered map with pair(topPlyrs,scores)
    std::map<string, float> topPlyrs; 
    topPlyrs = setTopPlyrs(names);
    
    //prntMap(topPlyrs); //Print unordered map (key,value) pairs of topPlyrs & high scores
   
    // Print map (key,value) pairs of high scores
    cout<<"Map pair(set<string>, list<float>).\n";
    cout<<"Map Sorted Alphabetically:  \n";
    prntMap(topPlyrs);// Print unordered map (key,value) pairs of topPlyrs & high scores
    
//    string sName="";
//    cout<<endl<<endl<<"Enter a player's name to return\nwhat place they're in this week.\n";
//    cin >> sName; 
//    //cin.ignore(); 
//    cout<<endl;    
//    // Searches for a top player's name and returns this standing
//    auto it = topPlyrs.find(set2Upper(sName)); 
//    if(it==topPlyrs.end()){
//       cout<<"Sorry, "<<sName<<" wasn't found.\n";
//    } else {      
//        int count=1;
//        for(auto i=topPlyrs.begin(); i!=it;i++,++count){}
//        cout << (*it).first <<" is in the "
//             << count<<" spot \nfor this week's top player with "
//             << (*it).second <<" points.\n\n";
//    }    
//    pause(); // pause game so player can view the search findings 
    //sortSel(); // Sorts last week's top scores.   
  }


// Initialize unordered map with pair(topPlyrs,scores)
// https://en.cppreference.com/w/cpp/iterator/insert_iterator
map<string, float> setTopPlyrs(unordered_set<string> &names){        
 
    
    set<float>s{98.98, 99.69, 98.81, 97.43};
    list<float>scores{101.9, 99.71, 99.24, 99.18};     
    cout<<"set:\n";
    for(auto &i : s){cout<<i<<endl;}    
    cout<<"\nPartial list:\n";    
    prntList(scores);
    // Copy set into list
    std::copy(s.begin(),s.end(), 
            std::insert_iterator<std::list<float>>(scores, std::next(scores.begin()))); 
    cout<<"set copied into list:\n";
    prntList(scores);
    
    // Initialize map container with a set and a list as its pair(key,value)
    map<string, float> topPlyrs;  
    unordered_set<string>::iterator itr = names.begin();
    list<float>::iterator litr = scores.begin();
    
    // Initialize map with a pair("name", hiScore)
    int j=0; 
    for (itr = names.begin(); itr!=names.end(); itr++,litr++) {         
        topPlyrs.insert(  // Inserts pairs in the key's alphabetically order
        pair<string, float>(*itr, *litr)); 
        //cout<<"j="<<j<<" ("<<*itr<<", "<<scores<<") "<<endl;
        j++; 
    }    
    return topPlyrs;
}
 
// Combined 2 sets and then inserted p1Name in front
unordered_set<string> setSet(){
    
    // Copy array to a set
    string nameAry[]={"MARTY", "BART", "ALEX", "CHOPPER", "MAUL", "ANAKIN", "KENOBI"}; 
    int n = sizeof(nameAry)/sizeof(nameAry[0]);
    //name2=nameAry[rand()%(n)];    
    // Initialize set with string array values
    unordered_set<string> p2Names;    
    for(int i=0;i<n;i++){ p2Names.insert(nameAry[i]);}    
    
    // copy all of player 2's name into a new array 
    unordered_set<string> names(p2Names.begin(), p2Names.end());      
    return names;
}


// Can i const stack so it doesn't delete the original stack?
// Print a stack using a temp stack, so it doesn't delete the stack forever
void prntStackStr(stack<string> &stack){
    std::stack<string> temp;
    while(stack.empty()==false){
        //string t = stack.top();cout<<t<<"\n";
        temp.push(stack.top());
        stack.pop();
    }  
    while(temp.empty()==false){        
        string t = temp.top();       
        cout<<t<<"\n";
        temp.pop(); 
        stack.push(t);// To restore contents of the original stack.
    }    
}


//shuffles int, char, string array BUT not a set container
void shuffleThis(){
    //Shuffle https://www.educba.com/c-plus-plus-shuffle/
    //Shuffle doesn't work with set<>names
    array<int,8> shuf {19,24,37,42,54,76,58,53};
    //array<char,6> shuf {'A', 'B', 'C', 'D', 'E', 'F'};
    unsigned num = chrono::system_clock::now().time_since_epoch().count();
    shuffle (shuf.begin(), shuf.end(), default_random_engine(num));
    cout << "The numbers after shuffling are:";
    for (auto& x: shuf) cout << ' ' << x;
    cout << '\n';
}

// Set player 1's name and convert to uppercase letters
string getName(){ 
    string name1="Danielle";
    cout << "\nPlayer 1: Enter your name\n";
    //cin >> name1; 
    //cin.ignore();
    cout << endl; 
    return set2Upper(name1);  //convert user input into capital letters
}

// changes string to all uppercase letters
string set2Upper(string name){ 
    string temp=" ";
    temp=name;
    // using transform() function and ::toupper in STL 
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper); 
    return temp;
}

// Print unordered map (key,value) pairs of topPlyrs & high scores
void prntMap(map<string, float> &map){
    int i=1;
    std::map <string, float>::iterator itmap = map.begin();
    cout<<"Map Top Player's Scores\n";
    for (itmap = map.begin(); itmap!=map.end(); itmap++) {
        cout<<i++<<". "<<"("<<setw(8)<<left
            << itmap->first <<","<< itmap->second <<")\n";
    }
}

// Print a list
void prntList(list<float> &list){
    int i=1;
    std::list<float>::iterator litr = list.begin();
    for(litr=list.begin(); litr!=list.end(); litr++,i++) {
        cout<<i<<". "<<*litr<<"\n";
    }cout<<endl;
}

// Prints names set container
void prntSetStr(unordered_set<string> &set){
    int i=1;
    std::unordered_set<string>::iterator itr;
    for (itr = set.begin(); itr != set.end(); itr++) {
        cout<<i++<<". "<<*itr<<endl;
    }
    cout<<endl;
}

// pause screen before game starts
void pause(){    
    cout << "\n\nPress enter to continue. ";
    //cin.ignore();
    cin.get();   
    cout<<endl;
}


//*********************************************************************
//                      Array Functions  
//*********************************************************************


//Play battleship 
void play(){
    
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
                 winner;
    
    float        avgRnds;   // average rounds it takes to win
    vector<string> vNames{"VICTOR", "DANI", "STEPHANIE", "MIKE", "BART", "JANIS", "MICHELLE", "JILLIAN"};
    string p1Name = "GUEST", 
           name2 = "COMPUTER"; 
   
  
                /****************************************/
                /*    SET UP GAME BOARD STARTS HERE       */
                /*   MOVE THIS SECTION INTO A CLASS     */
                            //constructGame();
                /****************************************/
    
    /**************************************************************************/
    //              Set 2 game boards with ships or blanks
    /**************************************************************************/
    // open an existing file that holds max number of games a user can play
    // declare variables   
    ifstream     inFile1; // for reading an existing file
    ifstream     inFile2;
    ofstream     outFile; // for outputting to a file
    //inFile.open("maxNGms.txt");
    inFile1.open("board1.txt",ios::in);   
    inFile2.open("board2.txt",ios::in);
    outFile.open("scores.txt");  // create a file to output to   
    
    // Initialize game board containers and ship counters   
    char         board1[ROWS][COLS]={};
    char         board2[ROWS][COLS]={};
    int numShp1, // Number of ships player 1 has in their array
        numShp2, // Number of ships player 2 has in their array
        count1, 
        count2;    
    numShp1=numShp2=count1=count2=0;

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
                numShp2++;  // count how many ships player 2 has in their array
            }
            count2++;   // count how many items were read in
        }        
    }      
    
    /**************************************************************************/
    //              Fill each players container with guesses
    /**************************************************************************/
    int     p1GShps,// # ships in p1 guess container
            p2GShps;// # ships in p2 guess container
    char    guessP1[ROWS][COLS]={};//p1 guess container
    char    guessP2[ROWS][COLS]={};//p2 guess container 
    // Used to fill each player's guess[][]
    char choices[]={'S','B','S','S','B','S','S','B','S','B','B','S','S','B','S','S'};
    // fill guess[] [] with choices[]
    fillGuess(guessP1,guessP2,choices,ROWS,COLS,p1GShps,p2GShps);    

                /****************************************/
                /*    END GAME BOARD CONSTRUCTOR HERE   */   
                /****************************************/
    
    
                /****************************************/
                /*    START PLAYER CONSTRUCTOR HERE     */   
                /****************************************/
    
    // Set name and Push into set       
    unordered_set<string> names = setSet(); 
    
    // show switch menu
    runMenu(p1Name,ch,ans,count1,count2,numShp1,numShp2,guessP1,guessP2,board1,board2,
            p1GShps,p2GShps,ROWS,COLS,maxGms,winner,names,vNames);
    
    pause();   
    // get player 2's name from an array of names    
    p1Name=getName(); // Set player 1's name to uppercase case 
    cout << "\nLocating your opponent online......\n";  
    name2 = getMin(names);// get player 2's name from an array of names
    cout << setw(12) << p1Name << " vs " << name2 << "!" << endl;           
 
        
            /****************************************/
            /*      END PLAYER CONSTRUCTOR HERE     */   
            /****************************************/
   
    
            /****************************************/
            /*      START PLAY CONSTRUCTOR HERE     */   
            /****************************************/
              
    // sets games flag & counting variables to their default values
    banner("BATTLE"); // display game's introduction message  
    p1_crrt = p2_crrt = false;     
    rowIndx=colIndx=1;
    pause();
    
    // loops until a player correctly guesses opponents ship location
    while((!p1_crrt) && (!p2_crrt)){

        rBanner(round); // display round number banner

        //*************** Player 1's Guess ************* 
        //**********************************************        
      
        instruc(p1Name,MAX);// display instructions to player 1  
        // set variables to the their 1st array's indices
        p1Guess = guessP1[rowIndx][colIndx];
        p2Ship1 = board2[rowIndx][colIndx];
        showGuess(rowIndx,colIndx); // show players guess 
        
        // checks if player1 guess is correct
        if((p1Guess=='S') && (p2Ship1=='S')){                 

            numShp2--;  // decrease number of ships player 2 has left                        
            p1Win++;    // increment player 1 number of wins 
            isHit=true;  // reset flag                            
            hitMiss(isHit,p1Guess,p2Ship1);  // display HIT message for correct guess
            chkAnswr(ans); // ask if they want to check arrays
            ready=isReady(ans); // validates user's input

            if(ready) {                
                // display opposing 2D arrays to confirm it was a hit
                plyrShpBrd(1,2,guessP1,board2,ROWS,COLS);
                pause();
            }

            // checks if player 1's number of wins equals max games 
            if(maxGms==p1Win) p1_crrt = true;   // reassign player 1's value for a correct guess                          
                                                                              
        } else { // else when player 1 guess is wrong 
            isHit=false;    // reset flag
            hitMiss(isHit,p1Guess,p2Ship1); // display MISS message for wrong guess
        }
        pause();
        
        // conditional only runs if player 1 misses player 2's ship
        if(!p1_crrt){

            //**********************************************
            //*************** Player 2's Guess *************
            //**********************************************                

            instruc(name2,MAX);  // display instructions to player 2                

            // program generates random number guess
            p2Guess = guessP2[rowIndx][colIndx];
            p1Ship1= board1[rowIndx][colIndx];            
            showGuess(rowIndx,colIndx);

            // conditional checks if player 2's guess is correct
            // program automatically generated  guess for player 2                           
             if((p2Guess=='S') && (p1Ship1=='S')){  

                numShp1--;  // decrement number of ships player 1 has                                        
                p2Win++;    // increment player 2 number of wins
                isHit=true;   // reset flag                                  
                hitMiss(isHit,p2Guess, p1Ship1);    // display HIT message for correct guess  

                chkAnswr(ans);

                // conditional validates user's input
                ready=isReady(ans);
                if(ready){
                    plyrShpBrd(2,1,guessP2,board1,ROWS,COLS);                   
                    pause();
                }

                // checks to see if player has won the
                if(maxGms==p2Win) p2_crrt = true;   // reassign player 1's value for a correct guess                          
                
            } else {  // else when player 2 guess is wrong 
                isHit=false;
                hitMiss(isHit,p2Guess,p1Ship1); // display MISS message for player 2's wrong guess  
            }
        } // ends player 2's turn
        
        // increment index that controls the guess[][] & board[][]
        if(colIndx<=8) colIndx++;                           

        // if both players guessed wrong, then       
        if((!p1_crrt) && (!p2_crrt)){

            // increases row and resets column
            if( (colIndx>8) && (rowIndx<=2)) {
                rowIndx++; 
                colIndx=1;
            }

            // makes sure game ends if neither player  has guessed their opponents ship's location correctly
            if(round>=16){
                p1_crrt=p2_crrt=true;
                cout<<"You've reached the max # of rounds.\n\n";

            } else hitMiss();   // display try again message when both players guess wrong
        }            
    } // ends while(!p1_crrt) && (!p2_crrt)

    // calculate total number of games won & number rounds played
    ttlGmes = p1Win+p2Win;
    ttlRnds += round; // sums the total number of rounds from all games
    avgRnds = static_cast<float>(ttlRnds)/ttlGmes;
    
    // call function to display both player's scores
    sBanner("SCOREBOARD", p1Name, name2, p1Win, p2Win);      
    scoresMsg(ttlGmes, ttlRnds, avgRnds);     

    pause();    // pause game so player can see the scores
     
    // **********************************************
    // ******** SORT & SEARCH NAMES SECTION *********
    // **********************************************
    
    // Sort & search names   
    topPlyrs(names);

    // write scores and averages to file
    outFile << fixed << showpoint << setprecision(2);
    outFile << "Player 1 wins: " << p1Win << endl
            << "Player 2 wins: " << p2Win << endl
            << ttlGmes << " of " << maxGms << " max games were played.\n";
     
    // close files being read in and written to
    inFile1.close();
    inFile2.close();    
    outFile.close();   
}

// function controls the sort and search section
void topPlyrs(string p2Names[],int SIZE7,string names[],int SIZE8, string p1Name,
              vector<string> &vNames){
   // copy contents of one array to another array and add player1's name
   copyAdd(p2Names,SIZE7,names,SIZE8,p1Name);
   
   // print names array
   cout << "\nThis week's Top Players \n";
   prntArr(names);
   
   // bubble sort names & print sorted array
   sortBub(names,SIZE8);
   float scores[SIZE8]={98.98, 99.84, 99.81, 99.80, 99.78, 99.74, 99.71, 99.69};
   cout << "Bubble Sort: Top Player's \n";
   
   // print parallel arrays
   for(int i=0; i<SIZE8; i++){       
            cout << setw(3)<< i+1 << ". "<<setw(12)
                 << left << names[i] << setw(6) << " "
                 << scores[i] << endl;
    }
    cout << endl;
   
   string sName;
   cout << "Enter a player's name to return what place they're in this week. \n";
   cin >> sName;
   int score = binarySrch(names,sName,SIZE8);
   if(score==-1){
       cout << "Sorry, " << sName << " wasn't found.\n";
   } else cout << sName << " is in the " << score+1 << " spot of this week's top player.\n\n";
   
   pause(); // pause game so player can view the search findings
   
   // selection sort
   sortSel(vNames);   
  }

// selection sort with vectors
void sortSel(vector<string> &vNames){    
   
    cout << "\nLast Week's Top Players \n";
    for(auto ele : vNames)
        cout << ele << endl;
    cout << endl;
    
    int    minIndx, last=0; 
    string minVal;    
    
    last=(vNames.size()-1); // don't need to go the last index cause we check it by the end of loop's 1st run
    
    for(int start=0; start<last; start++){
        
        minIndx = start; // set smallest index to zero
        minVal=vNames[start]; // set smallest value to array's 1st index
        
        // start loop at array's[1]
        for(int indx=(start+1);indx<vNames.size();indx++){            
        
            // if its neighbor index is smaller than it
            if(vNames[indx] < minVal){ 
                
                // reassign smallest to that array's index and its value
                minVal = vNames[indx];
                minIndx = indx;
            }  
        } // swap their values
        swap1(vNames[minIndx], vNames[start]);
    }    
    cout << "Vector Selection Sort: Last Week's Top Players \n";
    for(auto ele : vNames)
        cout << ele << endl;
    cout << endl;
}

// bubble sort. compare neighboring indices one at a time
void sortBub(string names[], int size){
    
    bool swap;
    int maxElmt=size-1; // (8-1)=7. holds subscript of last element that will be compared to its neighbor
    
    do {
        swap=false; // set flag
        
        // loop 0 thru 7
        for(int i=0;i<maxElmt;i++){
            if(names[i] > names[i+1]){ // "VICTOR" > "JILLIAN" ?
                
                // swap index values
                swap1(names[i],names[(i+1)]);
                
                // reset flag value  
                swap=true;                           
            }
        }       
        maxElmt--; // decrement. biggest value is at last index, so now restart loop to run to one less last index
    } while(swap); // while there's still indices to left to swap
}

// randomly picks a name from an array as player 2's name
string pickP2Name(string p2Names[], int SIZE7){    
    cout << "\nLocating your opponent online......\n";    
    string name2=p2Names[rand()%(SIZE7)];     
    return name2;
}
// swap indices
void swap1(string &a, string &b){
    
    string temp;
    temp=a;
    a=b;
    b=temp;
}

// displays each players scores and win average
void scoresMsg(int ttlGmes, int ttlRnds, float avgRnds){
    
    showStatic(); // show how many games have been played
    cout << fixed << showpoint << setprecision(2); 
                cout << "Averages for " << ttlGmes << " games \n"
                     << "Total # of rounds played: " << ttlRnds << endl                    
                     << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
                     << ceil(avgRnds) << endl;
}

// show each players guess 
void showGuess(int row,int col){
    char colLttr = col==1 ? 'A':
                   col==2 ? 'B':
                   col==3 ? 'C':
                   col==4 ? 'D':
                   col==5 ? 'E':
                   col==6 ? 'F':
                   col==7 ? 'G':
                   col==8 ? 'H': '?';   
    cout<<endl<<setw(18)<<"Guessed: "<<colLttr<<row<<endl;   
}

// static variable for games
void showStatic(){
    static int games=1;
    cout << "\nTotal # Games Played = " << games << endl;
    games++;
}

// display scoreboard banner
void sBanner(string str, string p1Name, string p2Name, int p1Win, int p2Win){
    
    
    // Display scoreboard banner       
        for(int k=0; k<=2; k++){
            ((k==0)||(k==2)) ? cout << "********************************\n"
                    : (k==1) ? cout << setw(21) << str << endl
                    : cout << "Error in scoreboard banner.\n";
        }
        cout << setw(7) << " " << p1Name << setw(4) << "vs" << setw(3) << " " 
             << right << p2Name << endl;
        cout << setw(8) << p1Win << setw(16) << p2Win << endl;
}

// banner displays round number
void rBanner(int &r){
        ++r;
        cout << endl << setw(26) << "********************************" << endl;
        cout << setw(18) << "Round " << r << endl;
        cout << setw(26) << "********************************" << endl;                     
}

// prntArr []
void prntArr(const char arr[][9],int ROWS, int COLS){

    for(int pRows=1; pRows<ROWS; pRows++){         
        for(int pCols=1; pCols<COLS; pCols++){
            cout << arr[pRows][pCols] << "  ";           
        }             
    }
}

// prntArr names[]
void prntArr(string arr[]){

    for(int i=0;i<8;i++){
        cout << i+1 << ". " << arr[i] << endl;
    }
    cout << endl;
}

// 
void print2DArr(const char guessP1[][9], const char guessP2[][9],
                const char board1[][9],const char board2[][9], 
                const int ROWS,const int COLS,int &maxGms,int &winner){
    
    unsigned int hit1,hit2,rIndx1,rIndx2,cIndx1,cIndx2;
    char g1,g2,b1,b2;
    hit1=hit2=rIndx1=rIndx2=cIndx1=cIndx2=0;
    
    // get how many ship hits each player should get during this game
     for(int pRows=1; pRows<ROWS; pRows++){        
        for(int pCols=1; pCols<COLS; pCols++){
            g1=guessP1[pRows][pCols];
            b2=board2[pRows][pCols];
            if((g1=='S') && (b2=='S')){
                hit1++;
                if(hit1==1){
                rIndx1=pRows;
                cIndx1=pCols;
                }
            }
        }         
    }
    for(int row2=1; row2<ROWS; row2++){    
        for(int col2=1; col2<COLS; col2++){            
            g2=guessP2[row2][col2];
            b1=board1[row2][col2];
            if((g2=='S') && (b1=='S')){
                hit2++;
                if(hit2==1){                   
                rIndx2=row2;
                cIndx2=col2;
                }
            }
        }         
    }
    
    // sets max number of games and returns which player to use for a conditional in main()
    if(hit1>hit2){
        maxGms=hit1;
        winner=1;
    }else if(hit1<hit2) {
        maxGms=hit2;
        winner=2;
    } else{
        maxGms=hit1;
        winner=2;
    }
    
    plyrShpBrd(1,2,guessP1,board2,ROWS,COLS); 
    cout << "\nPlayer 1 expected # of HITS: "<< hit1 << endl
         << "1st HIT in round [" << rIndx1<<"]["<<cIndx1<<"]" <<endl<<endl;  
   
    plyrShpBrd(2,1,guessP2,board1,ROWS,COLS); 
    cout << "\nPlayer 2 expected # of HITS: " << hit2 << endl
         << "1st HIT in round [" << rIndx2 <<"]["<<cIndx2<<"]" <<endl<<endl;          
}

// 
void plyrShpBrd(int player,int opponnt,const char guess[][9],const char board[][9], 
                const int ROWS,const int COLS){    
    cout<<endl<<setw(19)<<" "<< "A1 B1 C1 D1 E1 F1 G1 H1 A2 B2 C2 D2 E2 F2 G2 H2\n";         
    cout<<"Player "<<player<<" Guesses:  ";    
    prntArr(guess,ROWS,COLS);     
    cout<<endl<<setw(19)<<"Opponent's Board:  " ;
    prntArr(board,ROWS,COLS);
}

//  prompt user  
void runMenu(string p1Name, char &ch, char &ans, int count1,int count2,int numShp1,int numShp2,
             char guessP1[][9],char guessP2[][9],char board1[][9],char board2[][9],
             int p1GShps,int p2GShps,int ROWS,int COLS,int &maxGms, int &winner,
             unordered_set<string>&names,vector<string> &vNames){
    do {         
        cout << endl << p1Name << " your game has successfully loaded. \n\n"
             << "Press 1: to see a summary of the files that were read.\n"
             << "Press 2: to confirm Guess 2D filled correctly\n"
             << "Press 3: to confirm game board 2D was filled with data read from files,\n"
             << "         and guess 2D were filled randomly.\n"
             << "Press 4: to start your game.\n"
             << "Press 5: to run Top Player's Board.\n"
             << "Press 6: to exit.\n";
        cin  >> ch;

        switch(ch){       
            case '1': fileSum(count1,count2,numShp1,numShp2); break;
                    //cGssArr(const char[][9], const char[][9],const int,const int,int,int); 
            case '2': cGssArr(guessP1, guessP2,ROWS,COLS,p1GShps,p2GShps);break;// confirms guess[][] filled correctly
            case '3': print2DArr(guessP1, guessP2,board1,board2,ROWS,COLS,maxGms,winner); break;       
            case '5': topPlyrs(names);
            case '6': exit(EXIT_SUCCESS); break;
            default: cout << setw(9)<< " " << "Loading.......\n";
        }

        if(ch=='1' || ch=='2' || ch=='3'|| ch=='5'){    
            cout << "Run Menu again? Y or N?\n";
            cin >> ans;
        } else {ans='n';}
    
    // continue doing all the statements above until ans does not equal y or Y
    } while((ans=='y')||(ans=='Y')); 
}

// validates user's input
bool isReady(char ans){
    // conditional validates user's input
    if(ans=='y'){                
        return true;
    } else if(ans=='Y'){                
        return true;
    } else return false;            
}

// display instructions to player
void instruc(string player, const int MAX, int min){    
    cout << endl << setw(2) << " " << "Try to guess the location of \n"
         << setw(6) << " " << "your opponent\'s ship." << endl
         << endl << setw(12)<< " " << player  << endl 
         << setw(2) << " " << "Guess a letter between A-H\n"
         << setw(2) << " " << "and a number between " << min << " and " << MAX/8 << endl;
}

// display hit message when player guesses correctly
void hitMiss(bool isHit, int guess, int shipLoc){    
    cout<<setw(13)<<static_cast<char>(guess)<<"=="<<static_cast<char>(shipLoc)<<"?\n"; 
    if(isHit) cout << setw(20) << "It\'s a HIT!\n" << endl;
    else cout << setw(22) << "It\'s a MISS!\n";
}

// display try again message when both player's guessed wrong
void hitMiss(){
    cout<<endl<<"You Both Missed. Try Again..."<<endl<<endl;
}
// randomly fill guess[][] until at least one of the player's has 3 ships in their array
void fillGuess(char guessP1[][9],char guessP2[][9],char choices[],int ROWS,int COLS,int &p1GShps, int &p2GShps){
    int size=17;
    p1GShps=p2GShps=0;  // initialize both players number of ships to zero
    bool minMet;        // minimum number of ships==3

    do{
        minMet=false;   // set flag

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

// confirm data that was read in is even and contains at least 3 ships
void fileSum(int count1, int count2, int numShp1, int numShp2){   
    cout << endl << setw(3)<<" " << "Read in " << setw(6)<< " " << "P1 Board" << setw(5)<< " "<< "P2 Board" << endl;
    cout << "Total # chars " << setw(8) << right << count1 << "\t \t" << count2 << "\n";
    cout << "Total # ships " << setw(8) << right << numShp1 << "\t \t" << numShp2 << "\n\n";    
}

// save player 1 and all of player 2's names to a new array
void copyAdd(string p2Names[],const int SIZE7, string names[], const int SIZE8, string p1Name){
   
   // copy all of player 2's name into a new array 
   for(int i=0;i<SIZE7;i++){
       names[i]=p2Names[i];
   }
   
   // calculate the last index for names[]
   unsigned int last = SIZE8-1;
   
   // add player 1's name to the end of the names[]
   names[last]=p1Name;      
}

// 
void chkAnswr(char &ans){
    char temp;
    cout << "Would you like to confirm it was a hit? Y or N?  ";
    cin >> temp;
    ans = toupper(temp);
}
// display data from both player's guess arrays. 
void cGssArr(const char guessP1[][9], const char guessP2[][9],
             const int ROWS,const int COLS, int p1GShps, int p2GShps){
    
    cout << "\nConfirming Guess arrays are random and have at least 3 S in one array\n";
    cout << setw(4) << " " << "P1 Guesses"<<endl; 
    prntArr(guessP1,ROWS,COLS);
    cout <<"\nP1 # Ships : " << p1GShps <<endl<<endl;
    
    cout << setw(4) << " " << "P2 Guesses\n";
    prntArr(guessP2,ROWS,COLS);
    cout << endl << "P2 # Ships : " << p2GShps << endl<<endl;         
}

// binary search 
 int binarySrch(string names[], string &name, int SIZE8){
    
    int indx=0,
        first=0,
        last=SIZE8-1,
        middle,
        position=-1;
    
    bool found=false;
    
    set2Upper(name);    // change string to all uppercase letters
    
    while(!found && first<=last){ // search between indices [0,7]
        
        middle = (first + last)/2; // middle index
        if(names[middle]==name){ // check if middle indx equals name
            found=true;
            position=middle;
           
          // if name ASCii value is smaller then its in lower half of array  
        } else if(names[middle]>name){ 
            last= middle-1;
          
          // if name ASCii value is smaller then its in upper half of array
        } else first = middle+1;  
    }      
    return position;
}

// displays game's name and instructions in a banner
void banner(string str){
    
    // reassign variables value
    str="BATTLESHIP"; 
    
    for(int i=0; i<=2; i++){
        if(i==0 || i==2){
            for(int j=0; j<32; j++) {
                cout << "*";       
            } cout << endl;
        } else  cout << setw(21) << str << endl;               
    }        
}
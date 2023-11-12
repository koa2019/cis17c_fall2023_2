/* File:    main.cpp
 * Author:  Danielle 
 * Created: 11-11-23  3 PM
 * Purpose: project1_convertArrays_to_STL_v4
 *         Converts arrays to STL containers before adding it
 *         to cis17C_Project_1_battleship_v3
 * 
 * version 4: 
 * 
 * To do:
 * 
 */

//System Libraries
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
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

void fllGArr(char [][9],char [][9],char [], int, int, int &, int&);

//Function Prototypes
unordered_set<string> setP2Names(string,string&);
unordered_set<string> pushFrntSet(string,string&); 
map<string, float> setTopPlyrs(unordered_set<string> &);
void topPlyrs(unordered_set<string> &);
void prntMapUnO(map<string, float>&);// Prints topPlyrs & hiScores
void prntList(list<float> &);
void prntStrSet(unordered_set<string>&);// Prints player 1 & player 2's names
string set2Upper(string name="name"); // convert string to all uppercase letters

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers    
    
    const int    MIN = 1, // minimum number for rand()
                 MAX = 16; // maximum number for rand()
    const int    SIZE7 = 7,  // size for player 2 names array
                 SIZE8 = 8;
    const int    ROWS = 3,
                 COLS = 9;   // number of cols in 2D array
    const int    SIZE17=17;    // choice array size    
       
//    char    ans, // answer  
//            ch,                 
//            p1Guess=0, // player 1 guess
//            p2Guess, // player 2 guess
//            p1Ship1, // player 1 ship number 1
//            p2Ship1; // player 2 ship number 1
    
    
    int     p1GShps,
            p2GShps;
    char    guessP1[ROWS][COLS]={};
    char    guessP2[ROWS][COLS]={}; 
    // Used to fill each player's guess[][]
    char choices[]={'S','B','S','S','B','S','S','B','S','S','B','S','S','B','S','S','B'};
    
    // Fill guess[][] with choices[]
    fllGArr(guessP1,guessP2,choices,ROWS,COLS,p1GShps,p2GShps);    
    
    // Confirm Guess[][] filled correctly
    //cGssArr(guessP1, guessP2,ROWS,COLS,p1GShps,p2GShps);
    
    
    cout<<endl;
    return 0;
}

/**********  Function Implementations  **************/
// randomly fill guess[][] until at least one of the player's has 3 ships in their array
void fllGArr(char guessP1[][9],char guessP2[][9],char choices[],int ROWS,int COLS,int &p1GShps, int &p2GShps){
    int size=17;
    p1GShps=p2GShps=0;  // initialize both players number of ships to zero
    bool minMet;        // minimum number of ships==3 for each player's guess container

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

//*********************************************************************
/*                              STL                                   */
//*********************************************************************


// function controls the sort and search section
void topPlyrs(unordered_set<string> &names){ 
    
    // Initialize unordered map with pair(topPlyrs,scores)
    map<string, float> topPlyrs; 
    topPlyrs = setTopPlyrs(names);
   
    // bubble sort names & print sorted array
   
    // Print map (key,value) pairs of high scores
    cout << "\nSorted: This week's Top Players \n";
    prntMapUnO(topPlyrs);
    
//    string sName="";
//    cout<<endl<<endl<<"Enter a player's name to return\nwhat place they're in this week. ";
//    cin >> sName; cout<<endl;
//    // Searches for a top player's name and returns this standing
//    auto it = topPlyrs.find(set2Upper(sName)); 
//    if(it==topPlyrs.end()){
//       cout<<"Sorry, "<<sName<<" wasn't found.\n";
//    } else { // Finds player's spot in score board        
//        int count=1;
//        for(auto i=topPlyrs.begin(); i!=it;i++,++count){}
//        cout << (*it).first <<" is in the "
//             << count<<" spot of this week's top player\nwith "
//             << (*it).second <<" points.\n\n";
//    }
    
    //pause(); // pause game so player can view the search findings
   
    // Sorts last week's top scores. 
    //sortSel();   
  }


// Initialize unordered map with pair(topPlyrs,scores)
map<string, float> setTopPlyrs(unordered_set<string> &names){     
    set<float>s{98.98, 99.69, 98.81, 97.43}; 
    list<float>scores{101.9, 99.71, 99.24, 99.18}; 
    std::copy(s.begin(),s.end(),
            std::insert_iterator<std::list<float>>(scores, std::next(scores.begin()))); 
    prntList(scores);
    
    // Initialize map container with a set and a list as its pair(key,value)
    map<string, float> topPlyrs;  
    //map <string,float>::iterator itmap = topPlyrs.begin();
    unordered_set<string>::iterator itr = names.begin();
    list<float>::iterator litr = scores.begin();
    
    int j=0; 
    // Initialize map with a pair("name", hiScore)
    for (itr = names.begin(); itr!=names.end(); itr++,litr++) {  
        // Inserts pairs in the key's alphabetically order
        topPlyrs.insert( 
        pair<string, float>(*itr, *litr)); 
        //cout<<"j="<<j<<" ("<<*itr<<", "<<scores<<") "<<endl;
        j++; 
    }    
    return topPlyrs;
}

void prntList(list<float> &list){
    int i=1;
    std::list<float>::iterator litr = list.begin();
    for(litr=list.begin(); litr!=list.end(); litr++,i++) {
        cout<<i<<". "<<*litr<<"\n";
    }cout<<endl;
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
    for(int i=0;i<n;i++){ p2Names.insert(nameAry[i]);}//prntStrSet(p2Names);    
    return p2Names;
}

// changes string to all uppercase letters
string set2Upper(string name){ 
    string temp=" ";
    temp=name;
    // using transform() function and ::toupper in STL 
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper); 
    return temp;
}

// Print map (key,value) pairs of topPlyrs & high scores
void prntMapUnO(map<string, float> &map){
    int i=1;
    std::map<string, float>::iterator itmap = map.begin();
    cout<<"Map Top Player's Scores\n";
    for (itmap = map.begin(); itmap!=map.end(); itmap++) {
        cout<<i++<<". "<<"("<<setw(8)<<left
            << itmap->first <<","<< itmap->second <<")\n";
    }
}

// Prints names set container
void prntStrSet(unordered_set<string> &set){
    int i=1;
    unordered_set<string>::iterator itr;
    for (itr = set.begin(); itr != set.end(); itr++) {
        cout<<i++<<". "<<*itr<<endl;
    }
    cout<<endl<<endl;
}

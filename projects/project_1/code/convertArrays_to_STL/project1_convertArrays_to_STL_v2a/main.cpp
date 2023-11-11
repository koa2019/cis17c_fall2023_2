/* File:    main.cpp
 * Author:  Danielle 
 * Created: 11-10-23  4:28 PM
 * Purpose: CIS 17C Project 1
 * 
 * v2a:  
 * changed topPlyr pair from (name,score) to (score,name) for high score board
 * 
 * 
 * map:
*/

//System Libraries
#include <bits/stdc++.h> 
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <climits> // char and int maximums
#include <cfloat>  //float maximum
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include<unordered_map>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
unordered_set<string> setP2Names(string p1Name);
unordered_set<string> pushFrntSet(unordered_set<string> &,string); 
std::map<float, string, greater<float> > setTopPlyrs(unordered_set<string> &);
bool cmp(pair<string, int>& a, pair<string, int>& b);
void sort(std::map<float, string>& M);

void prntMapUnO(map<float, string, greater<float> >&);// Prints topPlyrs & hiScores
void prntStrSet(unordered_set<string>&);// Prints player 1 & player 2's names


void topPlyrs(string [],int,string [],int,string,vector<string> &);

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
    
    string p1Name = "Danielle", 
           p2Name = " ";         
    //unordered_set<string> vNames=({"VICTOR", "DANI", "STEPHANIE", "MARTY", "BART", "ALEX", "ROBERT", "RENEE"});
    
    
    
    // Initialize set with string array values
    unordered_set<string> p2Names = setP2Names(p1Name);
    cout<<"set<string> p2Names =\n";
    //prntStrSet(p2Names);  
    
    // Push string into set
    unordered_set<string> names = pushFrntSet(p2Names,p1Name);
    cout << "\nUnsorted: Players \n";
    prntStrSet(names);
   
    // Initialize unordered map with pair(topPlyrs,scores)
    std::map<float, string, greater<float>> topPlyrs; 
    topPlyrs = setTopPlyrs(names);

    // Print map pair(score,name) 
    cout << "\nSorted: High Scores \n";
    prntMapUnO(topPlyrs);
  
    string sName;
    cout << "Enter a player's name to return what place they're in this week. \n";
    cin >> sName;
    //int score = binarySrch(names,sName,SIZE8);
//   if(score==-1){
//       cout << "Sorry, " << sName << " wasn't found.\n";
//   } else cout << sName << " is in the " << score+1 << " spot of this week's top player.\n\n";
//   
   //pause(); // pause game so player can view the search findings
   
    cout<<endl;
    return 0;
}

/**********  Function Implementations  **************/


// function controls the sort and search section
void topPlyrs(string p2Names[],int SIZE7,string names[],int SIZE8, string p1Name,
              vector<string> &vNames){

   string sName;
   cout << "Enter a player's name to return what place they're in this week. \n";
   cin >> sName;
   //int score = binarySrch(names,sName,SIZE8);
//   if(score==-1){
//       cout << "Sorry, " << sName << " wasn't found.\n";
//   } else cout << sName << " is in the " << score+1 << " spot of this week's top player.\n\n";
//   
   //pause(); // pause game so player can view the search findings
   
   // selection sort
   //sortSel(vNames);   
  }

//*********************************************************************
/*                              STL                                   */
//*********************************************************************


// Initialize unordered map with pair(topPlyrs,scores)
std::map<float, string, greater<float> > setTopPlyrs(unordered_set<string> &names){     
    float scores[]={98.98, 99.69, 99.81, 99.43, 101.9, 99.71, 99.24, 99.78}; 
    int j=0; 
    std::map<float, string, greater<float> > topPlyrs;  
    std::map<float, string>::iterator itmap = topPlyrs.begin();
    std::unordered_set<string>::iterator itr = names.begin();
    
    // Initialize map with a pair("name", hiScore)
    for (itr = names.begin(); itr!=names.end(); itr++) {      
        topPlyrs.insert( 
        pair<float, string>(scores[j],*itr)); 
        //cout<<"j="<<j<<" ("<<*itr<<", "<<scores<<") "<<endl;
        j++; 
    }    
    return topPlyrs;
}
 

// Push string to front of set
unordered_set<string> pushFrntSet(unordered_set<string> &p2Names, string p1Name){
    
    // copy all of player 2's name into a new array 
    unordered_set<string> names(p2Names.begin(), p2Names.end());   

    // add player 1's name to the end of the names[] 
    names.insert(p1Name);
    //cout<<"Combined 2 sets and then inserted "<<p1Name<<" in front:\n";
    //prntStrSet(names);
    return names;
}


unordered_set<string> setP2Names(string p1Name){    
    // Copy array to a set
    string nameAry[]={"MARTY", "BART", "ALEX", "CHRIS", "GABE", "VICTOR", "JILLIAN"}; 
    int n = sizeof(nameAry)/sizeof(nameAry[0]);
    unordered_set<string> p2Names;    
    for(int i=0;i<n;i++){ p2Names.insert(nameAry[i]);}
    //prntStrSet(p2Names);    
    return p2Names;
}

// Print map (key,value) pairs of topPlyrs & high scores
void prntMapUnO(map<float, string, greater<float> > &topPlyrs){
    int i=1;
    std::map<float, string>::iterator itmap = topPlyrs.begin();
    cout<<"Map Top Player's Scores\n";
    for(itmap = topPlyrs.begin(); itmap!=topPlyrs.end(); itmap++) {
        cout<<i++<<". "<<"("<<setw(8)<<left
            << (*itmap).second <<right<<","<< (*itmap).first <<")\n";
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

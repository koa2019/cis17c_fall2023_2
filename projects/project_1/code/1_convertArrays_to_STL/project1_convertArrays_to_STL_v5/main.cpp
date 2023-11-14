/* File:    main.cpp
 * Author:  Danielle 
 * Created: 11-13-23  3 PM
 * Purpose: project1_convertArrays_to_STL_v5
 *         Converts arrays to STL containers before adding it
 *         to cis17C_Project_1_battleship_v3
 * 
 * version 5: 
 * Implement stack on board array
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
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions


//STL Function Prototypes
void concepts();
void constructor();
void setNames(unordered_set<string>&);
unordered_set<string> setSet(); 
void setShips(queue<string>&);
void setStack(stack<string>&, list<string>&);
void fillGuess();
string getMin(unordered_set<string>&);//returns min name
string getName();  // get player 1's name using pass by reference
map<string, float> setTopPlyrs(unordered_set<string> &);
void topPlyrs(unordered_set<string> &);
void pause();
void prntMap(map<string, float>&);// Prints topPlyrs & hiScores
void prntListFlt(list<float>&); // High Scores
void prntListStr(list<string>&); // Names
void prntQue(queue<string> &);
void prntSetStr(unordered_set<string>&);// Prints player 1 & player 2's names
void prntStckFIFO(stack<string>&);
void prntStckRev(stack<string>&);
void reverse(stack<int>&);
void insert_at_bottom(stack<int>&,int);
string set2Upper(string name="name"); // convert string to all uppercase letters
void shuffleThis();//shuffles int, char, string array BUT not a set container

// Array Function prototypes
void menu();

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
           name2  = "COMPUTER";     
    
    // Set player 1 name and Push into set       
    p1Name=getName();  // Set player 1's name to uppercase case 
    cout<<" -> "<<p1Name<<".\nUsed transform(std::toupper)\n";
    pause();
    
    
    /*   Move to Player's Constructor  */    
    // Initialize set with a list of names 
    cout<<"Pushed an array into a List.\n";
    unordered_set<string> names = setSet(); // returns set
//    cout<<"Copied a List into a Set.\n";
//    cout<<"Unsorted Set of Players: \n";
//    prntSetStr(names);
//    pause();
//  
//    
//    // Insert player 1 name into a set
//    cout<<"\nInserted "<<p1Name<<" into a Set.\n";
//    names.insert(p1Name);
//    cout<<"Unsorted Set of Players: \n";
//    prntSetStr(names);    
//    pause();
//    
//    // Set player 2's names
//    // Use std:min() to pick player 2's name
//    name2 = getMin(names);
//    cout<<"\t"<<p1Name<<" vs "<<name2<< "!\n";  
//    pause();
//    
//    
//    // Sets, lists, maps 
//    // Sort & search high scores board   
//    topPlyrs(names);
//    pause();
    
    
    // Stack
    cout<<"\n\nPush List into Stack.\n";
    stack<string> stack;
    // player 2 names to mimic playing someone online
    list<string> list{"MARTY", "BART", "ALEX", "CHOPPER", "MAUL", "ANAKIN", "KENOBI"};
    setStack(stack,list);// setStack(stack&,list)    
    cout<<"List of names\n";
    prntListStr(list);
    cout<<"Stack (Last In First Out).\n";
    prntStckFIFO(stack);
    cout<<"\nReverse Order Stack.\n";
    prntStckRev(stack);
    pause();
    
    
    // Queue
    cout<<"\n\n\tQueue Container\nEach player has 3 ships that can be hit.\n"; 
    queue<string> ships;
    setShips(ships);      
    prntQue(ships);  
    pause();
    
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

// Use to show concepts
// Initialize a list with an array, then initialized set2 with set1
// Future projects: you can just return p2Names. I wanted to different ways to initialize a set.
unordered_set<string> setSet(){
    
    // Copy array to a set
    string nameAry[]={"MARTY", "BART", "ALEX", "CHOPPER", "MAUL", "ANAKIN", "KENOBI"}; 
    int i=0, n = sizeof(nameAry)/sizeof(nameAry[0]);    

    // Initialize set with array 
    list<string> list;    
    std::list<string>::iterator it = list.begin();
    for(i=0;i<n;i++, it++){ list.push_back(nameAry[i]);}    
    cout<<"List of Player 2 names:\n";
    prntListStr(list);
    
    // Initialize set with a set
    unordered_set<string> names(list.begin(), list.end());      
    return names;
}

// With with my MySTL class
// Same as setSet() expect it's what i think I'll use when i move it to a class
// Initialize a set with a list
void setNames(unordered_set<string> &names){    
    
//    // player 2 names to mimic playing someone online
//    list<string> p2Names{"MARTY", "BART", "ALEX", "CHOPPER", "MAUL", "ANAKIN", "KENOBI"};
//    cout<<"List of player 2 names\n";
    //prntListStr(list);
//    for(auto &i : p2Names){cout<<i<<endl;}cout<<endl;
//    
//    // copy list into set of names
//    names(p2Names.begin(), p2Names.end());
//   //prntSetStr(names);
}

// use in class
// Initialize stack with list 
// Loops through list and pushes a name to the stack
void setStack(stack<string> &stack, list<string> &list){    
    std::list<string>::iterator it = list.begin();
    for(int n=0;n<list.size();n++, it++){ stack.push(*it);}
    //cout<<"Stack FIFO\n";prntStckFIFO(stack);
   //cout<<"Stack Reverse\n";prntStckRev(stack);
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
    cout<<"\tLocating your opponent...\n";
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
    cout<<"\tmin("<< *itr<<","<<last<<") = "<<min<<"\n\n";
    return min;
}


// function controls the sort and search section
void topPlyrs(unordered_set<string> &names){ 
    
    // Initialize unordered map with pair(topPlyrs,scores)
    std::map<string, float> topPlyrs; 
    topPlyrs = setTopPlyrs(names);    
   
    
    // Print map (key,value) pairs of high scores
    cout<<"Map Sorted Alphabetically:  \n";
    cout<<"Map pair(set<string>, list<float>)\n";
    prntMap(topPlyrs);// Print unordered map (key,value) pairs of topPlyrs & high scores
    
    string sName="";
    cout<<endl<<endl<<"Enter a player's name to return\nwhat place they're in this week.\n";
    cin >> sName; 
    cin.ignore(); 
    cout<<endl;        
   
    // Searches for a top player's name and returns this standing
    auto it = topPlyrs.find(set2Upper(sName)); 
    if(it==topPlyrs.end()){
       cout<<"Sorry, "<<sName<<" wasn't found.\n";
    } else {  
        // Count which place this person placed in this week's standings
        int count=1;
        for(auto i=topPlyrs.begin(); i!=it;i++,++count){}
        // Print results
        cout <<(*it).first <<" is in the "
             << count<<" spot \nfor this week's top player \nwith "
             << (*it).second <<" points.\n\n";
    }    
    //pause(); // pause game so player can view the search findings 
    ////sortSel(); // Sorts last week's top scores.   
  }


// Initialize unordered map with pair(topPlyrs,scores)
// https://en.cppreference.com/w/cpp/iterator/insert_iterator
map<string, float> setTopPlyrs(unordered_set<string> &names){        
 
    // Set
    set<float>s{98.98, 99.69, 98.81, 97.43};
    cout<<"Set:\n";
    for(auto &i : s){cout<<i<<endl;}    
    
    // Partial list
    list<float>scores{101.9, 99.71, 99.24, 99.18};     
    cout<<"\nPartial List:\n";    
    prntListFlt(scores);
    
    
    // Copy set into list
    std::copy(s.begin(),s.end(), 
            std::insert_iterator<std::list<float>>(scores, std::next(scores.begin()))); 
    cout<<"Set copied into List:\n";
    prntListFlt(scores);
    
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
    cout<<name1<<" ";
    //cin>>name1; //change to ostream_iterator
    //cin.ignore();
    //cout << endl; 
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


// Print a list
void prntListFlt(list<float> &list){
    int i=1;
    std::list<float>::iterator litr = list.begin();
    for(litr=list.begin(); litr!=list.end(); litr++,i++) {
        cout<<i<<". "<<*litr<<"\n";
    }cout<<endl;
}
// Print a list
void prntListStr(list<string> &list){
    int i=1;
    std::list<string>::iterator litr = list.begin();
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
// Can i const stack so it doesn't delete the original stack?
// Print a stack using a temp stack, so it doesn't delete the stack forever
void prntStckFIFO(stack<string> &stack){
    int n=1;
    std::stack<string> temp;
    temp=stack;
    while(temp.empty()==false){
        string t = temp.top();
        cout<<n++<<". "<<t<<"\n";
        temp.pop();
    }     
}

// Can i const stack so it doesn't delete the original stack?
// Print a stack using a temp stack, so it doesn't delete the stack forever
void prntStckRev(stack<string> &stack){
    int n=1;
    std::stack<string> temp;
    //temp=stack;
    while(stack.empty()==false){
        temp.push(stack.top());
        stack.pop();
    }  
    while(temp.empty()==false){        
        string t = temp.top();       
        cout<<n++<<". "<<t<<"\n";
        temp.pop(); 
        stack.push(t);// To restore contents of the original stack.
    }    
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
// pause screen before game starts
void pause(){    
    cout << "\n\nPress enter to continue. ";
    //cin.ignore();
    cin.get();   
    cout<<endl;
}



/****************************Reverse Stack*************************************/
// Below is a recursive function
// that inserts an element
// at the bottom of a stack.
//https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
void insert_at_bottom(stack<int>& st, int x)
{
 
    if (st.size() == 0) {
        st.push(x);
    }
    else {
 
        // All items are held in Function Call
        // Stack until we reach end of the stack
        // When the stack becomes empty, the
        // st.size() becomes 0, the above if
        // part is executed and the item is
        // inserted at the bottom
 
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);
 
        // push allthe items held in
        // Function Call Stack
        // once the item is inserted
        // at the bottom
        st.push(a);
    }
}
// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse(stack<int>& st)
{
    if (st.size() > 0) {
 
        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        int x = st.top();
        st.pop();
        reverse(st);
 
        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insert_at_bottom(st, x);
    }
    return;
}
/****************************Reverse Stack*************************************/
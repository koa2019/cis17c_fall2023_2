#include "Game.h"
//#include <bits/stdc++.h> 
//#include <string>
using namespace std;  //STD Name-space where Library is compiled

//**********************************************************
//                  Default Constructor
//**********************************************************
Game::Game(){
    
    
    setName(set2Upper("Santa"));
    name2=set2Upper("Computer");
    
    // Initialize set with a list of fnames 
    cout<<"Pushed an array into a List.\n";
    setSet();// first names
//    cout<<"Copied a List into a Set.\n";
//    cout<<"Unsorted Set of Players: \n";
//    prntSetStr(fnames);
//    pause();
//  
//    // Insert player 1 name into a set
//    cout<<"\nInserted "<<name<<" into a Set.\n";
//    fnames.insert(name);
//    cout<<"Unsorted Set of Players: \n";
//    prntSetStr(fnames);    
//    pause();
//     
//    
//    // Stack
//    cout<<"\n\nPush List into Stack.\n";
//    // player 2 fnames to mimic playing someone online
//    list<string> list{"Donald Duck", "Mickey", "Chip", "Smurfette", "Dale", "Yoda", "Jerry Rice"};
//    cout<<"List of names\n";
//    prntListStr(list);
//    setStack(list);//(stack,list);// setStack(stack&,list)    
//    cout<<"Stack (Last In First Out).\n";
//    prntStckFIFO();
//    cout<<"\nReverse Order Stack.\n";
//    prntStckRev();
//    pause();
//    
//    
//    // Queue
//    setShips();      
//    cout<<"\n\tQueue Container\nEach player has 3 ships that can be hit.\n"; 
//    prntQue();   
//    pause();
    
    
    // Sets, lists, maps 
    setTopPlyrs(); 
    getTopPlyrs();// Initialize unordered map with pair(topPlyrs,scores)    
   pause();
    
    // CHANGE FROM Stack TO MAPS
    //fillGuess(); 
    
    //start();
}

void Game::start(){    
    
    // Set player 1 name and Push into set       
    name = getName();  // Set player 1's name to uppercase case 
    cout<<" -> "<<name<<".\nUsed transform(std::toupper)\n";
    pause();
 
    // Used min() to set player 2's name
    name2 = getMin();
    cout<<"\t"<<name<<" vs "<<name2<< "!\n";  
    pause();  
}

// Set map(set,list)
// function controls the sort and search section
void Game::getTopPlyrs(){ 
    
    // Print map (key,value) pairs of high scores
    cout<<"Map Sorted Alphabetically:  \n";
    cout<<"Map pair(set<string>, list<float>)\n";
    prntMap(topPlyrs);// Print unordered map (key,value) pairs of topPlyrs & high scores
    
    // Find max_element
    //https://www.techiedelight.com/find-element-with-the-maximum-value-in-a-map-in-cpp/
    auto maxPair = std::max_element(topPlyrs.begin(), topPlyrs.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
                }); 
    cout<<"\n\nCongratulate "<<maxPair->first<<" for being\nthis week's winner \nwith "<< maxPair->second<<" points!\n"; 
    
    
    // Searches for a top player's name and returns this standing
    string sName="";
    cout<<endl<<endl<<"Enter a player's name to return\nwhat place they're in this week.\n";
    cin >> sName; 
    cin.ignore(); 
    cout<<endl;        
   
    // Find name in top scores board    
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
//    ////pause(); // pause game so player can view the search findings 
//    ////sortSel(); // Sorts last week's top scores.   
}


// Initialize unordered map with pair(topPlyrs,scores)
// https://en.cppreference.com/w/cpp/iterator/insert_iterator
void Game::setTopPlyrs(){        
 
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
    unordered_set<string>::iterator itr = fnames.begin();
    list<float>::iterator litr = scores.begin();
    
    // Set map with a pair("name", hiScore)
    int j=0; 
    for (itr = fnames.begin(); itr!=fnames.end(); itr++,litr++) {       
        // Inserts pairs in the key's alphabetically order
        topPlyrs.insert( 
        pair<string, float>(*itr, *litr)); 
        //cout<<"j="<<j<<" ("<<*itr<<", "<<scores<<") "<<endl;
        j++; 
    }    
}


// Set player 1's name and convert to uppercase letters
string Game::getName(){ 
    string str="Danielle";
    cout << "\nPlayer 1: Enter your name\n";
    //cin>>str; //change to ostream_iterator
    //cin.ignore();
    cout<<str<<" ";
    //cout << endl; 
    return set2Upper(str);  //convert user input into capital letters
}

// Add a for loop to find the shortest name in names set container
string Game::getMin(){        
    cout<<"\tLocating your opponent...\n";
    unordered_set<string>::iterator itr = fnames.begin();
    unordered_set<string>::iterator end = fnames.begin();
    itr++;
    int n = fnames.size()-1;
    int i = 1+(rand()%n);// change this to shuffle
    std::advance(end, i);//https://stackoverflow.com/questions/20477545/element-at-index-in-a-stdset
    string last = *end;
    //cout<<"n="<<n<<"  fnames["<<i<<"] = "<<last<<endl;
    string min = std::min({*itr, last},
            [](const std::string_view s1, const std::string_view s2)
            {
                return s1.size() < s2.size();
            });
    cout<<"\tmin("<< *itr<<","<<last<<") = "<<min<<"\n\n";
    return min;
}


// Use to show concepts
// Initialize a list with an array, then initialized set2 with set1
// Future projects: you can just return p2Names. I wanted to different ways to initialize a set.
void Game::setSet(){
    
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
    //fnames(list.begin(), list.end());      
    it = list.begin();
    for(i=0;i<list.size();i++, it++){ 
        fnames.insert(*it);
        //cout<<*it<<endl;
    }   
}


void Game::setShips(){
    nShips.push("ship1");
    nShips.push("ship2");
    nShips.push("ship3");    
}

// Initialize stack with list 
// Loops through list and pushes a name to the stack
void Game::setStack(list<string> &list){ //(stack<string> &stack, list<string> &list){    
    std::list<string>::iterator it = list.begin();
    for(int n=0;n<list.size();n++, it++){ stack.push(*it);}
    //cout<<"Stack FIFO\n";prntStckFIFO(stack);
   //cout<<"Stack Reverse\n";prntStckRev(stack);
}


// Print a list
void Game::prntListFlt(list<float> &list){
    int i=1;
    std::list<float>::iterator litr = list.begin();
    for(litr=list.begin(); litr!=list.end(); litr++,i++) {
        cout<<i<<". "<<*litr<<"\n";
    }cout<<endl;
}

// Print a list
void Game::prntListStr(list<string> &list){
    int i=1;
    std::list<string>::iterator itr = list.begin();
    for(itr=list.begin(); itr!=list.end(); itr++,i++) {
        cout<<i<<". "<<*itr<<"\n";
    }cout<<endl;
}



// Print unordered map (key,value) pairs of topPlyrs & high scores
void Game::prntMap(map<string, float> &map){
    int i=1;
    std::map <string, float>::iterator itmap = map.begin();
    cout<<"Map Top Player's Scores\n";
    for (itmap = map.begin(); itmap!=map.end(); itmap++) {
        cout<<i++<<". "<<"("<<setw(8)<<left
            << itmap->first <<","<< itmap->second <<")\n";
    }
}


void Game::prntQue(){
    queue<string> temp1;
    while(!nShips.empty()){
        temp1.push(nShips.front());
        nShips.pop();
    }
    while (temp1.empty() == false)
    {        
        string t1 = temp1.front();        
        cout<<t1<<" \n";
        temp1.pop(); 
        nShips.push(t1);   // To restore contents of the original stack.
    }    
}
// Can i const stack so it doesn't delete the original stack?
// Print a stack using a temp stack, so it doesn't delete the stack forever
void Game::prntStckFIFO(){//stack<string> &stack){
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
void Game::prntStckRev(){//stack<string> &stack){
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

// Prints names set container
void Game::prntSetStr(unordered_set<string> &set){
    int i=1;
    std::unordered_set<string>::iterator itr;
    for (itr = set.begin(); itr != set.end(); itr++) {
        cout<<i++<<". "<<*itr<<endl;
    }
    cout<<endl;
}


// Convert string to all uppercase letters
string Game::set2Upper(string str){ 
    transform(str.begin(), str.end(), str.begin(), ::toupper); 
    return str;
}


// pause screen before game starts
void Game::pause(){    
    cout << "\nPress enter to continue. ";
    //cin.ignore();
    cin.get();   
    cout<<endl;
}

////shuffles int, char, string array BUT not a set container
//void Game::shuffleThis(){
//    //Shuffle https://www.educba.com/c-plus-plus-shuffle/
//    //Shuffle doesn't work with set<>names
//    array<int,8> shuf {19,24,37,42,54,76,58,53};
//    //array<char,6> shuf {'A', 'B', 'C', 'D', 'E', 'F'};
//    unsigned num = chrono::system_clock::now().time_since_epoch().count();
//    shuffle (shuf.begin(), shuf.end(), default_random_engine(num));
//    cout << "The numbers after shuffling are:";
//    for (auto& x: shuf) cout << ' ' << x;
//    cout << '\n';
//}
//
///****************************Reverse Stack*************************************/
//// Below is a recursive function
//// that inserts an element
//// at the bottom of a stack.
////https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
//void Game::insert_at_bottom(stack<int>& st, int x)
//{
// 
//    if (st.size() == 0) {
//        st.push(x);
//    }
//    else {
// 
//        // All items are held in Function Call
//        // Stack until we reach end of the stack
//        // When the stack becomes empty, the
//        // st.size() becomes 0, the above if
//        // part is executed and the item is
//        // inserted at the bottom
// 
//        int a = st.top();
//        st.pop();
//        insert_at_bottom(st, x);
// 
//        // push allthe items held in
//        // Function Call Stack
//        // once the item is inserted
//        // at the bottom
//        st.push(a);
//    }
//}
//// Below is the function that
//// reverses the given stack using
//// insert_at_bottom()
//void Game::reverse(stack<int>& st)
//{
//    if (st.size() > 0) {
// 
//        // Hold all items in Function
//        // Call Stack until we
//        // reach end of the stack
//        int x = st.top();
//        st.pop();
//        reverse(st);
// 
//        // Insert all the items held
//        // in Function Call Stack
//        // one by one from the bottom
//        // to top. Every item is
//        // inserted at the bottom
//        insert_at_bottom(st, x);
//    }
//    return;
//}
///****************************Reverse Stack*************************************/

#include "TopPlyrsBrd.h"
#include "AVLTree.h" 
#include <bits/stdc++.h> 
using namespace std;  //STD Name-space where Library is compiled

//**********************************************************
//                  Default Constructor
//**********************************************************
TopPlyrsBrd::TopPlyrsBrd(){

    setName(set2Upper("Santa"));   
    
    // ******************************************
    //           deque integer section
    // ******************************************
    deqIntSz=10;
    cout<<"\n\nDeque default iterator is a Random Access Iterator\n";
    setDeqInt();
    cout<<"Int Deque before shuffle: ";
    prntDeqInt();
    cout<<"Int Deque after  shuffle: ";
    shuffleThis(deqIndx);
    prntDeqInt();
    //pause();
    
    // ******************************************
    //       Using AVL to balance a binary tree
    // ******************************************    
    // Fill tree with random numbers    
    AVLTree avl;
    int choice, item;
    int num1=0, num2=0;  
    const int SIZE = 5;
    int arr[]={8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
    vector<int> node;
    
    for(auto &i : deqIndx){
        //cout<<i<<" ";
        avl.root = avl.insert(avl.root, i);//(avl.root, arr[i]);
    } //cout<<endl;    
    cout<<"AVL In-order Traversal: ";
    avl.inorder(avl.root);
    
    // Insert 5 random numbers into binary tree
    for(int i=0;i<SIZE;i++){        
        for(int j=0;j<7;j++){//shuffle so i hopefully dont get duplicates
            num1 = rand()%10;// [0,10)  
            num2 = num1 + (rand()%50+1);// [1,50]  
        }
        node.push_back(num2);// Push rand number into vector
        //cout<<"num2 = "<<num2<<"  node="<<node[i]<<" ";     
        avl.root = avl.insert(avl.root, num2);//(avl.root, arr[i]);
    } cout<<endl;
    
    cout<<"\nInserted "<<node.size()<<" nodes in AVL Tree:\n";
    for(int i=0;i<node.size();i++){cout<<node[i]<<" ";}
    cout<<endl<< "Inserted 5 nodes into AVL tree: "<<endl;
    avl.inorder(avl.root); 
    int height = avl.height(avl.root);
    num1 = rand()%height;// [0,10)
    cout<<"\n\nAVL Tree height: "<<height<<endl;
    cout<<"Left is smaller than right side\n";
    for(int i=1;i<=height;i++){
        cout<<endl<<"Level: "<<i<<" = ";
        avl.prntLev(avl.root,i);
    }
    cout<<endl<<endl<<"Dr. Lehr I was only able to implement AVL Tree\n"
        <<"because I wasted hours trying to make a recursive \n"
        <<"quick_sort() work with Simple Vectors Linked List and\n"
        <<"a float deque work with my AVL Tree.\n"
        <<"You can find this code in TopPlyrsBrd.cpp line 30. Sorry :/\n";
    cout<<endl<<endl;
    pause();
    
    // ******************************************
    //           deque float section
    // ******************************************
    deqFltSz=10;
    cout<<"\n\nDeque default iterator is a Random Access Iterator\n";
    setDeqFlt();
    cout<<"Float Deque before shuffle:\n";
    prntDeqFlt();
//    cout<<"Float Deque after shuffle:\n";
//    shuffleThis(deqFlt);
//    prntDeqFlt();
    cout<<endl<<endl;
    pause();
    
    

    
    
    
    // Initialize set with a list of fnames 
    cout<<"Pushed array into a List.\n";
    setSet();// first names 
    fnSize=fnames.size();
    //    cout<<"Copied a List into a Set.\n";
    //    cout<<"Unsorted Set of Players: \n";
    //    prntSetStr(fnames);
    //    //pause();     
    
  
    // Insert player 1 name into a set
    cout<<"\nInserted "<<name<<" into a Set.\n";
    fnames.insert(name);
    //cout<<"Unsorted Set of Players: \n";
    //prntSetStr(fnames);    
    //pause();
   
    
    // Stack
    cout<<"\n\nPush List into Stack.\n";
    // player 2 fnames to mimic playing someone online
    list<string> list{"Donald Duck", "Mickey", "Chip", "Smurfette", "Dale", "Yoda", "Jerry Rice"};
    cout<<"List of names\n";
    prntListStr(list);
    setStack(list);//(stack,list);// setStack(stack&,list)    
    // cout<<"Stack (Last In First Out).\n";
    // prntStckFIFO();
    // cout<<"\nReverse Order Stack.\n";
    // prntStckRev();
    // //pause();
               
    // Sets, lists, maps 
    setTopPlyrs(); 
    getTopPlyrs();// Initialize unordered map with pair(topPlyrs,scores)    
    //pause();  
    run();
    cout<<endl<<endl;
}
void TopPlyrsBrd::run(){
    cout<<"Copied a List into a Set.\n";
    cout<<"Unsorted Set of Players: \n";
    prntSetStr(fnames);
    //pause();   
    
    cout<<"Unsorted Set of Players: \n";
    prntSetStr(fnames);    
    //pause();
        
    cout<<"Stack (Last In First Out).\n";
    prntStckFIFO();
    cout<<"\nReverse Order Stack.\n";
    prntStckRev();
    //pause();
}

/*****************************************************************/
//                 deque functions
/*****************************************************************/
// Create array of random high scores 
void TopPlyrsBrd::setDeqFlt(){
    deqFlt.assign(deqFltSz,0);// fill constructor. Assigns new contents to the deque container, replacing its current contents
    for(int i=0; i<deqFltSz;i++){ 
        int num = (rand()%18)+99;
        float randNum = num*1.1;
        deqFlt.at(i) = randNum; 
    } 
}
void TopPlyrsBrd::prntDeqFlt(){
    for(auto &d : deqFlt){cout<<d<<" ";} cout<<endl;
}
// Create array of index to keep track of each player   
void TopPlyrsBrd::setDeqInt(){
    // deque has to already be initialized
    int num[15]={19,11,9,4,3,15,34,1,17,18,25,78,66,99,45};
    deqIndx.assign(deqIntSz,0);// fill constructor. Assigns new contents to the deque container, replacing its current contents
    for(int i=0; i<deqIntSz;i++){ 
        deqIndx.at(i)=num[i]; 
    } 
}
void TopPlyrsBrd::prntDeqInt(){
    for(auto &d : deqIndx){cout<<d<<" ";} cout<<endl;
}
    
/*****************************************************************/
// Set map(set,list)
// function controls the sort and search section
/*****************************************************************/
void TopPlyrsBrd::getTopPlyrs(){ 
    
    // Print map (key,value) pairs of high scores
    cout<<"Map Sorted Alphabetically:  \n";
    cout<<"Map pair(set, list)\n";
    prntMap(topPlyrs);// Print unordered map (key,value) pairs of topPlyrs & high scores
    
    // Find max_element
    //https://www.techiedelight.com/find-element-with-the-maximum-value-in-a-map-in-cpp/
    auto maxPair = std::max_element(topPlyrs.begin(), topPlyrs.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
                }); 
                
    cout<<"\n\nstd::max()\nCongratulate "
        <<maxPair->first<<" for being\nthis week's winner \nwith "
        << maxPair->second<<" points!\n"; 
    
    
    // Searches for a top player's name and returns this standing
    string sName="marty";
    cout<<endl<<endl<<"Enter a player's name to return\nwhat place they're in this week.\n";
    cin>>sName; 
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


/*****************************************************************/
// Initialize unordered map with pair(topPlyrs,scores)
// https://en.cppreference.com/w/cpp/iterator/insert_iterator
/*****************************************************************/
void TopPlyrsBrd::setTopPlyrs(){        
 
    // Set. Make these pairs(i,99.1)
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


/*****************************************************************/
// Picks a random number [0,fnames.size()-1], moves iterator
/*****************************************************************/
string TopPlyrsBrd::getMin(){        
    cout<<"\tLocating your opponent...\n";
    unordered_set<string>::iterator itr = fnames.begin();
    unordered_set<string>::iterator end = fnames.begin();
    end++;//itr++;
    int n = fnSize-1;
    int i = 1+(rand()%n);// change this to shuffle
    // Move iterator to this element in container
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


/*****************************************************************/
// 		Use to show concepts
// Initialize a list with an array, then initialized set2 with set1
// Future projects: you can just return p2Names. I wanted to different ways to initialize a set.
/*****************************************************************/
void TopPlyrsBrd::setSet(){
    
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


/*****************************************************************/
// 				Initialize stack with list 
// Loops through list and pushes a name to the stack
/*****************************************************************/
void TopPlyrsBrd::setStack(list<string> &list){ //(stack<string> &stack, list<string> &list){    
    std::list<string>::iterator it = list.begin();
    for(int n=0;n<list.size();n++, it++){ stack.push(*it);}
    //cout<<"Stack FIFO\n";prntStckFIFO(stack);
   //cout<<"Stack Reverse\n";prntStckRev(stack);
}


/*****************************************************************/
// 					Print a list float
/*****************************************************************/
void TopPlyrsBrd::prntListFlt(list<float> &list){
    int i=1;
    std::list<float>::iterator litr = list.begin();
    for(litr=list.begin(); litr!=list.end(); litr++,i++) {
        cout<<i<<". "<<*litr<<"\n";
    }cout<<endl;
}


/*****************************************************************/
// 				Print a list string
/*****************************************************************/
void TopPlyrsBrd::prntListStr(list<string> &list){
    int i=1;
    std::list<string>::iterator itr = list.begin();
    for(itr=list.begin(); itr!=list.end(); itr++,i++) {
        cout<<i<<". "<<*itr<<"\n";
    }cout<<endl;
}


/*****************************************************************/
// Print unordered map (key,value) pairs of topPlyrs & high scores
/*****************************************************************/
void TopPlyrsBrd::prntMap(map<string, float> &map){
    int i=1;
    std::map<string, float>::iterator itmap = map.begin();
    cout<<"Top Player's Scores\n";
    for (itmap = map.begin(); itmap!=map.end(); itmap++) {
        cout<<i++<<". "<<"("<<setw(8)<<left
            << itmap->first <<","<< itmap->second <<")\n";
    }
}


/*****************************************************************/
//
/*****************************************************************/
void TopPlyrsBrd::prntQue(queue<string> &que){
    queue<string> temp1;
    while(!que.empty()){
        temp1.push(que.front());
        que.pop();
    }
    while (temp1.empty() == false)
    {        
        string t1 = temp1.front();        
        cout<<t1<<" \n";
        temp1.pop(); 
        que.push(t1);   // To restore contents of the original stack.
    }    
}


/*****************************************************************/
// Can i const stack so it doesn't delete the original stack?
// Print a stack using a temp stack, so it doesn't delete the stack forever
/*****************************************************************/
void TopPlyrsBrd::prntStckFIFO(){//stack<string> &stack){
    int n=1;
    std::stack<string> temp;
    temp=stack;
    while(temp.empty()==false){
        string t = temp.top();
        cout<<n++<<". "<<t<<"\n";
        temp.pop();
    }     
}


/*****************************************************************/
// Can i const stack so it doesn't delete the original stack?
// Print a stack using a temp stack, so it doesn't delete the stack forever
/*****************************************************************/
void TopPlyrsBrd::prntStckRev(){//stack<string> &stack){
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

/*****************************************************************/
// 				Prints names set container
/*****************************************************************/
void TopPlyrsBrd::prntSetStr(unordered_set<string> &set){
    int i=1;
    std::unordered_set<string>::iterator itr;
    for (itr = set.begin(); itr != set.end(); itr++) {
        cout<<i++<<". "<<*itr<<endl;
    }
    cout<<endl;
}


/*****************************************************************/
// 			Convert string to all uppercase letters
/*****************************************************************/
string TopPlyrsBrd::set2Upper(string str){ 
    transform(str.begin(), str.end(), str.begin(), ::toupper); 
    return str;
}


/*****************************************************************/
// 			pause screen before game starts
/*****************************************************************/
void TopPlyrsBrd::pause(){    
    cout << "\nPress enter to continue. ";
    //cin.ignore();
    cin.get();   
    cout<<endl;
}


/*****************************************************************/
// Shuffles int, char, string array BUT not a set<string> container
//// Shuffle https://www.educba.com/c-plus-plus-shuffle/
/*****************************************************************/
void TopPlyrsBrd::shuffleThis(){
    array<string,7> shuf{"Mon","Tue","Wed","Thur","Fri","Sat","Sun"};
    cout << "Before shuffling:\n";
    for (auto& x: shuf) {cout<<x<<" ";} cout<<endl;
    unsigned num = chrono::system_clock::now().time_since_epoch().count();
    shuffle (shuf.begin(), shuf.end(), default_random_engine(num));
    cout << "After shuffling:\n";
    for (auto& x: shuf){cout<<x<<" ";} cout<<endl<<endl;
}


/*****************************************************************/
// 			Fills container with sequential numbers [0,deqIntSz]
/*****************************************************************/
 void TopPlyrsBrd::setDeqWthSize(){
    list<int> nums;
    for(int i=0; i<deqIntSz;i++){ nums.push_back(i); }
    //for(auto &d : nums){ cout<<d<<endl; } cout<<endl;
    deque<int> deq(nums.begin(), nums.end());
    for(auto &d : deq){cout<<d<<endl;}
 }
 
 
 /*****************************************************************/
 //
 /*****************************************************************/
 void TopPlyrsBrd::shuffleThis(deque<int> &deq){
    //std::deque<int> str = { 1, 27, 38, 42, 50, 69, 72, 87, 99 };
    //std::vector<int> str = { 1, 27, 38, 42, 50, 69, 72, 87, 99 };
    //string str="1234567";
    std::shuffle(deq.begin(), deq.end(), std::default_random_engine(std::random_device{}()));
    //cout<<"After shuffle:\n";for(auto &i : deq){cout<<i<<" ";} cout<<endl;
 }
 void TopPlyrsBrd::shuffleThis(deque<float> &deq){
    //std::deque<int> str = { 1, 27, 38, 42, 50, 69, 72, 87, 99 };
    //std::vector<int> str = { 1, 27, 38, 42, 50, 69, 72, 87, 99 };
    //string str="1234567";
    std::shuffle(deq.begin(), deq.end(), std::default_random_engine(std::random_device{}()));
    //cout<<"After shuffle:\n";for(auto &i : deq){cout<<i<<" ";} cout<<endl;
 }
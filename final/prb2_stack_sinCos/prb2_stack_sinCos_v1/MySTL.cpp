#include "MySTL.h"
#include <bits/stdc++.h> 
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
#include <unordered_set>//min
#include <sstream> // stringstream
#include <list>
using namespace std;  //STD Name-space where Library is compiled

//sin cos
float MySTL::h(float angR){
    float tol=1e-6;
    if(angR>-tol&&angR<tol){
        countSin1++;
        return angR+angR*angR*angR/6;
    }
    countSin2++;
    return 2*h(angR/2)*g(angR/2);
}
//sin cos
float MySTL::g(float angR){
    float tol=1e-6;
    if(angR>-tol&&angR<tol){
        countCos1++;
        return 1+angR*angR/2;
    }
    countCos2++;
    float b=h(angR/2);
    return 1+2*b*b;
}

//**********************************************************
//                  Default Constructor
//**********************************************************
MySTL::MySTL(){
   
    
    countSin1=0;//f() 1st return statement
    countSin2=0;//f() 2nd return statement
    countCos1=0;//g() 1st return statement
    countCos2=0;//g() 2nd return statement
    
    // Stack
    //cout<<"\n\nPush List into Stack.\n";
    list<float>xIn{1.0, .9,.8,.7,.6,.5,.4,.3,.2,.1,0,-.1, -.2,-.3,-.4,-.5,-.6,-.7,-.8,-.9,-1.0};     
    //cout<<"\nList:\n"; prntListFlt(xIn);   
    setStack(xIn);
      
    start();
}


/*****************************************************************/
//				Mimics Battleships startGame function
/*****************************************************************/
void MySTL::start(){          
       
    //cout<<"Stack (Last In First Out).\n";
    //prntStckFIFO();
    
    // Testing out recursive trig functions
    float angDeg=45;
    float angRad=0;
    int n=1;
    std::stack<float> temp;
    temp=stack;
    
    cout<<setw(3)<<"Cnt"   <<setw(4)<<" "
        <<setw(7)<<"Radian "<<setw(4)<<" "
        <<setw(5)<<"sinh " <<setw(4)<<" "
        <<setw(5)<<"our h "<<setw(3)<<" "
        <<setw(5)<<"cosh " <<setw(4)<<" "
        <<setw(5)<<"our g "<<setw(4)<<" "
        <<setw(5)<<"h count "<<setw(2)<<" "  
        <<setw(5)<<"g count "<<setw(4)<<" " 
            <<endl<<right<<fixed<<setprecision(4);
    
    while(temp.empty()==false){
        angDeg = temp.top();        
        angRad=angDeg*atan(1)/45;// Convert degree radians
        
        cout<<setw(2)<<n++<<"    ";
        cout<<setw(7)<<angDeg<<setw(3)<<"  "
        <<setw(7)<<sinh(angRad)<<setw(3)<<" "
        <<setw(7)<<h(angRad)<<"  "
        <<setw(7)<<cosh(angRad)<<"  "
        <<setw(7)<<g(angRad)<<"  "
        <<setw(7)<<countSin1+countSin2<<"   " // total count for h() being called
        <<setw(7)<<countCos1+countCos2<<"  " // total count for g() being called
        <<endl;        
        temp.pop();
    }    
    cout<<endl;  
    cout<<"h1 count:  "<<countSin1<<endl // count for 1st return in h()
        <<"h2 count:  "<<countSin2<<endl // count for 2nd return in h()
        <<"\tTotal h() :  "<<countSin1+countSin2<<endl    
        <<"g1 count:  "<<countCos1<<endl // count for 1st return in g()
        <<"g2 count:  "<<countCos2<<endl // count for 2nd return in g()
        <<"\tTotal g() :  "<<countCos1+countCos2<<endl ;
       
}


/*****************************************************************/
// 		Initialize stack with list 
// Loops through list and pushes a name to the stack
/*****************************************************************/
void MySTL::setStack(list<float> &list){ 
    std::list<float>::iterator it = list.begin();
    for(int n=0;n<list.size();n++, it++){ stack.push(*it);}
    //cout<<"Stack FIFO\n";prntStckFIFO(stack);
   //cout<<"Stack Reverse\n";prntStckRev(stack);
}

/*****************************************************************/
// Can i const stack so it doesn't delete the original stack?
// Print a stack using a temp stack, so it doesn't delete the stack forever
/*****************************************************************/
void MySTL::prntStckFIFO(){//stack<string> &stack){
    int n=1;
    std::stack<float> temp;
    temp=stack;
    while(temp.empty()==false){
        float t = temp.top();
        cout<<setw(2)<<n++<<".  "<<setw(4)<<t<<"\n";
        temp.pop();
    }    
    cout<<endl<<endl;
}

/*****************************************************************/
// 					Print a list float
/*****************************************************************/
void MySTL::prntListFlt(list<float> &list){
    int i=1;
    std::list<float>::iterator litr = list.begin();
    for(litr=list.begin(); litr!=list.end(); litr++,i++) {
        cout<<i<<". "<<*litr<<"\n";
    }cout<<endl<<endl;
}


/*****************************************************************/
// Set map(set,list)
// function controls the sort and search section
/*****************************************************************/
void MySTL::getTopPlyrs(){ 
    
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
    string sName="";
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
void MySTL::setTopPlyrs(){        
 
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
        // Inserts pairs maps container alphabetically order
        topPlyrs.insert( 
        pair<string, float>(*itr, *litr)); 
        //cout<<"j="<<j<<" ("<<*itr<<", "<<scores<<") "<<endl;
        j++; 
    }    
}


/*****************************************************************/
// 	Set player 1's name and convert to uppercase letters
/*****************************************************************/
string MySTL::askName(){ 
    string str="Danielle";
    cout << "\nPlayer 1: Enter your name\n";
    cin>>str; //change to ostream_iterator
    //cin.ignore();
    cout<<str<<" "; //cout << endl; 
    return set2Upper(str);  //convert user input into capital letters
}


/*****************************************************************/
// Picks a random number [0,fnames.size()-1], moves iterator
/*****************************************************************/
string MySTL::getMin(){        
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
// 				Use to show concepts
// Initialize a list with an array, then initialized set2 with set1
// Future projects: you can just return p2Names. I wanted to different ways to initialize a set.
/*****************************************************************/
void MySTL::setSet(){
    
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
//			Set queue with concantenated strings
/*****************************************************************/
void MySTL::setShips(){
    //string strAry[nShips];
    int i=0;
    deque<string>::iterator it=ships.begin();  
    for(i=0;i<nShips;i++,it++){          
        int num = i+1;
        stringstream ss;  // convert int to string
        ss << num;
        string str2;
        ss >> str2;  // save converted int to a string variable
        string str1 = "ship"+str2;
        //strAry[i] = str1; //save concatenated string to array
        it = ships.insert(it,str1);
    }       
//    // Initialize deque with ships
//    it=ships.begin(); 
//    for(i=0;i<nShips;i++, it++){  
//        it = ships.insert(it,strAry[i]);
//    }
}


/*****************************************************************/
// 		Print deque string forward
//https://www.techiedelight.com/iterate-deque-forward-backward-cpp/
/*****************************************************************/
void MySTL::prntDeq(deque<string> &deq){
    copy(deq.begin(), deq.end(),
        ostream_iterator<string>(cout,"\n"));
    cout<<endl; 
}


/*****************************************************************/
// 				Print deque string Reverse
//https://www.techiedelight.com/iterate-deque-forward-backward-cpp/
/*****************************************************************/
void MySTL::prntDeqRev(deque<string> &deq){
    copy(deq.rbegin(), deq.rend(),
        ostream_iterator<string>(cout,"\n"));
    cout<<endl; 
}




/*****************************************************************/
// 		Print a list string
/*****************************************************************/
void MySTL::prntListStr(list<string> &list){
    int i=1;
    std::list<string>::iterator itr = list.begin();
    for(itr=list.begin(); itr!=list.end(); itr++,i++) {
        cout<<i<<". "<<*itr<<"\n";
    }cout<<endl;
}


/*****************************************************************/
// Print unordered map (key,value) pairs of topPlyrs & high scores
/*****************************************************************/
void MySTL::prntMap(map<string, float> &map){
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
void MySTL::prntQue(queue<string> &que){
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
//void MySTL::prntStckRev(){//stack<string> &stack){
//    int n=1;
//    std::stack<float> temp;
//    //temp=stack;
//    while(stack.empty()==false){
//        temp.push(stack.top());
//        stack.pop();
//    }  
//    while(temp.empty()==false){        
//        float t = temp.top();       
//        cout<<n++<<". "<<t<<"\n";
//        temp.pop(); 
//        stack.push(t);// To restore contents of the original stack.
//    }    
//}

/*****************************************************************/
// 				Prints names set container
/*****************************************************************/
void MySTL::prntSetStr(unordered_set<string> &set){
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
string MySTL::set2Upper(string str){ 
    transform(str.begin(), str.end(), str.begin(), ::toupper); 
    return str;
}


/*****************************************************************/
// 			pause screen before game starts
/*****************************************************************/
void MySTL::pause(){    
    cout << "\nPress enter to continue. ";
    //cin.ignore();
    cin.get();   
    cout<<endl;
}


/*****************************************************************/
// Shuffles int, char, string array BUT not a set<string> container
// Shuffle https://www.educba.com/c-plus-plus-shuffle/
/*****************************************************************/
void MySTL::shuffleThis(){
    array<string,7> shuf{"Mon","Tue","Wed","Thur","Fri","Sat","Sun"};
    cout << "Before shuffling:\n";
    for (auto& x: shuf) {cout<<x<<" ";} cout<<endl;
    unsigned num = chrono::system_clock::now().time_since_epoch().count();
    shuffle (shuf.begin(), shuf.end(), default_random_engine(num));
    cout << "After shuffling:\n";
    for (auto& x: shuf){cout<<x<<" ";} cout<<endl<<endl;
}


/*****************************************************************/
// Fills container with sequential numbers [0,deqSize]
/*****************************************************************/
 void MySTL::setDeqWthSize(){
    list<int> nums;
    for(int i=0; i<deqSize;i++){ nums.push_back(i); }
    //for(auto &d : nums){ cout<<d<<endl; } cout<<endl;
    deque<int> deq(nums.begin(), nums.end());
    for(auto &d : deq){cout<<d<<endl;}
 }
 
 
 /*****************************************************************/
 //
 /*****************************************************************/
 void MySTL::shuffleThis(deque<int> &deq){
    //std::deque<int> str = { 1, 27, 38, 42, 50, 69, 72, 87, 99 };
    //std::vector<int> str = { 1, 27, 38, 42, 50, 69, 72, 87, 99 };
    //string str="1234567";
    std::shuffle(deq.begin(), deq.end(), std::default_random_engine(std::random_device{}()));
    //cout<<"After shuffle:\n";for(auto &i : deq){cout<<i<<" ";} cout<<endl;
 }
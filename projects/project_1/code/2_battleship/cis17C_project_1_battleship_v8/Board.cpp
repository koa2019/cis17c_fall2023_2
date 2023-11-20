#include "Board.h"
// System Libraries: 
#include <bits/stdc++.h> 
#include <algorithm>
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cstdlib>  // rand()
#include <ctime>    // time library for rand()
#include <cstring>  // char [] library
#include <string>   // length() library
#include <cctype>   // toupper()
using namespace std; 

//**************************************************************
//              Default constructor
//**************************************************************
Board::Board() {
    nShips=3;
    size = 20;
    board = new char[size];
    indx = new int[size];

    //Initialize both arrays 
    for(int shuffle=0;shuffle<2;shuffle++){ //randomized values 2 times
        for (int i = 0; i < size; i++) {            
            board[i] = rand()%26+65; // rand() uppercase letters from alphabet            
            indx[i] = i;
        }
    }
    //sets board with ships or blanks
    setBoard();
    // Queue
    setShips(); 
    prntDeq(ships); 
}

//**************************************************************
//Constructor #2
//**************************************************************
Board::Board(int s) {

    size = (s<2 && s>100) ? 20 : s;
    board = new char[size];
    indx = new int[size];

    //Initialize both arrays 
    for (int i=0; i<size; i++) {        
        board[i]=rand()%26+96; // rand() lowercase letters from alphabet            
        indx[i] = i;
    }
    //sets board with ships or blanks
    setBoard();
}

//**************************************************************
//       copy constructor
//**************************************************************
Board::Board(const Board &obj1) {
    size=obj1.size;      
    board = new char[size];
    indx = new int[size];
    for(int x=0; x<size; x++){
       board[x] = obj1.board[x];
       indx[x] = obj1.indx[x];
   }
}

//**************************************************************
//         Destructor
//**************************************************************
Board::~Board() {
    if(getBrdSize()>0) {
        delete [] board;
        delete [] indx;
    }
    board=nullptr;
    indx=nullptr;
}

/*****************************************************************/
//		Set queue with concatenated strings
/*****************************************************************/
void Board::setShips(){
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

//**************************************************************
//  reinitialize board with ships or blanks that are stored in 
//  a static array 
//**************************************************************
void Board::setBoard(){
    //reinitialize both pointer arrays 
    for(int shuffle=0;shuffle<2;shuffle++){ //randomized values 2xs
        for (int i=0; i<size; i++) {
            board[i] = bChoice[rand()%SIZE17]; // fills with S=ship or B=blank
            indx[i] = i;
        }
    }
}

//**************************************************************
// Prints game board
//**************************************************************
void Board::printBoard() const {

    cout << "\t\tGame Board.  S==Ship.\n";
    for (int i = 0; i<getBrdSize(); i++) {
        cout<<setw(3)<<indx[i];
    }
    cout << endl;
    for (int i=0; i<getBrdSize(); i++) {
        cout<<setw(3)<<board[i];
        //if(i%10==(10-1)) cout<<endl;
    }
    cout << endl << endl;
}
/*****************************************************************/
//          Print Queue
/*****************************************************************/
void Board::prntQue(queue<string> &que){
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
// 		Print deque string forward
//https://www.techiedelight.com/iterate-deque-forward-backward-cpp/
/*****************************************************************/
void Board::prntDeq(deque<string> &deq){
    copy(deq.begin(), deq.end(),
        ostream_iterator<string>(cout,"\n"));
    cout<<endl; 
}


/*****************************************************************/
// 		Print deque string Reverse
//https://www.techiedelight.com/iterate-deque-forward-backward-cpp/
/*****************************************************************/
void Board::prntDeqRev(deque<string> &deq){
    copy(deq.rbegin(), deq.rend(),
        ostream_iterator<string>(cout,"\n"));
    cout<<endl; 
}
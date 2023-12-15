/* File:    main.cpp
 * Author:  Danielle F
 * Created: 09-28-2023 @ 10 PM
 * Purpose:  
*/

//System Libraries
#include <bits/stdc++.h> 
//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <iomanip>
//#include <cctype>
//#include <fstream>
//#include <climits> // char and int maximums
//#include <cfloat>  //float maximum
//#include <cmath>
#include <iterator>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void prntQue(queue<int> &que){
    queue<int> temp1;
    while(!que.empty()){
        temp1.push(que.front());
        que.pop();
    }
    while (temp1.empty() == false)
    {        
        int t1 = temp1.front();        
        cout<<t1<<" \n";
        temp1.pop(); 
        que.push(t1);   // To restore contents of the original stack.
    }    
}

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    cout<<left;
    //rand()%90+10;//2 digit numbers    
    //char ch = 65+(rand()%26); //A-Z[65,90]
    
    deque <int> line; 
    deque <string> bank;
    int time=60*3, 
        numBank=0,
        ttlCust=0,
        nClerks=0,
        clerk1Cnt=0,
        clerk2Cnt=0,
        clerk3Cnt=0;
    string cust="c";
    
    
    for(int sec=0; sec<=time;sec++){
        
        if(sec%15==0){
            ttlCust++;
            numBank++;
            if(sec==15 || sec==30 || sec==45){nClerks++;}          
            
            string n = to_string(numBank);
            cust += n;
            bank.push_back(cust);
            cust="c";
            
            //line.push(sec);
            //cout<<"size added "<<line.size()<<endl;
        }
                
        // Clerks helping customers
        if (sec!=0 && sec%60==0){
            clerk1Cnt++;
            numBank--;
            bank.pop_front();
//             cout<<"clerk 1 value popped b off "<<line.front()<<endl;
//            line.pop();
//           cout<<" value popped a off "<<line.front()<<endl; 
        }
        if (sec!=0 && sec%80==0){
            clerk3Cnt++;
            numBank--;
            bank.pop_front();
            cout<<"Hit clerk3! Sec="<<setw(3)<<sec<<endl; 
        }
        if (sec!=0 && sec%120==0){
            clerk2Cnt++;
            numBank--;
            bank.pop_front();
            cout<<"Hit clerk2! Sec="<<setw(3)<<sec<<endl; 
            //line.pop();
        }
        
        // Check when more or less clerks are needed to help with numBank

        if(numBank%5==0 && numBank>=5){ 
            clerk1Cnt++;
            nClerks++; // Total number of clerks
            cout<<endl<<setw(3)<<ttlCust<<" Sec="<<setw(3)<<sec<<"  clerks="<<setw(2)<<nClerks;
            cout<<" numBank="<<numBank<<"  HIT 5+!";
            cout<<" bank["<<bank.size()<<"]: "; for(auto &d : bank){cout<<d<<" ";} cout<<endl;
            numBank--;
            bank.pop_front();
            cout<<setw(3)<<ttlCust<<" Sec="<<setw(3)<<sec<<"  clerks="<<setw(2)<<nClerks;
            cout<<" numBank="<<numBank<<"  AFTER 5";
            cout<<" bank["<<bank.size()<<"]: "; for(auto &d : bank){cout<<d<<" ";} cout<<endl<<endl;
        }
//        if(numBank%5==0 && numBank>=10){
//            nClerks++;
//            cout<<"\tMod5. Adding clerk="<<nClerks<<endl;
//            numBank--;
//        }
        
        
        if(sec%10==0){ //(sec>=60 && sec%5==0){
            cout<<setw(3)<<ttlCust<<" Sec="<<setw(3)<<sec<<" nClerks="<<setw(2)<<nClerks;
            if(numBank%5==0 && numBank>=5){cout<<"\tnumBank="<<numBank<<" ";}
            else{cout<<" numBank="<<numBank<<"  ";}
            cout<<"bank["<<bank.size()<<"]: "; for(auto &d : bank){cout<<d<<" ";} cout<<endl;
        }
    }
    
    //Display the results
    return 0;
}



//******************************************************************************
//                  Function Implementations  
//******************************************************************************

//******************************************************************************
//              
//******************************************************************************
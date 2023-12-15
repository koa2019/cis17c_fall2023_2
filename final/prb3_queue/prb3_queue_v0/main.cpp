/* File:    main.cpp
 * Author:  Danielle F
 * Created: 09-28-2023 @ 10 PM
 * Purpose:  
*/

//System Libraries
#include <bits/stdc++.h> 
#include <iterator>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
class Bank {
public:
    deque <int> bank; 
    deque <int> line;
    bool isOk2AddClerk;
    int sec;
    int numBank;
    int ttlWaitTime;
    int ttlCust;
    int nClerks;
    int clerk1Cnt;
    int clerk2Cnt;
    int clerk3Cnt;    
    int crrntCust;
    //string cust="c";   
    Bank();
    void start();
    void addClerk();
    void setWaitTimt(int num=1);
    void prntWaitTime(int);
    void prntClerk(int num=1);
    void prnt(string str="beg");
    void prntLine();
    void prntBank();
};
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
Bank::Bank(){    
    isOk2AddClerk=false;
    bank.push_back(-66); // Not sure how else to intialize dueque in a class
    line.push_back(-66);
    bank.clear();
    line.clear();
    sec=0; 
    numBank=0;
    ttlWaitTime=0;
    ttlCust=0;
    nClerks=0;
    clerk1Cnt=0;
    clerk2Cnt=0;
    clerk3Cnt=0;
    crrntCust=1;
    //cout<<" line["<<line.size()<<"]: "; for(auto &d : line){cout<<d<<" ";} cout<<endl;
    start();    
}

void Bank::start(){
    
    int time=90;//170;//60*2; 
    cout<<left;
    
    
    for(sec=0; sec<=time;sec++){
        
        // One customer enters the bank every 15 seconds
        if(sec%15==0){
            ttlCust++;
            numBank++;
            
            // push a customer in bank and line 
            //string n = to_string(ttlCust);
            //cust += n;
            bank.push_back(ttlCust);
            line.push_back(ttlCust);
            //cust="c";
            
            isOk2AddClerk = (bank.size()%5==0 && bank.size()>=0) ? true: false;
            //prntLine();
            //prntBank();                    
            prnt();
            
            // Add clerk and take 1 customer out of line
            if(sec==60){
               nClerks=3;
               clerk1Cnt++;
               cout<<"     START Sec="<<setw(3)<<sec;
               cout<<"\n\t"; prntLine(); 
               cout<<"\t"; prntBank();
               cout<<"\t     nClerks="<<setw(2)<<nClerks<<"->\n";
               line.pop_front();  // Take 1 person out of line & begin their service.
               line.pop_front();  // Take 1 person out of line & begin their service.
               line.pop_front();  // Take 1 person out of line & begin their service. 
               cout<<"\t"; prntLine();
               cout<<"\t"; prntBank();
            }     
        }
                
        // Clerk #1 helps 1 customer every 60 seconds
        if (sec!=0 && sec%60==0){            
           prntClerk();
        }
        
        // Clerk #3 helps 1 customer every 80 seconds
        if (sec!=0 && sec%80==0){
            prntClerk(3); 
            //ttlWaitTime-=5;
        }
        
        // Clerk #2 helps 1 customer every 120 seconds
        if (sec!=0 && sec%120==0){
            prntClerk(2);
        }
        
        // Check when 5 or increments of 5 customers are in bank AND then add another clerk #1
        if(numBank%5==0 && numBank>=5 && isOk2AddClerk && line.size()>0){ 
            addClerk();  
        }

        if(sec%10==0){prnt("end");}
    }
}


void Bank::setWaitTimt(int num){
    crrntCust=line.front();
    int arrived=crrntCust*15;
    int waitTime=sec-arrived;
    ttlWaitTime+=waitTime;
    cout<<setw(5)<<" "<<"Clerk#"<<num<<" now serving: c"<<crrntCust<<endl
    <<setw(13)<<" "<<"Current: "<<setw(3)<<sec<<endl
    <<setw(13)<<" "<<"Arrived: "<<arrived<<endl
    <<setw(13)<<" "<<"Waited: "<<waitTime<<endl;    
}
void Bank::prntWaitTime(int num){  

}
void Bank::prntClerk(int num){    
    cout<<"     Clerk#"<<num<<" Sec="<<setw(3)<<sec<<endl;    
    cout<<setw(13)<<" "<<"c"<<bank.front()<<" leaves bank.\n";
    cout<<setw(13)<<" "<<"numBank="<<numBank<<"->";
    numBank--;  // Finished service. Customer leaves bank.
    cout<<numBank<<endl; 
    setWaitTimt(num);
    //prntWaitTime(num);    
    line.pop_front();  // Take 1 person out of line & begin their service.
    bank.pop_front();
    cout<<"\t"; prntLine();
    cout<<"\t"; prntBank();   
     
}

// Add a Clerk#1 type and Take 1 person out of line & begin their service.
void Bank::addClerk(){
    isOk2AddClerk=false;
    clerk1Cnt++;         //  Total number of clerk #1
    nClerks++;          // Total number of clerks
    cout<<"add c"<<setw(3)<<ttlCust<<" Sec="<<setw(3)<<sec
        <<"HIT "<<numBank<<"+ IN BANK!"<<endl;
    cout<<"\t"; prntLine();
    cout<<"\t"; prntBank();
    setWaitTimt(nClerks);
    //prntWaitTime(nClerks);
    line.pop_front();  
    cout<<setw(13)<<" "<<"nClerks++="<<setw(2)<<nClerks;            
    cout<<"->\n\t"; prntLine();
    cout<<"\t"; prntBank();
}

void Bank::prntLine(){
    cout<<"     line["<<line.size()<<"]: "; for(auto &d : line){cout<<"c"<<d<<" ";} cout<<endl;
}
void Bank::prntBank(){
    cout<<"     bank["<<bank.size()<<"]: "; for(auto &d : bank){cout<<"c"<<d<<" ";} cout<<endl;
}
void Bank::prnt(string str){   
    cout<<str<<" c"<<setw(3)<<ttlCust<<" Sec="<<setw(4)<<sec<<" nClerks="<<setw(2)<<nClerks;
    if(numBank%5==0 && numBank>=5){
        cout<<" numBank="<<numBank<<"!!!->\n";
        cout<<"\t"; prntLine();
        cout<<"\t"; prntBank();
    }
    else{cout<<" numBank="<<numBank<<endl;}
}

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers    
    //char ch = 65+(rand()%26); //A-Z[65,90]
    Bank day;
        
    //Display the results
    return 0;
}



//******************************************************************************
//                  Function Implementations  
//******************************************************************************

//******************************************************************************
//              
//******************************************************************************
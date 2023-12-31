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
//#include <algorithm>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers    
    //char ch = 65+(rand()%26); //A-Z[65,90]
    
    cout<<left;
    queue <int> line; 
    int time=60*3, 
        numBank=0,
        ttlCust=0,
        nClerks=0,
        clerk1Cnt=0,
        clerk2Cnt=0,
        clerk3Cnt=0;
    
    
    for(int sec=0; sec<=time;sec++){
        
        if(sec%15==0){
            ttlCust++;
            numBank++;
            if(sec==15 || sec==30 || sec==45){nClerks++;}
            // cout<<" sec is "<<sec<<endl;            
            //line.push(sec);
//            line.push(sec);
//            line.push(sec);
//            line.push(sec);
            //cout<<"front "<<line.front()<<endl;
            //cout<<"size added "<<line.size()<<endl;
        }
                
        // Clerks helping customers
        if (sec!=0 && sec%60==0){
            clerk1Cnt++;
            numBank--;
//             cout<<"clerk 1 value popped b off "<<line.front()<<endl;
//            line.pop();
//           cout<<" value popped a off "<<line.front()<<endl; 
        }
        if (sec!=0 && sec%80==0){
            clerk3Cnt++;
            numBank--;
//             cout<<"clerk 3 value popped b off "<<line.front()<<endl;
//            line.pop();
//           cout<<" value popped a off "<<line.front();
        }
        if (sec!=0 && sec%120==0){
            clerk2Cnt++;
            numBank--;
//            cout<<"clerk 2 value popped b off "<<line.front()<<endl; 
//            line.pop();
//       cout<<" value popped a off "<<line.front()<<endl;
        }
        
        // Check when more or less clerks are needed to help with numBank

        if(numBank%5==0 && numBank>=5){ 
            clerk1Cnt++;
            nClerks++; // Total number of clerks
            numBank--;
            cout<<setw(3)<<ttlCust<<" Sec="<<setw(3)<<sec<<"  clerks="<<setw(2)<<nClerks;
            cout<<" numBank="<<numBank<<" HIT 5+ IN BANK!\n";
        }
//        if(numBank%5==0 && numBank>=10){
//            nClerks++;
//            cout<<"\tMod5. Adding clerk="<<nClerks<<endl;
//            numBank--;
//        }
        
        
        if(sec%10==0){ //(sec>=60 && sec%5==0){
            cout<<setw(3)<<ttlCust<<" Sec="<<setw(3)<<sec<<" nClerks="<<setw(2)<<nClerks;
            if(numBank%5==0 && numBank>=5){cout<<"\tnumBank="<<numBank<<endl;}
            else{cout<<" numBank="<<numBank<<endl;}
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
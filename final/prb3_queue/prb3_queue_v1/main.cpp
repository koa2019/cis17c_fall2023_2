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
    
    
    queue <int> line; 
    for(int i=0; i<300;i++){
        
        if(i % 15  == 0){
           // cout<<" i is "<<i<<endl;

            line.push(i);
//            line.push(i);
//            line.push(i);
//            line.push(i);
            //cout<<"front "<<line.front()<<endl;
             //cout<<"size added "<<line.size()<<endl;


        }
        
//        if (i==15 || (i>15 && i-15 % 60 == 0) ){
//             cout<<"clerk 1 value popped b off "<<line.front()<<endl;
//            line.pop();
//           cout<<" value popped a off "<<line.front()<<endl; 
//        }
//        if (i==45 || (i>45 && i % 80 == 0 )){
//             cout<<"clerk 3 value popped b off "<<line.front()<<endl;
//            line.pop();
//           cout<<" value popped a off "<<line.front();
//        }
//        if (i==30 || (i>30 && i % 120 == 0) ){
//            cout<<"clerk 2 value popped b off "<<line.front()<<endl; 
//            line.pop();
//       cout<<" value popped a off "<<line.front()<<endl;
//        }
        
        cout<<" time "<<i<<" "<<"size after "<<line.size()<<endl;
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
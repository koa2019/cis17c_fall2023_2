/* File:    main.cpp
 * Author:  Danielle F
 * Created: 09-28-2023 @ 10 PM
 * Purpose:  
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
    //vector arr(2,2,1,2,1);
    //sort(arr.begin(),arr.end());
    
    //vector<string> ss={"abbcccaa"};
    //cout<<ss.size()<<endl;
    string s ="abbcccaa";    
    int sum=0,count=0;
    cout<<"s.length="<<s.length()<<endl;
  
    for(int i=0; i<s.length(); i++){
        for(int j=i; j<=i; j++){
            
        cout<<s[i]<<"=="<<s[j]<<endl;
        if(s[i]==s[i+1]){            
            sum++;
            cout<<"\tsum = "<<sum<<endl;
        }
        }
    }

    return 0;
}

/**********  Function Implementations  **************/

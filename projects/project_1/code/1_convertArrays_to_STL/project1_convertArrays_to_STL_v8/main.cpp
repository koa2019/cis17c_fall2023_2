/* File:    main.cpp
 * Author:  Danielle 
 * Created: 11-14-23  3 PM
 * Purpose: project1_convertArrays_to_STL_v8
 *         
 * Note:   Converts arrays to STL containers before adding it
 *         to cis17C_Project_1_battleship_v6
 * 
 * version 8: 
    * Changed Game class to MySTL
    * Changed queue nShips to deque and used random access iterators to print it forward and backwards. 
    * Convert int *indx to a deque for MySTL class 
    * Filled a list with integers 0 to member variable: size and then shuffled indx in shuffleThis(deque<int>) 
    * Problem: Couldn’t get shuffle or random_shuffle to work with an unordered set. 
    * Declared MySTL and User destructors virtual
    * Completed Iterators off project checklist. 
    * Checklist is complete. 
    * Problem: Deleted excel and word desktop apps from my laptop
 * 
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
#include <sstream> // stringstream
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "MySTL.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
// Program execution begins here
int main(int argc, char** argv) {
    // set random number seed
    srand(static_cast<unsigned int>(time(0))); 
    
    MySTL mystl;
    //menu();  
    //concepts();
    //constructor();    
    return 0;
}

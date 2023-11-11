/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 12-07-2022 @ 6:36 PM
 * Purpose:  final_cis17a_prb1_randFreq
 *  
 * Program loops 100000 times and picks a random element from an array.
 * It keeps count of how many times each element was picked and prints
 * results in main();
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>  //setw()
#include <cstdlib>  //rand()
#include <ctime>    //rand()
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "Prb1Random.h"


int main(int argc, char** argv) {
    
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));    
    
    //Driver program to return a random sequence
    char n = 5;
    char rndseq[] = {0,1,2,3,4};//{19, 34, 57, 79, 126};
    int ntimes = 10;
    
    Prb1Random a(n, rndseq);
    
    for (int i = 1; i <= ntimes; i++) {
        a.randFromSet();     
    }   
    
    int *x = a.getFreq();   //set pointer to *freq pointer in Prb1Random class
    
    char *y = a.getSet();   //set pointer to *set pointer in Prb1Random class
    
    //Print results
    cout << "\n\nProblem 12\nRandom Sequence's Frequency\n";
    for (int i = 0; i < n; i++) {
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
    }
    
    cout << "The total number of random numbers is " << a.getNumRand() << endl;

    return 0;
}
//User Libraries
#include "Prb1Random.h"
//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>  //setw()
#include <cstdlib>  //rand()
#include <ctime>    //rand()
using namespace std; //STD Name-space where Library is compiled


//*************************************
//         Default constructor
//*************************************
Prb1Random::Prb1Random(const char size, const char *rndseq){
    
    numRand = 0;
    
    nset = size;
    
    set = new char[nset];   // Allocate memory for rand # array
    
    //Copy randSeq[] values from main to pointer in this class
    for(int i=0;i<size;i++){
        set[i]=rndseq[i];
    }
    
    freq = new int[nset];   // Allocate memory for freq array
    
    // initialize elements to zero
    for(int i=0;i<size;i++){
        freq[i]=i;
    }   
}


//*************************************
// Returns random number from the set
//*************************************
char Prb1Random::randFromSet(){
   
    numRand++;
   
    int randm = rand()%nset;  //Random # between [0,4]
    
    for(int i=0;i<nset;i++){
        if(set[randm]== set[i]){
            freq[i]++;
        }
    }
    return set[randm];
}

//*************************************
// Returns random number from the set
//*************************************
//char Prb1Random::randFromSet(){
//   
//    numRand++;
//   
//    int randm = rand()%nset;  //Random # between [0,4]
//    
//    for(int i=0;i<nset;i++){
//        if(set[randm]== set[i]){
//            freq[i]++;
//        }
//    }
//    return set[randm];
//}
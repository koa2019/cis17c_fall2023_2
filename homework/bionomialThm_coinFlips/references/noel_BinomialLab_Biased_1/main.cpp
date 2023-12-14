
/* 
 * File:   main.cpp
 * Author: Noel Perez
 *
 * Created on November 7, 2023, 6:30 PM
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


int main(int argc, char** argv) {
    
    
    srand(static_cast<unsigned>(time(0)));

    int simulations = 10000; // number of simulations
    float bias = 0.60;    // Bias  
    int numTails = 1;
    int numHeads = 3;           
    float probability;

    int outcomes = 0;  

    for (int i = 0; i < simulations; i++) {
        
        int tailsCount = 0;
        int headsCount = 0;

        // Simulate flipping 4 coins with bias
        for (int j = 0; j < 4; j++) {
            
            float randomValue = float(rand()) / (RAND_MAX + 1.0);; // random value 0 and 1
            
            if (randomValue < bias) {
                headsCount++;
            } else {
                tailsCount++;
            }
        }

        // Check 1 tail and 3 heads
        if (tailsCount == numTails && headsCount == numHeads) {
            outcomes++;
        }
    }

    probability = static_cast<float>(outcomes)/simulations;

    // Output
    cout << "Probability: " << probability * 100 << "%" <<endl;



    return 0;
}



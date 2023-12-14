/* 
 * File:   main.cpp
 * Author: Noel Perez
 *
 * Created on November 7, 2023, 5:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;


int main(int argc, char** argv) {
    
      srand(static_cast<unsigned>(time(0)));

    int simulations = 10000; // number of simulations
    
    int h=0 , t = 0;
    

    for (int i = 0; i < simulations; i++) {
        
        for(int j = 0; j < 4; j++){
            
          //  simulate a coin flip
        int coin = rand() % 2;
        
          
        if (coin == 0) {
            h++;
            
        } else {
            t++;
           
        }
        
        }
      
    }

    // Output
    cout<<((1.0)*h/(simulations*4))<<endl;
    cout<<((1.0)*t/(simulations*4))<<endl;
    
    return 0;
}


/* 
 * File:   Prb1Random.h
 * Author: DanYell
 *
 * Created on December 8, 2022, 6:25 PM
 */

#ifndef PRB1RANDOM_H
#define PRB1RANDOM_H
using namespace std; //STD Name-space where Library is compiled


class Prb1Random {
private:
    char *set; //The set of numbers to draw random numbers from
    char nset; //The number of variables in the sequence
    int *freq; //Frequency of all the random numbers returned
    int numRand; //The total number of times the random number
                 //function is called
public:
    Prb1Random(const char, const char *); //Default Constructor
    ~Prb1Random(){ //Destructor
        delete [] set;
        delete [] freq;
    }
    char randFromSet(); //Returns a random number from the set
    int *getFreq() const { return freq;} //Returns the frequency histogram
    char *getSet() const{ return set;}  //Returns the set used
    int getNumRand() const{ return numRand;} //Gets the number of times 
                                             //randFromSet has been called
};


#endif /* PRB1RANDOM_H */


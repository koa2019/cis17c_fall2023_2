#include "Dice.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Dice::Dice() {
    //cout<<"Hit dice construction\n";
    value = 0;    
}

void Dice::roll() {
    value = rand() % 6 + 1;
}

int Dice::getValue() const {
    return value;
}
#include "Automata.h"
#include <iostream>

using namespace std;


int main() {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.coin(100);
    automata.choice("Espresso");
    
    return 0;
}
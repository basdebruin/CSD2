#include <iostream>
#include "les2.h"


// main for oscillator
int main() {

    Oscillator osc(2000);

    std::cout << "hoi\n" << osc.getFreq() << std::endl;

    return 0;

}
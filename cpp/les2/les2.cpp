#include <iostream>
#include "les2.h"

// oscillator implementation
Oscillator::Oscillator(float freq){
    std::cout << "\n -osc constructed\n";
    this->freq = freq;
}

Oscillator::~Oscillator() {
    std::cout << "\n -osc destructed\n";
}

void Oscillator::setFreq(float freq){
    std::cout << "\n -osc freq set\n";

    if (freq < 0 || freq > 22050) {
        std::cout << "-setFreq: ERROR, too big or too small\n";
        return;
    }
    this->freq = freq;
}

float Oscillator::getFreq(){
    std::cout << "\n -osc freq get\n";
    return freq;
}
#include "oscillator.h"

Oscillator::Oscillator(float freq, float amp){
    this->freq = freq;
    this->amp  = amp;

    phase = 0;
    sample = 0;

    std::cout << "- osc - constructed";
}

Oscillator::~Oscillator(){};

float Oscillator::getSample() {

}

float Oscillator::getFreq() {
    return freq;
}

void Oscillator::setFreq(float freq) {
    this->freq = freq;
}
#include "osc.h"

Osc::Osc() {
    std::cout << "- osc - constructed";
}

Osc::~Osc() {}

void Osc::setFreq(float freq) {
    this->freq = freq;
}
float Osc::getFreq() {
    return freq;
}

void Osc::setAmp(float amp) {
    this->amp = amp;
}
float Osc::getAmp() {
    return amp;
}

float Osc::getSample() {
    return sample;
}
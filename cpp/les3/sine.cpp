// inplement
#include "sine.h"

Sine::Sine (float freq) {

}

Sine::~Sine(){};


float Sine::getSample() {
    return sample;
}

void Sine::tick() {
    std::cout << "ticked" << std::endl;
}

void setFreq(float freq) {
    this->freq = freq;
}

float getFreq() {
    return freq;
}
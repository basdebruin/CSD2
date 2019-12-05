#include "banjo.h"

Banjo::Banjo(float freq) : Instrument(sound) {
    this->freq = freq;
    std::cout << "-- BANJO -- Constructed\n";
}

Banjo::~Banjo(){}

void Banjo::play() {
    std::cout << this->sound << " at " << this->freq << " Hz.\n";
}
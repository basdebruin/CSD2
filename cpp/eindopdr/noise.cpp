#include "noise.h"
#include <cstdlib> //for rand()

Noise::Noise() : Osc() {
    std::cout << "- Noise - constructed\n";
}
Noise::~Noise() {}

//  Generating the Noise:
void Noise::tick() {
    float r = (std::rand() % 1000) / 500 - 1;
    sample = r;
}
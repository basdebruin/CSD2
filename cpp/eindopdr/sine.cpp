#include "sine.h"

Sine::Sine() : Osc() {
    std::cout << "- sine - constructed\n";
}
Sine::~Sine() {}

//  Generating the sine:
void Sine::tick(double samplerate) {
    phase += freq / samplerate;
    sample = sin(phase * PI_2);
}
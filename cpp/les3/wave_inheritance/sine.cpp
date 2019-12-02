#include "sine.h"

Sine::Sine(float freq, float amp) : Oscillator(freq, amp) {
    std::cout << "- sine - costructed";
}

Sine::~Sine() {}


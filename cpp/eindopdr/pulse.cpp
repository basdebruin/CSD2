#include "pulse.h"

Pulse::Pulse() : Osc() {
    std::cout << "- Pulse - constructed\n";
}
Pulse::~Pulse() {}

//  Generating the sine:
void Pulse::tick(double samplerate) {
    phase += freq / samplerate;
    sample = pow(sin(phase * PI_2), 5);
}

void Pulse::setSaturation(float saturation) {
    if (saturation > 0 && saturation < 100) {
        this->saturation = saturation;
    } else {
        std::cout << "Error: Saturation should be between 0 and 100\n";
    }
}
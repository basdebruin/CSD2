#include "pulse.h"

Pulse::Pulse() : Osc() {
    std::cout << "- Pulse - constructed\n";
}
Pulse::~Pulse() {}

//  Generating the sine:
void Pulse::tick(double samplerate) {
    phase += freq / samplerate;
    // generate sample based on saturation exponent
    sample = pow(sin(phase * PI_2), saturation);
}

void Pulse::setSaturation(int saturation) {
    // filter saturation input
    if (saturation >= 0 && saturation <= 1000) {
        // make sure saturation in uneven
        this->saturation = saturation + (1 - (saturation % 2));
    } else {
        std::cout << "Error: Saturation should be between 0 and 1000\n";
    }
}
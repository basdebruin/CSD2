#include "fm.h"

FmOsc::FmOsc() : Osc() {
    std::cout << "- FmOsc - constructed\n";
}
FmOsc::~FmOsc() {}

//  Generating the osc:
void FmOsc::tick(double samplerate) {
    // tick phase
    phase += freq / samplerate;
    fmphase += freq * ratio / samplerate;
    // tick sample
    float fm = sin(fmphase * PI_2) * harm;
    sample = sin(phase * PI_2 + fm);
}


void FmOsc::setHarmonics(float harm) {
    this->harm = harm;
}
void FmOsc::setRatio(float ratio) {
    this->ratio = ratio;
}
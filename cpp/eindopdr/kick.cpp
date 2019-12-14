#include "kick.h"


Kick::Kick() {
    env.setLength(5000);
    osc.setFreq(0);
    std::cout << "- Kick - constructed\n";
}

Kick::~Kick() {}


void Kick::trigger() {
    env.trigger();
}

void Kick::tick(double samplerate) {
    // tick the envelope and oscillator, with the envelope controlling the frequency
    env.tick();
    osc.setFreq(env.getSample() * freq);
    osc.tick(samplerate);
    sample = osc.getSample();
}

float Kick::getSample() {
    return sample;
}
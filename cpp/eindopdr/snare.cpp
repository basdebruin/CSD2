#include "snare.h"


Snare::Snare() {
    env.setLength(2000);
    std::cout << "- Snare - constructed\n";
}

Snare::~Snare() {}


void Snare::trigger() {
    env.trigger();
}

void Snare::tick() {
    env.tick();
    noise.tick();
    sample = noise.getSample() * env.getSample();
}

float Snare::getSample() {
    return sample;
}
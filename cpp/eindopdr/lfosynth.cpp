#include "lfosynth.h"


LfoSynth::LfoSynth() {
    env.setLength(20000);
    osc.setFreq(freq);
    osc.setAmp(0.01);
    lfo.setFreq(lfospeed);
    std::cout << "- LfoSynth - constructed\n";
}
LfoSynth::LfoSynth(float freq, float lfospeed, float length) {
    this->freq = freq;
    this->lfospeed = lfospeed;
    this->length = length;
    env.setLength(length);
    osc.setFreq(freq);
    lfo.setFreq(lfospeed);
    std::cout << "- LfoSynth - constructed with arguments\n";
}

LfoSynth::~LfoSynth() {}


void LfoSynth::trigger() {
    env.trigger();
}

void LfoSynth::tick(double samplerate) {
    // tick the envelope and lfo, change saturation based on lfo, tick and sample pulse
    env.tick();
    lfo.tick(samplerate);
    osc.setSaturation(int(lfo.getSample() * 500 + 500));
    osc.tick(samplerate);
    sample = osc.getSample() * env.getSample();
}

float LfoSynth::getSample() {
    return sample;
}
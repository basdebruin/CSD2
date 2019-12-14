#include <iostream>
#pragma once

#include "osc.h"
#include "sine.h"
#include "pulse.h"
#include "envelope.h"


class LfoSynth {

public:
    LfoSynth();
    LfoSynth(float freq, float lfospeed, float length);
    ~LfoSynth();

    void trigger();

    void setFreq(float freq);
    float getFreq();

    void setLfoSpeed(float lfospeed);
    float getLfoSpeed();

    void tick(double samplerate);
    float getSample();

private:
    Pulse osc;
    Sine lfo;
    Envelope env;
    float freq = 300;
    float lfospeed = 1;
    int length = 10000;
    float sample = 0;

};
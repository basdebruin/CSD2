#include <iostream>

#define SR 44100
#define ONE_OVER_SR 0,00002267573696

#ifndef OSC_H
#define OSC_H

using namespace std;

class Oscillator {

public:
    Oscillator(float freq, float amp);
    ~Oscillator();

    void setFreq(float freq);

    float getFreq();

    float getSample();

    void tick();

protected:
    float amp;
    float freq;
    float phase;
    float sample;

};

#endif
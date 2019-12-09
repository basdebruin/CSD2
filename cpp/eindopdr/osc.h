#include <iostream>

#ifndef OSC_H
#define OSC_H


class Osc {

public:
    Osc();
    ~Osc();

    float getFreq();
    void setFreq(float freq);

    float getAmp();
    void setAmp(float amp);

    void tick();
    float getSample();

protected:
    float sample;
    float phase;
    float amp;
    float freq;

};


#endif
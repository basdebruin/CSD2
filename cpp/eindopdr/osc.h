#include <iostream>
#include "math.h"

#define PI_2 6.28318530717959

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
    float sample = 0;
    float phase = 0;
    float amp = 0.5;
    float freq = 440;

};


#endif
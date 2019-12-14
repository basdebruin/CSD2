#include <iostream>

#include "osc.h"
#include "noise.h"
#include "envelope.h"


class Snare {

public:
    Snare();
    ~Snare();

    void trigger();

    void tick();
    float getSample();

private:
    Noise noise;
    Envelope env;
    float sample;

};
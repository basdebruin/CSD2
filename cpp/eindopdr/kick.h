#include <iostream>
#pragma once

#include "osc.h"
#include "sine.h"
#include "envelope.h"


class Kick {

public:
    Kick();
    ~Kick();

    void trigger();

    void tick(double samplerate);
    float getSample();

private:
    Sine osc;
    Envelope env;
    float freq = 300;
    float sample = 0;

};
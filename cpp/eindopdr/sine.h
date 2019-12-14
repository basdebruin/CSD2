#include "osc.h"
#pragma once

class Sine : public Osc {

public:
    Sine();
    ~Sine();

    void tick(double samplerate);

};
#include "osc.h"
#pragma once

class Pulse : public Osc {

public:
    Pulse();
    ~Pulse();

    void tick(double samplerate);

    void setSaturation(int saturation);

private:
    int saturation = 5;

};
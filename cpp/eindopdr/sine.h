#include "osc.h"

class Sine : Osc {

public:
    Sine();
    ~Sine();

    void tick(double samplerate);

};
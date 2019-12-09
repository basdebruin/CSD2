#include "osc.h"

class Sine : public Osc {

public:
    Sine();
    ~Sine();

    void tick(double samplerate);

};
#include "instrument.h"

class Banjo : Instrument {

public:
    Banjo(float freq);
    ~Banjo();

private:
    float freq;

};
#include "osc.h"

class FmOsc : public Osc {

public:
    FmOsc();
    ~FmOsc();

    void setHarmonics(float harm);
    void setRatio(float ratio);

    void tick(double samplerate);

private:
    float fmphase = 0;
    float harm = 0.5;
    float ratio = 2;

};
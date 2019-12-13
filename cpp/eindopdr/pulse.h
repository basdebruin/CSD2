#include "osc.h"

class Pulse : public Osc {

public:
    Pulse();
    ~Pulse();

    void tick(double samplerate);

    void setSaturation(float saturation);

private:
    float saturation = 5;

};
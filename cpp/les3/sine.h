// sinewave
#include <iostream>
#define SR 44100

class Sine {
public:
    Sine(float sr, float freq);
    ~Sine();

    float getSample();
    void tick();

    void setFreq(float freq);
    float getFreq();

protected:
    float freq;
    float sample;
    float phase;
};
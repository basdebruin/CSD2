#pragma once
#include "circBuffer.h"

class Delay {
public:
    Delay(float delayTime, float samplerate);
    ~Delay();
    void process(float* inBuf, float* outBuf, int nframes);

    void setDelayTime(float delayTime);
    inline float getDelayTime() {return delayTime;};

private:
    CircBuffer buffer;
    float delayTime;
    uint delaySamples;
    float samplerate;
};
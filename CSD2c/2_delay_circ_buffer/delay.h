#pragma once
#include "circBuffer.h"

class Delay {
public:
    Delay(float delayTime, float samplerate, float feedback);
    ~Delay();
    void process(float* inBuf, float* outBuf, int nframes);

    void setDelayTime(float delayTime);
    inline float getDelayTime() {return delayTime;};

    inline void setFeedback(float feedback)  { this->feedback = feedback; };
    inline float getFeedback()               { return feedback; };

private:
    CircBuffer buffer;
    float delayTime;
    uint delaySamples;
    float samplerate;

    float feedback;
};
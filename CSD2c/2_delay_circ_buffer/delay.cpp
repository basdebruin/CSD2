#include "delay.h"
#include <iostream>

Delay::Delay(float delayTime, float maxDelayTime, float samplerate, float feedback) {
    std::cout << "-------- Delay Constructed ----------\n";
    
    this->samplerate = samplerate;
    this->feedback = feedback;

    buffer.resetSize(maxDelayTime * samplerate);
    setDelayTime(delayTime);

    // logging
    buffer.logAllSettings();
}
Delay::~Delay() {
    std::cout << "-------- Delay Destructed ----------\n";
}


void Delay::process(float * inBuf, float * outBuf, int nframes) {
    // loop through frames
    for (unsigned int i = 0; i < nframes; i++) {
        buffer.write(inBuf[i]);
        buffer.incrWriteH();

        outBuf[i] = buffer.read() * 0.5;
        buffer.incrReadH();
    }
}


void Delay::setDelayTime(float delayTime) {
    this->delayTime = delayTime;
    delaySamples = samplerate * delayTime;
    buffer.setDistanceRW(delaySamples);
    std::cout << "delay::delayTime set to: " << delayTime << std::endl;
}
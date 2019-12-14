#include "envelope.h"

// two constructors, one with length input
Envelope::Envelope() {
    std::cout << "- Envelope - constructed\n";
}
Envelope::Envelope(int length) {
    this->length = length;
    std::cout << "- Envelope - constructed with length\n";
}

Envelope::~Envelope() {}

void Envelope::setLength(int length) {
    if (length > 0) {
        this->length = length;
    } else {
        std::cout << "Error: length needs to be higher than 0";
    }
}
int Envelope::getLength() {
    return length;
}

void Envelope::trigger() {
    time = 0;
}

void Envelope::tick() {
    if (time < length) {
        sample = 1 - (time / length);
        time++;
    }
}

float Envelope::getSample() {
    return sample;
}
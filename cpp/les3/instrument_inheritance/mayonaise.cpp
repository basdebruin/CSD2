#include "mayonaise.h"


Mayonaise::Mayonaise() : Instrument(sound) {
    std::cout << "-- MAYO -- Constructed\n";
    this->sound = "Mayo is a real instrument";
}

Mayonaise::~Mayonaise(){};
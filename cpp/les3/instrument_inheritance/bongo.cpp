#include "bongo.h"


Bongo::Bongo() : Instrument(sound) {
    std::cout << "-- BONGO -- Constructed\n";
    this->sound = "Bongo sound";
}

Bongo::~Bongo(){};
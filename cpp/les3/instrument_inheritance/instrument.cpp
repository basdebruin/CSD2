#include "instrument.h"

Instrument::Instrument(std::string sound) {
    this->sound = sound;
}
void Instrument::play() {
    std::cout << sound << "\n";
}
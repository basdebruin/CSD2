#include "instrument.h"

Instrument::Instrument(string inputSound) {
    sound = inputSound;
}
void Instrument::play() {
    std::cout << sound << std::endl;
}
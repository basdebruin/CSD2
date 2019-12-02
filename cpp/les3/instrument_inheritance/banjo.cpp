#include "banjo.h"

Banjo::Banjo(float freq) : Instrument("banjo says pling at " + std::to_string(freq) + " Hz") {
}

Banjo::~Banjo(){}
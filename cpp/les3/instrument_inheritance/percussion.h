#include "instrument.h"

class Percussion : Instrument {

public:
    Percussion(std::string name);
    ~Percussion();

private:
    std::string name;

};
#include "instrument.h"

class Banjo : public Instrument {

public:
    Banjo(float freq);
    ~Banjo();

    void play();

protected:
    float freq;
    std::string sound = "The banjo says pling";

};
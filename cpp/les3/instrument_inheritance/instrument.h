#include <iostream>
#include <string>

#ifndef INST_H
#define INST_H

class Instrument {

public:
    Instrument(std::string inputSound);

    void play();

protected:
    std::string sound;

};

#endif
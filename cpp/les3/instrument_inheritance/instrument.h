#include <iostream>
#include <string>

using namespace std;

#ifndef INST_H
#define INST_H

class Instrument {

public:
    Instrument(string inputSound);

    void play();

protected:
    string sound;

};

#endif
#include <iostream>
#include <string>

using namespace std;

class Instrument {

public:
    Instrument(string inputSound);

    void play();

private:
    string sound;

};
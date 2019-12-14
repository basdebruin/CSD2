#include <iostream>

class Envelope {

public:
    Envelope();
    Envelope(int length);
    ~Envelope();

    void setLength(int length);
    int getLength();

    void trigger();

    void tick();
    float getSample();

protected:
    float sample = 0;
    float time = 0;
    int length = 1000; // in samples

};
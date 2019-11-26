
// oscillator blueprint
class Oscillator {

public:
    Oscillator(float freq);
    ~Oscillator(); // DESTRUCTOR

    void setFreq(float freq);
    float getFreq();

private:
    float freq;

};
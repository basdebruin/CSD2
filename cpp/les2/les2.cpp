#include <iostream>


class Oscillator {

public:
    Oscillator(float freq);

    void setFreq(float freq);
    float getFreq();

private:
    float freq;

};

// oscillator functions
Oscillator::Oscillator(float freq){
    std::cout << "\n -osc constructed\n";
    this->freq = freq;
}
void Oscillator::setFreq(float freq){
    std::cout << "\n -osc freq set\n";

    if (freq < 0 || freq > 22050) {
        std::cout << "-setFreq: ERROR, too big or too small\n";
        return;
    }
    this->freq = freq;
}
float Oscillator::getFreq(){
    std::cout << "\n -osc freq get\n";
    return freq;
}



int main() {

    Oscillator osc(2000);
    osc.setFreq(30000);

    std::cout << "hoi\n" << osc.getFreq() << std::endl;

    return 0;

}
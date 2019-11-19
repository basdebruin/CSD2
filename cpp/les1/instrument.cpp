#include <iostream>
#include <string>

using namespace std;

class Instrument {

public:
    Instrument(string inputSound) { // constructor
        sound = inputSound; // default
    }

    void play() {
        cout << sound << endl;
    }

private:
    string sound;

};


int main() {

    Instrument banjo("pling");
    banjo.play();
    Instrument trommel("boem");
    trommel.play();

}


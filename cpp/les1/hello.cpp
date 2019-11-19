#include <iostream>

/*
    class Hello

    constructor
    hello()
*/

class Hello {

public:
    Hello() { // constructor
        year = 1969; // default
    }

    void setYear(int newYear) {
        this->year = newYear;
    }

    void hi() {
        std::cout << "Hello from " << year << "." << std::endl;
    }

private:
    int year;

}; // !! bij class een semicolon erachter


int main() {

    Hello h;
    h.setYear(1980);
    h.hi();

    return 0;

}


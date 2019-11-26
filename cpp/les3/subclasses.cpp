// inheritance
// les 3
#include <string>

// ---- in Pet.h
// anders wordt hij meerdere keren gedefined

#ifndef _PET_H_
#define _PET_H_
// of: #pragma once

// ----
class Pet {
public:
    Pet(std::string name);

    void sleep();

protected: // wel zichtbaar voor subclasses
    std::string name;
};

#endif

// subclass:
class Cat : public Pet {
    Cat(std::string name);
};

// je moet de parentclass wel aanroepen bij sub constructor
Cat::Cat(std::string name) : Pet(name) {

}
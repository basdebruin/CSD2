#include "instrument.h"
#include "banjo.h"
#include "mayonaise.h"

int main() {

    Banjo b(200);
    b.play();

    Mayonaise m;
    m.play();

    return 0;

}
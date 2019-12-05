#include "instrument.h"
#include "banjo.h"
#include "mayonaise.h"

int main() {

    Banjo b(200);
    b.play();
    Banjo b2(500);
    b2.play();

    Mayonaise m;
    m.play();

    return 0;

}
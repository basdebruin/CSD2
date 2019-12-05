#include "instrument.h"
#include "banjo.h"
#include "mayonaise.h"
#include "bongo.h"

int main() {

    Banjo b(200);
    b.play();

    Mayonaise m;
    m.play();

    Bongo bongo;
    bongo.play();

    return 0;

}
#include "E:\Progs\CodeBlocks\lab3\histogram.h"
#include <iostream>
#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1,2,3}, min, max);
    assert(min == 1);
    assert(max == 3);
    find_minmax({}, min, max);
}

int
main() {
    test_positive();
}

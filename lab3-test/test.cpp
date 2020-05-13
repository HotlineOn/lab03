#include "../histogram.h"
#include "../svg.h"
#include "../avg_bin+scaling.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <windows.h>
void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1,2,3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1,-2,-3},min,max);
    assert(min == -3);
    assert(max == -1);
}
void
test_empty()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
}

void
test_equal()
{
    double min = 0;
    double max = 0;
    find_minmax({3,3,3},min,max);
    assert(min == 3);
    assert(max == 3);
}

void
test_double()
{
    double min = 0;
    double max = 0;
    find_minmax({2.5,3.33,5.89},min,max);
    assert(min == 2.5);
    assert(max == 5.89);
}

void
test_svg_nonzero()
{
    size_t avg_bin = average_bin(5, 2);
    assert(avg_bin == 2);
}

void
test_svg_upzero()
{
    size_t avg_bin = average_bin(0, 3);
    assert (avg_bin == 0);
}
void
test_svg_downzero()
{
    size_t avg_bin = average_bin(3, 0);
    assert (avg_bin == 0);
}
int
main()
{
    test_positive();
    test_negative();
    test_equal();
    test_double();
    test_empty();
    test_svg_nonzero();
    test_svg_upzero();
    test_svg_downzero();
    return 0;
}

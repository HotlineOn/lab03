#include <iostream>
#include <vector>
#include "histogram.h"
#include "avg_bin+scaling.h"

using namespace std;

int main()
{
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    double min, max;
    find_minmax(numbers, min, max);
    const auto bins = make_histogram(numbers, bin_count);

    double scaling = scale(bins);
    size_t avg_bin = average_bin(number_count, bin_count);
    show_histogram_svg(bins, scaling, avg_bin);
    return 0;
}

#include <iostream>
#include <vector>
#include "histogram.h"

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

    const size_t MAX_ASTERISK = 76;
    size_t max_count = 0;
    for (size_t bin:bins)
    {
        if (max_count < bin)
        {
            max_count = bin;
        }
    }
    double scaling = 1;
    if (max_count > MAX_ASTERISK)
    {
        scaling = MAX_ASTERISK / (double)max_count;
    }

    size_t avg_bin = number_count / bin_count;
    show_histogram_svg(bins, scaling, avg_bin);
    return 0;
}

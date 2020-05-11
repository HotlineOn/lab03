#include <iostream>
#include <vector>
#include "histogram.h"
#include "avg_bin+scaling.h"

using namespace std;

Input
read_input(istream& in, bool prompt) {
    Input data;

    if (prompt) cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;

    if (prompt) cerr << "Enter numbers: ";
    data.numbers = input_numbers(number_count, in);

    size_t bin_count;
    if (prompt) cerr << "Enter column count: ";
    cin >> bin_count;
    data.bin_count = bin_count;

    return data;
}

int main()
{
    const auto data = read_input(cin, true);

    const auto bins = make_histogram(data.numbers, data.bin_count);

    double scaling = scale(bins);
    show_histogram_svg(bins, scaling);
    return 0;
}

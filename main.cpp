#include <iostream>
#include <vector>
#include "histogram.h"
#include "avg_bin+scaling.h"

using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
};

Input
read_input(istream& in) {
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(number_count, in);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    data.bin_count = bin_count;

    return data;
}

int main()
{
    const auto data = read_input(cin);

    const auto bins = make_histogram(data.numbers, data.bin_count);

    double scaling = scale(bins);
    show_histogram_svg(bins, scaling);
    return 0;
}

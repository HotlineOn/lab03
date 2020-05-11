#pragma once
#include <vector>
#include <string>

using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
};

vector<double> input_numbers(size_t count, istream& in);
vector <size_t> make_histogram(Input input);
void show_histogram_svg(const vector<size_t>& bins, double scaling);
void find_minmax(const vector<double> numbers, double& min, double& max);


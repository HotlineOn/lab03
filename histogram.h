#pragma once
#include <vector>
#include <string>

using namespace std;

struct Input
{
    size_t number_count;
    vector<double> numbers;
    size_t bin_count;
};

vector<double> input_numbers(istream& in, const size_t number_count);
vector <size_t> make_histogram(Input input);
void show_histogram_svg(const vector<size_t>& bins, double scaling, size_t avg_bin, int version_major, int version_minor, int build, string PC_name);
void find_minmax(const vector<double> numbers, double& min, double& max);


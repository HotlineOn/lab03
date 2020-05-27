#pragma once
#include <vector>
#include <string>

using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
};

vector <size_t> make_histogram(Input input);
void show_histogram_svg(const vector<size_t>& bins, double scaling, size_t avg_bin);
void find_minmax(const vector<double> numbers, double& min, double& max);


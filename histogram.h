#pragma once
#include <vector>
#include <string>

using namespace std;

vector<double> input_numbers(size_t count);
vector <size_t> make_histogram(const vector<double>& numbers,size_t bin_count);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void svg_text(double left, double baseline, string text);
void svg_begin(double width, double height);
void svg_end();
void show_histogram_svg(const vector<size_t>& bins, double &scaling, size_t &avg_bin);
void find_minmax(const vector<double> numbers, double& min, double& max);


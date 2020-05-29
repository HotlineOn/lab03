#include "histogram.h"
#include "svg.h"
#include <iostream>
#include <vector>


vector<double> input_numbers(istream& in, const size_t number_count) {
    vector<double> result(number_count);
    for (size_t i = 0; i < number_count; i++) {
        in >> result[i];
    }

    return result;
}

vector <size_t> make_histogram(Input input)
{
    double min = input.numbers[0];
    double max = input.numbers[0];
    find_minmax(input.numbers,min,max);
    vector<size_t> bins(input.bin_count,0);
    for (double number : input.numbers)
    {
        size_t bin;
        bin = (number - min) / (max - min) * input.bin_count;
        if (bin == input.bin_count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}



void
show_histogram_svg(const vector<size_t>& bins, double scaling, size_t avg_bin, int version_major, int version_minor, int build, string PC_name)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t bin : bins)
    {
        string stroke, fill;

        if (bin <= avg_bin)
        {
            stroke = "green";
            fill = "#00FF00";
        }
        else
        {
            stroke = "red";
            fill = "#FF0000";
        }

        const double bin_width = BLOCK_WIDTH * bin * scaling;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, stroke, fill);
        top += BIN_HEIGHT;
    }
    win_version(TEXT_LEFT, top + TEXT_BASELINE, version_major, version_minor, build, PC_name);
    svg_end();
}



void find_minmax(const vector<double> numbers, double& min, double& max)
{
    if (numbers.size()!= 0)
    {
        min = numbers[0];
        max = numbers[0];
        for (double number : numbers)
        {
            if (number < min)
            {
                min = number;
            }
            if (number > max)
            {
                max = number;
            }
        }
    }
    else cerr << "ERROR1\n";
}

#include "histogram.h"
#include "svg.h"
#include <iostream>
#include <vector>

vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}




vector <size_t> make_histogram(const vector<double>& numbers,size_t bin_count)
{
    double min = numbers[0];
    double max = numbers[0];
    find_minmax(numbers,min,max);
    vector<size_t> bins(bin_count,0);
    for (double number : numbers)
    {
        size_t bin;
        bin = (number - min) / (max - min) * bin_count;
        if (bin == bin_count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}



void
show_histogram_svg(const vector<size_t>& bins, double scaling, size_t &avg_bin)
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

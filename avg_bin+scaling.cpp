#include <iostream>
#include <vector>
#include "avg_bin+scaling.h"


double scale (const vector <size_t>& bins)
{
    const size_t MAX_ASTERISK = 40;
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
    return scaling;
}

size_t average_bin (size_t number_count, size_t bin_count)
{
    size_t avg_bin = number_count / bin_count;
    return avg_bin;
}


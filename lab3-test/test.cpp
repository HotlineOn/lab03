#include "E:\Progs\CodeBlocks\lab3\histogram.h"
#include "E:\Progs\CodeBlocks\lab3\svg.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <windows.h>
void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1,2,3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1,-2,-3},min,max);
    assert(min == -3);
    assert(max == -1);
}
void
test_empty()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
}

void
test_equal()
{
    double min = 0;
    double max = 0;
    find_minmax({3,3,3},min,max);
    assert(min == 3);
    assert(max == 3);
}

void
test_double()
{
    double min = 0;
    double max = 0;
    find_minmax({2.5,3.33,5.89},min,max);
    assert(min == 2.5);
    assert(max == 5.89);
}
//svg реализуются через командную строку и файл просматривается самим пользователем

void
test_svg1()
{
    ifstream txt("E:\\Progs\\CodeBlocks\\lab3\\bin\\Debug\\marks1.txt");
    size_t number_count;
    txt >> number_count;
    vector <double> numbers(number_count,0);
    for(size_t i = 0; i < number_count; i++)
        txt >> numbers[i];
    size_t bin_count;
    txt >> bin_count;
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
}

//проверяется в командной строке с помощью файлов marks1.txt и marks2.txt

void
test_svg()
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
}

int
main() {
    test_positive();
    test_negative();
    test_equal();
    test_double();
    test_empty();
    test_svg();
}

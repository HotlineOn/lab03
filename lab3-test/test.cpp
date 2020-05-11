#include "../histogram.h"
#include "../svg.h"
#include "../avg_bin+scaling.h"
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

void
test_svg(ifstream &fin)
{
    size_t number_count;
    fin >> number_count;
    vector <double> numbers (number_count, 0);
    for (size_t i = 0; i < number_count; i++)
        fin >> numbers[i];
    size_t bin_count;
    fin >> bin_count;
    fin.close();
    const auto bins = make_histogram(numbers, bin_count);
    double scaling = scale(bins);
    size_t avg_bin = average_bin(number_count, bin_count);
    show_histogram_svg(bins, scaling, avg_bin);
}

int
main()
{
    test_positive();
    test_negative();
    test_equal();
    test_double();
    test_empty();
    ifstream fin1("bin\\Debug\\marks1.txt");
    test_svg(fin1);
    Sleep(10000); //в течение 10 секунд тестировщик должен посмотреть результат вывода для файла fin1, затем, после окончания действия программы, снова проверить svg файл
    ifstream fin2("bin\\Debug\\marks2.txt");
    test_svg(fin2);
}

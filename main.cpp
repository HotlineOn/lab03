#include <iostream>
#include <vector>
#include "histogram.h"
#include "avg_bin+scaling.h"
#include <curl/curl.h>
#include <sstream>
#include <string>

using namespace std;

vector<double> input_numbers(istream& in, const size_t number_count) {
    vector<double> result(number_count);
    for (size_t i = 0; i < number_count; i++) {
        in >> result[i];
    }

    return result;
}

Input
read_input(istream& in, bool prompt)
{
    Input data;

    if (prompt) cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;

    if (prompt) cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    size_t bin_count;
    if (prompt) cerr << "Enter column count: ";
    in >> bin_count;
    data.bin_count = bin_count;

    return data;
}

size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    if (ctx)
    {
        const size_t data_size = item_size * item_count;
        stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
        buffer->write(reinterpret_cast<const char*>(items), data_size);
        return data_size;
    }
    else return 0;
}

Input
download(const string& address) {
    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);
        CURL* curl = curl_easy_init();
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
            res = curl_easy_perform(curl);
            if (res != CURLE_OK)
            {
                cout << curl_easy_strerror(res);
                exit(1);
            }
            curl_easy_cleanup(curl);
        }
    return read_input(buffer, false);
}

int main(int argc, char* argv[])
{
    Input input;
    if (argc > 1) {
        input = download(argv[1]);
    }
    else {
        input = read_input(cin, true);
    }

    const auto bins = make_histogram(input);

    double scaling = scale(bins);
    size_t number_count = sizeof(input.numbers);
    size_t avg_bin = average_bin(number_count, input.bin_count);
    show_histogram_svg(bins, scaling, avg_bin);
    return 0;
}

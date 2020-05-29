#include <string>
#include <iostream>
#include <fstream>
#include "svg.h"

using namespace std;

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='"<<x<< "' y='" <<y<<"' width='" <<width <<"' height='" <<height <<"' stroke='"<<stroke<<"' fill='"<<fill<<"'/>";
    cout << "\n";
}


void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline <<"'>" <<text <<"</text>";
    cout << "\n";
}


void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void win_version(double left, double baseline, int version_major, int version_minor, int build, string PC_name)
{
    cout << "<text  x='" << left << "' y='" << baseline <<"'> Windows v" << version_major << "." << version_minor << " (build " << build << ") " <<
    PC_name << "</text>";
    cout << "\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

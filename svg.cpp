#include <string>
#include <iostream>
#include <fstream>
#include "svg.h"
#define SVG "E:\\Progs\\CodeBlocks\\lab3-test\\bin\\Debug\\marks.svg"
using namespace std;

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    ofstream fout(SVG, ios_base::app);
    fout << "<rect x='"<<x<< "' y='" <<y<<"' width='" <<width <<"' height='" <<height <<"' stroke='"<<stroke<<"' fill='"<<fill<<"'/>";
    fout << "\n";
    fout.close();
}


void svg_text(double left, double baseline, string text)
{
    ofstream fout(SVG, ios_base::app);
    fout << "<text x='" << left << "' y='" << baseline <<"'>" <<text <<"</text>";
    fout << "\n";
    fout.close();
}


void svg_begin(double width, double height)
{
    ofstream fout(SVG);
    if (!fout.is_open())
    {
        cout << "1";
    }
    fout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    fout << "<svg ";
    fout << "width='" << width << "' ";
    fout << "height='" << height << "' ";
    fout << "viewBox='0 0 " << width << " " << height << "' ";
    fout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    ofstream fout(SVG, ios_base::app);
    fout << "</svg>\n";
    fout.close();
}

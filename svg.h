#pragma once
#include <string>
using namespace std;

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void svg_text(double left, double baseline, string text);
void svg_begin(double width, double height);
void win_version(double left, double baseline, int version_major, int version_minor, int build, string PC_name);
void svg_end();

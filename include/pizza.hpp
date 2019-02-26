#pragma once
#include <istream>

struct Input {
    int r;
    int c;
    int l;
    int h;
};

Input read_input(std::istream& is);

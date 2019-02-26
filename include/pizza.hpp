#pragma once

#include <istream>
#include <vector>

struct Input {
    int r;
    int c;
    int l;
    int h;
    std::vector<char> matrix;
};

Input read_input(std::istream& is);

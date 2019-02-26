#include "pizza.hpp"
#include <cstdio>
#include <sstream>
#include <cassert>

int main() {
    std::stringstream ss(
            "3 5 1 6\n"
            "TTTTT\n"
            "TMMMT\n"
            "TTTTT\n");
    read_input(ss);
    return 0;
}

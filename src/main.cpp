#include "pizza.hpp"
#include <cstdio>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <array>
#include <vector>
#include <cstdlib>

int checkValid(char *pizza, char *covered, int row, int col,
        int height, int width) {
    int sumM, sumC;
    for (int i=row; i < row + height; ++i) {
        for (int j=col; j < col + width; ++j) {
            sumM += pizza[i*c + j];
            sumC += covered[i*c + j];
        }
    }
    if(sumC) return 0;
    if(sumM < l) return 0;
    if((height*width - sumM) < l) return 0;
    return 1;
}

void cover(char* covered, int row, int col, int height, int width) {
    for (int i=row; i < row + height; ++i) {
        for (int j=col; j < col + width; ++j) {
            covered[i*c + j] = 1;
        }
    }
}

int main() {
    std::stringstream ss(
            "3 5 1 6\n"
            "TTTTT\n"
            "TMMMT\n"
            "TTTTT\n");
    read_input(ss);

    char *pizza = mat;
    char *covered = (char*) malloc(r * c * sizeof *covered);
    std::vector<std::array<int, 2>> sliceSizes;
    std::vector<std::array<int, 4>> slices;

    for (int i=0; i <= h; ++i) {
        for (int j=0; j*i <= h; ++j) {
            sliceSizes.push_back(std::array<int, 2>{i, j});
        }
    }

    //largest slices first
    std::sort(sliceSizes.begin(), sliceSizes.end(),
            [](std::array<int, 2> a, std::array<int, 2> b) {
                return a[0]*a[1] > b[0]*b[1];
            });

    for (int i=0; i < r; ++i) {
        for (int j=0; j < c; ++j) {
            if (covered[i*c + j]) continue;
            for (unsigned int k=0; k < sliceSizes.size(); ++k) {
                if (checkValid(pizza, covered, i, j,
                        sliceSizes[k][0], sliceSizes[k][1])) {
                    int height = sliceSizes[k][0];
                    int width = sliceSizes[k][1];
                    slices.push_back(std::array<int, 4>{i, j,
                        i + height - 1, j + width - 1});
                    cover(covered, i, j, height, width);
                    break;
                }
            }
        }
    }
    //TODO smallest slices first then expand

    free(mat);
    free(covered);
    //TODO actually use result
    return slices.size();
    //return 0;
}

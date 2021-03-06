#include "pizza.hpp"
#include <cstdlib>

int r;
int c;
int h;
int l;
char *mat;

void read_input(std::istream& is) {
    is >> r >> c >> h >> l;
    mat = (char*) malloc(r * c * sizeof *mat);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            is >> mat[i * c + j];
            if (mat[i * c + j] == 'T')
                mat[i * c + j] = 0;
            else
                mat[i * c + j] = 1;
        }
        is.get();
    }
}

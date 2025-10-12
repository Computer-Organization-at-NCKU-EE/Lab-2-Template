#include "sudoku_config.h"

extern void sudoku_solver(int *arr_ptr);

int sudoku_verifier(int *arr_ptr) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            //
        }
    }
    return 0;
}

int main(void) {
    int arr[] = { SUDOKU_RANDOM_ARRAY };
    sudoku_solver(arr);
    return sudoku_verifier(arr);
}

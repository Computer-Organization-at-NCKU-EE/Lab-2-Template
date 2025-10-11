#include "merge_config.h"

extern void array_sort(int *arr_ptr, unsigned arr_size);

int array_sort_verifier(int *arr_ptr, unsigned arr_size) {
    //
    return 0;
}

int main(void) {
    int arr[] = { MERGE_SORT_RANDOM_ARRAY };
    array_sort(arr, MERGE_SORT_RANDOM_ARRAY_SIZE);
    return array_sort_verifier(arr, MERGE_SORT_RANDOM_ARRAY_SIZE);
}

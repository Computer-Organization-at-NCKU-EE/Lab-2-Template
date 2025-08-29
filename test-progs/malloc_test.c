#include "print.h"
#include "memory.h"

int main(void) {
    my_alloc_init();
    int *a = my_malloc(sizeof(int));
    *a     = 5;
    printf("a: %d\n", *a);
    *a = 10;
    printf("a: %d\n", *a);
    int *b = my_malloc(sizeof(int));
    *b     = 15;
    printf("b: %d\n", *b);
    *b = 20;
    printf("b: %d\n", *b);
    my_free(a);
    my_free(b);
}

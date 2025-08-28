#include "memory.h"

extern char *_sheap;
extern char *_eheap;
static char *heap_ptr;
static unsigned allocated_cnt;

void alloc_init(void) {
    heap_ptr      = _sheap;
    allocated_cnt = 0;
}

/*
 * Implement Bump Allocator
 * It can only free all used memory at once when all allocated object is freed
 */
void *malloc(size_t size) {
    if (heap_ptr + size > _eheap) {
        return NULL;
    }
    heap_ptr += size;
    allocated_cnt++;
    return (void *)(heap_ptr - size);
}

void free(void *ptr) {
    if (allocated_cnt > 0) {
        allocated_cnt--;
    }
    // free all memroy at once
    if (allocated_cnt == 0) {
        heap_ptr = _sheap;
    }
}

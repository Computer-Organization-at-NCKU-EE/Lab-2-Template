#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#include "basic.h"

int _open(const char *name, int flags, int mode) {
    return 1; // always return fd of stdout
}

int _close(int file) {
    return 0; // not supported
}

ssize_t _read(int file, void *ptr, size_t len) {
    return len;
}

ssize_t _write(int file, const void *ptr, size_t len) {
    volatile uint8_t *text_buff = (uint8_t *)TEXT_BUFFER_BASE;
    for (size_t i = 0; i < len; i++) {
        *text_buff = ((uint8_t *)ptr)[i];
    }
    return len;
}

int _fstat(int file, struct stat *st) {
    return 0;
}

int _isatty(int file) {
    return 0;
}

extern char _sheap[];
extern char _eheap[];
void *_sbrk(ptrdiff_t incr) {
    static unsigned long heap_end = (unsigned long)_sheap;
    if (heap_end + incr > (unsigned long)_eheap) {
        return NULL;
    }
    heap_end += incr;
    return (void *)(heap_end - incr);
}

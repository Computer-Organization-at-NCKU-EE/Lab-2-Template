#include "basic.h"

void terminate(void) {
    *(uint8_t *)HALT_BASE = 1;
    for (;;) {
        // infinite loop
    }
}

void platform_outb(char c) {
    *(uint8_t *)TEXT_BUFFER_BASE = c;
}

void start(void) {
    // initialize .bss section
    extern void *_sbss;
    extern void *_ebss;
    for (unsigned long i = (unsigned long)_sbss; i < (unsigned long)_ebss; i++) {
        *(uint8_t *)i = 0; // zero initialize byte-by-byte
    }

    // copy .data section from ROM to RAM
    extern void *_sidata;
    extern void *_sdata;
    extern void *_edata;
    for (unsigned long i = (unsigned long)_sdata; i < (unsigned long)_edata; i++) {
        *(uint8_t *)i = *(uint8_t *)((unsigned long)_sidata + i); // copy byte-by-byte
    }

    extern int main(void);
    main();
}

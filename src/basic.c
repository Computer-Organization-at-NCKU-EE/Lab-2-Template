#include "basic.h"

void terminate(void) {
    volatile uint8_t *halt = (uint8_t *)HALT_BASE;
    *halt                  = 1;
    for (;;) {
        // infinite loop
    }
}

void platform_outb(char c) {
    volatile char *text_buf = (char *)TEXT_BUFFER_BASE;
    *text_buf               = c;
}

void start(void) {
    // initialize .bss section
    extern char _sbss[];
    extern char _ebss[];
    for (unsigned long i = (unsigned long)_sbss; i < (unsigned long)_ebss; i++) {
        *(uint8_t *)i = 0; // zero initialize byte-by-byte
    }

    // copy .data section from ROM to RAM
    extern char _sidata[];
    extern char _sdata[];
    extern char _edata[];
    for (unsigned long i = (unsigned long)_sdata; i < (unsigned long)_edata; i++) {
        *(uint8_t *)i = *(uint8_t *)((unsigned long)_sidata + i); // copy byte-by-byte
    }

    extern int main(void);
    main();
}

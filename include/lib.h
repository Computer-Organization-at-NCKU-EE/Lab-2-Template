#ifndef __LIB_H__
#define __LIB_H__

#include <stdint.h>

// for replacing _write() in newlib
extern int _write(int fd, const void *buf, int nbytes);
// function used to terminate the execution of current RISC-V program
extern void terminate(void) __attribute__((noreturn));

/* MMIO functions */
extern void MMIO_load(uint32_t base_addr, unsigned length, uint8_t *buf);
extern void MMIO_store(uint32_t base_addr, unsigned length, const uint8_t *buf);

#endif

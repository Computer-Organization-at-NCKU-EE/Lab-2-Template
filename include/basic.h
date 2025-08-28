#ifndef __BASIC_H__
#define __BASIC_H__

#include <stdint.h>

// function used to terminate the execution of current RISC-V program
extern void terminate(void) __attribute__((noreturn));

// function used to send some characters to the text buffer
extern void platform_outb(char c);

#endif

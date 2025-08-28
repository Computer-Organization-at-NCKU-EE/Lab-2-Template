#include "print.h"

#include "basic.h"

#include <stdarg.h>

void putc(char c) {
    platform_outb(c);
}

void puts(char *s) {
    while (*s != '\0') {
        putc(*(s++));
    }
}

void putint(int numb) {
    if (numb < 0) {
        putc('-');
        numb = -numb; // convert to positive number
    }

    if (numb / 10) {
        putint(numb / 10);
    }
    putc((numb % 10) + '0');
}

void printf(char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
            case 'c': { // char
                char c = va_arg(args, int);
                putc(c);
                break;
            }
            case 'd': { // int
                int numb = va_arg(args, int);
                putint(numb);
                break;
            }
            case 's': { // string
                char *s = va_arg(args, char *);
                puts(s);
                break;
            }
            default: break;
            }
        } else {
            putc(*format);
        }
        format++;
    }

    va_end(args);
}

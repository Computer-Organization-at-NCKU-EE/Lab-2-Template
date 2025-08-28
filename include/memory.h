#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stddef.h>

extern void alloc_init(void);
extern void *malloc(size_t size);
extern void free(void *ptr);

#endif

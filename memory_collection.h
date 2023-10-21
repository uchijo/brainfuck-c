#ifndef MEMORY_COLLECTION_H
#define MEMORY_COLLECTION_H

#include <stdlib.h>

#include "memory.h"

typedef struct MemoryCollection {
    Memory* current_mem;
} MemoryCollection;

MemoryCollection* create_memory_collection();
char get_current_mem(MemoryCollection* memc);
void next_mem(MemoryCollection* memc);
void prev_mem(MemoryCollection* memc);

#endif

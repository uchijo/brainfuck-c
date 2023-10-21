#ifndef MEMORY_COLLECTION_H
#define MEMORY_COLLECTION_H

#include <stdlib.h>

#include "memory.h"

typedef struct MemoryCollection {
    Memory* current_mem;
    char* input;
    int input_length;
    int current_instr;
} MemoryCollection;

MemoryCollection* create_memory_collection(char* input);
char get_current_mem(MemoryCollection* memc);
char get_current_instr(MemoryCollection* memc);
void next_mem(MemoryCollection* memc);
void prev_mem(MemoryCollection* memc);
int has_instr(MemoryCollection* memc);

#endif

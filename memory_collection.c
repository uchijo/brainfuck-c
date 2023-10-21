#include "memory_collection.h"

#include <stdio.h>

#include "memory.h"

MemoryCollection* create_memory_collection() {
    MemoryCollection* memc = malloc(sizeof(MemoryCollection));
    if (!memc) {
        return NULL;
    }

    memc->current_mem = create_memory();
    if (!memc->current_mem) {
        return NULL;
    }

    return memc;
}

char get_current_mem(MemoryCollection* memc) { return memc->current_mem->data; }

void next_mem(MemoryCollection* memc) {
    Memory* next_mem = get_next(memc->current_mem);
    next_mem->prev = memc->current_mem;
    memc->current_mem->next = next_mem;
    memc->current_mem = next_mem;
}

void prev_mem(MemoryCollection* memc) {
    Memory* prev_mem = get_prev(memc->current_mem);
    prev_mem->next = memc->current_mem;
    memc->current_mem->prev = prev_mem;
    memc->current_mem = prev_mem;
}

#include "memory_collection.h"

#include <stdio.h>
#include <string.h>

#include "memory.h"

MemoryCollection* create_memory_collection(char* input) {
    MemoryCollection* memc = malloc(sizeof(MemoryCollection));
    if (!memc) {
        return NULL;
    }

    memc->input = malloc(sizeof(char) * (strlen(input) + 1));
    if (!memc->input) {
        return NULL;
    }
    strcpy(memc->input, input);

    memc->current_mem = create_memory();
    if (!memc->current_mem) {
        return NULL;
    }

    memc->current_instr = 0;
    memc->input_length = strlen(input);
    return memc;
}

char get_current_mem(MemoryCollection* memc) { return memc->current_mem->data; }

char get_current_instr(MemoryCollection* memc) {
    return memc->input[memc->current_instr];
}

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

int has_instr(MemoryCollection* memc) {
    return memc->current_instr < memc->input_length;
}

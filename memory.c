#include "memory.h"

#include <stdlib.h>

Memory* create_memory() {
    Memory* new_mem = malloc(sizeof(Memory));
    if (new_mem) {
        new_mem->data = 0;
        new_mem->next = NULL;
        new_mem->prev = NULL;
    }
    return new_mem;
}

void delete_memory(Memory* mem) { free(mem); }

Memory* get_next(Memory* mem) {
    if (mem->next) {
        return mem->next;
    }

    Memory* new_mem = create_memory();
    if (new_mem) {
        mem->next = new_mem;
        new_mem->prev = mem;
    }
    return new_mem;
}

Memory* get_prev(Memory* mem) {
    if (mem->prev) {
        return mem->prev;
    }

    Memory* new_mem = create_memory();
    if (new_mem) {
        mem->prev = new_mem;
        new_mem->next = mem;
    }
    return new_mem;
}

void increment_data(Memory* mem) { mem->data++; }

void decrement_data(Memory* mem) { mem->data--; };

void set_data(Memory* mem, int new_data) { mem->data = new_data; };

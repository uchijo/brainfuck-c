#ifndef MEMORY_H
#define MEMORY_H

typedef struct Memory {
    int data;
    struct Memory* next;
    struct Memory* prev;
} Memory;

Memory* create_memory();
void delete_memory(Memory* mem);
Memory* get_next(Memory* mem);
Memory* get_prev(Memory* mem);
void increment_data(Memory* mem);
void decrement_data(Memory* mem);
void set_data(Memory* mem, int new_data);

#endif

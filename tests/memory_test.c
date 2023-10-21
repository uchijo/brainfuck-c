#include "../memory.h"

#include <assert.h>
#include <stdio.h>

void test_create_memory() {
    Memory* mem = create_memory();
    assert(mem != NULL);
    assert(mem->data == 0);
    assert(mem->next == NULL);
    assert(mem->prev == NULL);
    delete_memory(mem);
    printf("[pass] test_create_memory\n");
}

void test_get_next() {
    Memory *mem = create_memory();
    Memory *next_mem = get_next(mem);
    assert(mem != NULL);
    assert(next_mem != NULL);
    assert(next_mem->prev == mem);
    assert(next_mem->next == NULL);
    delete_memory(mem);
    delete_memory(next_mem);
    printf("[pass] test_get_next\n");
}

void test_get_prev() {
    Memory *mem = create_memory();
    Memory *prev_mem = get_prev(mem);
    assert(mem != NULL);
    assert(prev_mem != NULL);
    assert(prev_mem->next == mem);
    assert(prev_mem->prev == NULL);
    delete_memory(mem);
    delete_memory(prev_mem);
    printf("[pass] test_get_prev\n");
}

int main() {
    test_create_memory();
    test_get_next();
    test_get_prev();
    printf("all tests passed!\n");
    return 0;
}

#include "../memory_collection.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../memory.h"

void test_create_memory_collection() {
    char* input = "hogehoge~";
    MemoryCollection* memc = create_memory_collection(input);
    assert(memc != NULL);
    assert(memc->input != NULL);
    assert(!strcmp(memc->input, input));
    assert(memc->current_instr == 0);
    assert(strlen(memc->input) == memc->input_length);
    printf("[pass] test_create_memory_collection\n");
}

void test_get_current_mem() {
    char* input = "hogehoge~";
    MemoryCollection* memc = create_memory_collection(input);
    assert(get_current_mem(memc) == 0);
    increment_data(memc->current_mem);
    assert(get_current_mem(memc) == 1);
    printf("[pass] test_get_current_mem\n");
}

void test_move_mem() {
    char* input = "hogehoge~";
    MemoryCollection* memc = create_memory_collection(input);
    increment_data(memc->current_mem);
    next_mem(memc);
    increment_data(memc->current_mem);
    increment_data(memc->current_mem);
    prev_mem(memc);
    prev_mem(memc);
    increment_data(memc->current_mem);
    increment_data(memc->current_mem);
    increment_data(memc->current_mem);
    increment_data(memc->current_mem);
    assert(memc->current_mem->data == 4);
    next_mem(memc);
    assert(memc->current_mem->data == 1);
    next_mem(memc);
    assert(memc->current_mem->data == 2);
    printf("[pass] test_move_mem\n");
}

void test_current_instr() {
    char* input = "hogehoge~";
    MemoryCollection* memc = create_memory_collection(input);
    char instr = get_current_instr(memc);
    assert(instr == input[0]);
    printf("[pass] test_current_instr\n");
}

void test_has_instr() {
    char* input = "hogehoge~";
    MemoryCollection* memc = create_memory_collection(input);
    assert(has_instr(memc));

    char* input2 = "";
    MemoryCollection* memc2 = create_memory_collection(input2);
    assert(!has_instr(memc2));

    char* input3 = "a";
    MemoryCollection* memc3 = create_memory_collection(input3);
    assert(has_instr(memc3));
    printf("[pass] test_has_instr\n");
}

int main() {
    test_create_memory_collection();
    test_get_current_mem();
    test_move_mem();
    test_current_instr();
    test_has_instr();
    printf("all tests passed!\n\n");
    return 0;
}

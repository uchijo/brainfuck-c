#ifndef ENGINE_H
#define ENGINE_H

#include "memory_collection.h"
#include "stack.h"

typedef struct Engine {
    MemoryCollection* memc;
    char* input;
    int input_length;
    int current_instr;
    Stack* stack;
} Engine;

Engine* create_engine(char* input);
char get_current_instr(Engine* e);
int has_instr(Engine* e);
void eval(Engine* e);

#endif

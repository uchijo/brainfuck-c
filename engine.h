#ifndef ENGINE_H
#define ENGINE_H

#include "memory_collection.h"

typedef struct Engine {
    MemoryCollection* memc;
    char* input;
    int input_length;
    int current_instr;
    int steps;
    int steps_limit;
} Engine;

Engine* create_engine(char* input, int limit);
char get_current_instr(Engine* e);
int has_instr(Engine* e);
void eval(Engine* e);

#endif

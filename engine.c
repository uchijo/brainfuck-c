#include "engine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "memory_collection.h"

Engine* create_engine(char* input) {
    Engine* e = malloc(sizeof(Engine));
    if (!e) {
        return NULL;
    }

    e->input = malloc(sizeof(char) * (strlen(input) + 1));
    if (!e->input) {
        return NULL;
    }
    strcpy(e->input, input);

    e->memc = create_memory_collection();
    if (!e->memc) {
        return NULL;
    }

    e->current_instr = 0;
    e->input_length = strlen(input);

    return e;
}

char get_current_instr(Engine* e) { return e->input[e->current_instr]; }

int has_instr(Engine* e) { return e->current_instr < e->input_length; }

void eval(Engine* e) {
    int in;
    for (;;) {
        if (!has_instr(e)) {
            break;
        }
        char instr = get_current_instr(e);
        switch (instr) {
            case '+':
                increment_data(e->memc->current_mem);
                break;
            case '-':
                decrement_data(e->memc->current_mem);
                break;
            case '.':
                printf("%c", get_current_mem(e->memc));
                break;
            case ',':
                in = getchar();
                set_data(e->memc->current_mem, in);
                break;
            case '>':
                next_mem(e->memc);
                break;
            case '<':
                prev_mem(e->memc);
                break;

            default:
                break;
        }

        e->current_instr++;
    }
}

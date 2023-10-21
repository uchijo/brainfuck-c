#include "../engine.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../memory_collection.h"

void test_current_instr() {
    char* input = "hogehoge~";
    Engine* e = create_engine(input);
    char instr = get_current_instr(e);
    assert(instr == input[0]);
    printf("[pass] test_current_instr\n");
}

void test_has_instr() {
    char* input = "hogehoge~";
    Engine* e1 = create_engine(input);
    assert(has_instr(e1));

    char* input2 = "";
    Engine* e2 = create_engine(input2);
    assert(!has_instr(e2));

    char* input3 = "a";
    Engine* e3 = create_engine(input3);
    assert(has_instr(e3));
    printf("[pass] test_has_instr\n");
}

int main() {
    test_current_instr();
    test_has_instr();
    printf("all tests passed!\n\n");
    return 0;
}

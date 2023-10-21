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

void test_eval1() {
    char* input = "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.";
    Engine* e = create_engine(input);
    eval(e);

    printf("[pass] test_eval1\n");
}

void test_eval2() {
    char* input = "+++++++++[>++++++++>+++++++++++>+++>+<<<<-]>.>++.+++++++..+++.>+++++.<<+++++++++++++++.>.+++.------.--------.>+.>+.";
    Engine* e = create_engine(input);
    eval(e);

    printf("[pass] test_eval2\n");
}

void test_eval3() {
    char* input = "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[>]<.";
    Engine* e = create_engine(input);
    eval(e);

    printf("[pass] test_eval3\n");
}

int main() {
    test_current_instr();
    test_has_instr();
    test_eval1();
    test_eval2();
    test_eval3();
    printf("all tests passed!\n\n");
    return 0;
}

#include "../stack.h"

#include <assert.h>
#include <stdio.h>

void test_create_stack() {
    Stack* stack = create_stack();
    assert(stack->head == NULL);
    printf("[pass] test_create_stack\n");
}

void test_push() {
    Stack* stack = create_stack();
    push(stack, 10);
    assert(peek(stack) == 10);
    push(stack, 20);
    assert(peek(stack) == 20);
    printf("[pass] test_push\n");
}

void test_pop() {
    Stack* stack = create_stack();
    push(stack, 10);
    assert(peek(stack) == 10);
    push(stack, 20);
    assert(peek(stack) == 20);
    assert(pop(stack) == 20);
    assert(peek(stack) == 10);
    printf("[pass] test_pop\n");
}

void test_pop_empty() {
    Stack* stack = create_stack();
    assert(pop(stack) == 0);
    printf("[pass] test_pop_empty\n");
}

void test_empty() {
    Stack* stack = create_stack();
    assert(is_empty(stack));
    push(stack, 10);
    assert(!is_empty(stack));
    pop(stack);
    assert(is_empty(stack));
    printf("[pass] test_empty\n");
}

void test_peek_empty() {
    Stack* stack = create_stack();
    assert(peek(stack) == 0);
    printf("[pass] test_peek_empty\n");
}

int main() {
    test_create_stack();
    test_push();
    test_pop();
    test_pop_empty();
    test_empty();
    test_peek_empty();
    printf("all tests passed!\n\n");
    return 0;
}


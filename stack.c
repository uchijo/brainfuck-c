#include "stack.h"

#include <stdlib.h>

Stack* create_stack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

Node* create_node(int value, Node* prev) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->prev = prev;
    return node;
}

void push(Stack* stack, int value) {
    Node* new_node = create_node(value, NULL);
    if (!new_node) {
        return;
    }

    if (stack->head == NULL) {
        stack->head = new_node;
        return;
    }

    new_node->prev = stack->head;
    stack->head = new_node;
}

int pop(Stack* stack) {
    if (is_empty(stack)) {
        return 0;
    }
    int top = stack->head->value;
    Node* tmp = stack->head;
    stack->head = stack->head->prev;
    delete_node(tmp);

    return top;
}

int peek(Stack* stack) {
    if (is_empty(stack)) {
        return 0;
    }
    return stack->head->value;
}

void delete_node(Node* node) { free(node); }

int is_empty(Stack* stack) { return stack->head == NULL; }

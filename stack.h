#ifndef STACK_H
#define STACK_H

typedef struct Node {
    struct Node* prev;
    int value;
} Node;

typedef struct Stack {
    Node* head;
} Stack;

Stack* create_stack();
Node* create_node(int value, Node* prev);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
void delete_node(Node* node);
int is_empty(Stack* stack);

#endif

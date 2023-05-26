/*
Write a program to implement a stack and perform the following operations:
- Push an element onto the stack
- Pop an element from the stack
- Find the minimum element in the stack in 0(1) time complexity
*/

#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int stack[MAX_SIZE];
    int min_stack[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }

    stack->stack[++stack->top] = element;

    if (isEmpty(stack) || element < stack->min_stack[stack->top - 1])
        stack->min_stack[stack->top] = element;
    else
        stack->min_stack[stack->top] = stack->min_stack[stack->top - 1];
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }

    int element = stack->stack[stack->top--];
    stack->min_stack[stack->top + 1] = -1;

    return element;
}

int getMinimum(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack->min_stack[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 5);
    push(&stack, 3);
    push(&stack, 8);
    push(&stack, 2);
    push(&stack, 6);

    printf("Minimum element: %d\n", getMinimum(&stack));

    pop(&stack);
    pop(&stack);

    printf("Minimum element: %d\n", getMinimum(&stack));

    printf("\n");
    return 0;
}

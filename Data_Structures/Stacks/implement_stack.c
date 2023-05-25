/*
Write a program to implement a stack and perform the following operations:
Push an element onto the stack
Pop an element from the stack
Check if the stack is empty
Display the top element of the stack without removing it
*/

#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int stack[MAX_SIZE];
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
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }
    return stack->stack[stack->top--];
}

int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->stack[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", top(&stack));
    printf("\n");

    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);
    printf("\n");

    int poppedElement_a = pop(&stack);
    printf("Popped element: %d\n", poppedElement_a);
    printf("\n");

    int poppedElement_b = pop(&stack);
    printf("Popped element: %d\n", poppedElement_b);
    printf("\n");

    int poppedElement_c = pop(&stack);
    printf("Popped element: %d\n", poppedElement_c);
    printf("\n");

    return 0;
}

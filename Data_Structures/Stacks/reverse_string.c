// Write a program to reverse a given string using a stack. The input string can contain any characters

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
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

void push(Stack* stack, char element) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }
    stack->stack[++stack->top] = element;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return '\0';
    }
    return stack->stack[stack->top--];
}

void reverseString(char* string) {
    int len = strlen(string);
    Stack stack;
    initialize(&stack);

    for (int i = 0; i < len; i++)
        push(&stack, string[i]);

    for (int i = 0; i < len; i++)
        string[i] = pop(&stack);
}

int main() {
    char string[] = "Hello, World!";
    printf("Original string: %s\n", string);

    reverseString(string);
    printf("Reversed string: %s\n", string);
    printf("\n");

    return 0;
}

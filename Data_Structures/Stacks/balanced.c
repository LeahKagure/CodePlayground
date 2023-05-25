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

int isBalanced(char* parentheses) {
    Stack stack;
    initialize(&stack);
    int len = strlen(parentheses);

    for (int i = 0; i < len; i++) {
        if (parentheses[i] == '(')
            push(&stack, parentheses[i]);
        else if (parentheses[i] == ')') {
            if (isEmpty(&stack))
                return 0;
            pop(&stack);
        }
    }

    return isEmpty(&stack);
}

int main() {
    char parentheses1[] = "((()))";
    char parentheses2[] = "((())";

    if (isBalanced(parentheses1))
        printf("Parentheses 1 are balanced.\n");
    else
        printf("Parentheses 1 are not balanced.\n");

    if (isBalanced(parentheses2))
        printf("Parentheses 2 are balanced.\n");
    else
        printf("Parentheses 2 are not balanced.\n");
    printf("\n");

    return 0;
}

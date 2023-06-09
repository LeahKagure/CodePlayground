// Write a recursive function to calculate the nth Fibonacci number

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int number = 6;
    int result = fibonacci(number);
    printf("The %dth Fibonacci number is %d\n", number, result);
    return 0;
}
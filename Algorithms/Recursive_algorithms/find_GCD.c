// Write a recursive function to find the GCD (greatest common divisor) of two numbers

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int number1 = 36;
    int number2 = 48;
    int result = gcd(number1, number2);
    printf("GCD of %d and %d is %d\n", number1, number2, result);
    return 0;
}
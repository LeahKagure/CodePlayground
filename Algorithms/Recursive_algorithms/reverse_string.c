// Write a recursive function to reverse a string

#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    if (strlen(str) == 0) {
        return;
    } else {
        reverseString(str + 1);
        printf("%c", str[0]);
    }
}

int main() {
    char str[] = "Hello, World!";
    reverseString(str);
    printf("\n");
    return 0;
}
// Given a string, find the first non-repeating character

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

int findFirstNonRepeatingChar(char* str) {
    int count[MAX_SIZE] = {0};
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        count[str[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (count[str[i]] == 1) {
            return i;
        }
    }

    return -1;  // No non-repeating character found
}

int main() {
    char str[] = "openai";

    int index = findFirstNonRepeatingChar(str);
    if (index != -1) {
        printf("First non-repeating character: %c\n", str[index]);
    } else {
        printf("No non-repeating character found!\n");
    }

    printf("\n");
    return 0;
}

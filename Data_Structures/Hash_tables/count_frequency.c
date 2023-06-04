// A program to count the frequency of elements in an array using a hash table

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void countFrequency(int arr[], int size) {
    int hash[SIZE] = {0};

    for (int i = 0; i < size; i++) {
        hash[arr[i]]++;
    }

    printf("Element\tFrequency\n");
    for (int i = 0; i < SIZE; i++) {
        if (hash[i] != 0) {
            printf("%d\t%d\n", i, hash[i]);
        }
    }
}

int main() {
    int arr[] = {5, 2, 8, 2, 6, 5, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    countFrequency(arr, size);

    printf("\n");
    return 0;
}

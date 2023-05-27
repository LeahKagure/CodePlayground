// A program to perform a linear search to find the position of a given element in an array

#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // element found, return its position
        }
    }
    return -1; // element not found
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int position = linearSearch(arr, size, key);

    if (position != -1) {
        printf("Element found at position: %d\n", position);
    } else {
        printf("Element not found.\n");
    }
    
    printf("\n");
    return 0;
}

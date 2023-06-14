// A program to sort an array of integers using the Counting Sort algorithm
// Assume that the input array contains integers ranging from 0 to 9

#include <stdio.h>

#define SIZE 10
#define RANGE 10

void countingSort(int arr[], int n) {
    // Create a counting array of size RANGE and initialize all elements to 0
    int count[RANGE] = { 0 };

    // Calculate the frequency of each element in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the counting array to contain the actual position of each element in the sorted array
    for (int i = 1; i < RANGE; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted elements
    int output[n];

    // Place each element in its correct position in the sorted array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[SIZE] = { 4, 2, 6, 3, 1, 9, 8, 0, 7, 5 };

    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countingSort(arr, SIZE);

    printf("Sorted array using Counting Sort:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

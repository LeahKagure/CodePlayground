// Given an array of integers, find a pair of elements that sum up to a target value

#include <stdio.h>

void findPair(int arr[], int size, int target) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found: %d, %d\n", arr[i], arr[j]);
                return;
            }
        }
    }
    printf("No pair found for the given target.\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;
    findPair(arr, size, target);
    printf("\n");
    return 0;
}
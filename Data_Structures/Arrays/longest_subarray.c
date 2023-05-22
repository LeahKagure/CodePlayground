//Given an array of integers, find the longest increasing subarray (contiguous elements) and return its length

#include <stdio.h>

int longestIncreasingSubarray(int arr[], int size) {
    int maxLength = 1;
    int currentLength = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[i - 1]) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }

    if (currentLength > maxLength) {
        maxLength = currentLength;
    }

    return maxLength;
}

int main() {
    int arr[] = {1, 2, 3, 2, 5, 7, 8, 9, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int length = longestIncreasingSubarray(arr, size);

    printf("Longest increasing subarray length: %d\n\n", length);

    return 0;
}

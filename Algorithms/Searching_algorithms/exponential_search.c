// A program to perform an exponential search to find the position of a given element in a sorted array

#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // element found, return its position
        }

        if (arr[mid] < key) {
            left = mid + 1; // search the right half
        } else {
            right = mid - 1; // search the left half
        }
    }

    return -1; // element not found
}

int exponentialSearch(int arr[], int size, int key) {
    if (arr[0] == key) {
        return 0; // element found at the beginning
    }

    int i = 1;
    while (i < size && arr[i] <= key) {
        i *= 2; // double the position for each iteration
    }

    return binarySearch(arr, i / 2, (i < size) ? i : size - 1, key);
}

int main() {
    int arr[] = {2, 4, 8, 16, 32, 64, 128, 256, 512};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 64;

    int position = exponentialSearch(arr, size, key);

    if (position != -1) {
        printf("Element found at position: %d\n", position);
    } else {
        printf("Element not found.\n");
    }

    printf("\n");
    return 0;
}

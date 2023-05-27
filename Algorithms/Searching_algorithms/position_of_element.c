// A program to perform a binary search to find the position of a given element in a sorted array

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

int main() {
    int arr[] = {1, 2, 4, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int position = binarySearch(arr, 0, size - 1, key);

    if (position != -1) {
        printf("Element found at position: %d\n", position);
    } else {
        printf("Element not found.\n");
    }

    printf("\n");
    return 0;
}

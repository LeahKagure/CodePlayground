// A program to perform interpolation search to find the position of a given element in a sorted array

#include <stdio.h>

int interpolationSearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key)
                return low; // element found
            return -1; // element not found
        }
        
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        
        if (arr[pos] == key)
            return pos; // element found
        
        if (arr[pos] < key)
            low = pos + 1; // search the right side
        else
            high = pos - 1; // search the left side
    }
    
    return -1; // element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    int position = interpolationSearch(arr, size, key);

    if (position != -1) {
        printf("Element found at position: %d\n", position);
    } else {
        printf("Element not found.\n");
    }

    printf("\n");
    return 0;
}

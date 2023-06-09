// Write a recursive function to find the sum of elements in an array

#include <stdio.h>

int sumArray(int arr[], int n) {
    if (n == 0) {
        return 0;
    } else {
        return arr[n - 1] + sumArray(arr, n - 1);
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = sumArray(arr, n);
    printf("Sum of elements in the array is %d\n", result);
    return 0;
}
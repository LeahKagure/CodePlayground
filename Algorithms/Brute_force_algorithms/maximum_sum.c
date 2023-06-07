// Given an array of integers, find the maximum sum of a subarray of consecutive elements

#include <stdio.h>

int maxSubarraySum(int arr[], int size) {
    int maxSum = arr[0];
    
    for (int i = 0; i < size; i++) {
        int currentSum = 0;
        for (int j = i; j < size; j++) {
            currentSum += arr[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    
    return maxSum;
}

int main() {
    int arr[] = {1, -3, 4, 2, -1, 6, -5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int maxSum = maxSubarraySum(arr, size);
    
    printf("Maximum sum of subarray: %d\n", maxSum);
    printf("\n");
    
    return 0;
}

// Given an array of integers, find the length of the longest subarray with a sum equal to a given target value k

#include <stdio.h>

int longestSubarraySumK(int arr[], int size, int k) {
    int maxLength = 0;
    int sum = 0;
    int hash[100] = {0};

    for (int i = 0; i < size; i++) {
        sum += arr[i];

        if (sum == k) {
            maxLength = i + 1;
        }

        if (hash[sum - k] != 0) {
            if (i - hash[sum - k] + 1 > maxLength) {
                maxLength = i - hash[sum - k] + 1;
            }
        } else {
            hash[sum] = i + 1;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {3, 1, 2, -2, 4, 6, -3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int length = longestSubarraySumK(arr, size, k);

    printf("Length of longest subarray with sum %d: %d\n", k, length);
    printf("\n");
    
    return 0;
}

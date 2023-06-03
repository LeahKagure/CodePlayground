// Given an array of integers, find the contiguoug subarray with the largest sum and return the sum

#include <stdio.h>

int maxSubarraySum(int arr[], int left, int right) {
    // Base case: if the array contains only one element
    if (left == right) {
        return arr[left];
    }

    // Divide the array into two halves
    int mid = (left + right) / 2;

    // Recursively find the maximum subarray sum in the left half
    int leftMaxSum = maxSubarraySum(arr, left, mid);

    // Recursively find the maximum subarray sum in the right half
    int rightMaxSum = maxSubarraySum(arr, mid + 1, right);

    // Find the maximum subarray sum that crosses the midpoint
    int crossMaxSum = 0;
    int leftSum = -99999;  // Initialize with a very small value
    int rightSum = -99999; // Initialize with a very small value

    // Find the maximum sum of the left part of the subarray
    for (int i = mid; i >= left; i--) {
        crossMaxSum += arr[i];
        if (crossMaxSum > leftSum) {
            leftSum = crossMaxSum;
        }
    }

    crossMaxSum = 0; // Reset crossMaxSum

    // Find the maximum sum of the right part of the subarray
    for (int i = mid + 1; i <= right; i++) {
        crossMaxSum += arr[i];
        if (crossMaxSum > rightSum) {
            rightSum = crossMaxSum;
        }
    }

    // Return the maximum of the three sums
    int maxSum = (leftMaxSum > rightMaxSum) ? leftMaxSum : rightMaxSum;
    maxSum = (maxSum > (leftSum + rightSum)) ? maxSum : (leftSum + rightSum);
    return maxSum;
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, 0, n - 1);

    printf("Maximum subarray sum: %d\n", maxSum);

    printf("\n");
    return 0;
}

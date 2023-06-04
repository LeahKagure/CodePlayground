// Given an array of integers, find the total number of subarrays that sum up to a target value K

#include <stdio.h>
#include <stdlib.h>

int subarraySum(int* nums, int numsSize, int k) {
    int count = 0;
    int sum = 0;
    int* prefixSum = (int*)calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            int currentSum = prefixSum[j + 1] - prefixSum[i];
            if (currentSum == k) {
                count++;
            }
        }
    }

    free(prefixSum);
    return count;
}

int main() {
    int nums[] = {1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = subarraySum(nums, numsSize, k);
    printf("Number of subarrays with sum %d: %d\n", k, result);

    printf("\n");
    return 0;
}

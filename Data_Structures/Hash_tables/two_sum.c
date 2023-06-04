// Given an array of integers and a target value, find two numbers in the array that sum up to the target value

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Element;

int compare(const void* a, const void* b) {
    return ((Element*)a)->val - ((Element*)b)->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Element* elements = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        elements[i].val = nums[i];
        elements[i].index = i;
    }

    qsort(elements, numsSize, sizeof(Element), compare);

    int* result = (int*)malloc(2 * sizeof(int));
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int sum = elements[left].val + elements[right].val;
        if (sum == target) {
            result[0] = elements[left].index;
            result[1] = elements[right].index;
            *returnSize = 2;
            break;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    free(elements);
    return result;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);

    printf("Indices: %d, %d\n", result[0], result[1]);

    free(result);

    printf("\n");
    return 0;
}

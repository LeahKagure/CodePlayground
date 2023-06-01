// Given an array of integers, find two numbers that sum up to a given target value

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10000

bool findTwoSum(int arr[], int n, int target) {
    bool hash[MAX_SIZE] = {false};

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (complement >= 0 && hash[complement]) {
            printf("Pair found: %d + %d = %d\n", arr[i], complement, target);
            return true;
        }
        hash[arr[i]] = true;
    }

    printf("Pair not found!\n");
    return false;
}

int main() {
    int arr[] = {2, 4, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    findTwoSum(arr, n, target);

    printf("\n");
    return 0;
}

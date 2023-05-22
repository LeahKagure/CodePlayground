//Given a sorted array of integers, find the number of occurrences of a given target value

#include <stdio.h>

int countOccurrences(int arr[], int size, int target) {
    int count = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            count++;
            int i = mid - 1;
            while (i >= 0 && arr[i] == target) {
                count++;
                i--;
            }

            i = mid + 1;
            while (i < size && arr[i] == target) {
                count++;
                i++;
            }

            return count;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return count;
}

int main() {
    int arr[] = {2, 3, 5, 5, 5, 7, 8, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int count = countOccurrences(arr, size, target);

    printf("Occurrences of %d: %d\n\n", target, count);

    return 0;
}

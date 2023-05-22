//Given an array of integers, find the maximum element in an array

#include <stdio.h>

int main() {
    int arr[] = {20, 10, 40, 30, 60, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];

    for(int i=1; i<size; i++){
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Maximum element is: %d\n", max);
    return 0;
}
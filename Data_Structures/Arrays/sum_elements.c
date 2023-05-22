//Given an array of integers, find the sum of all the elements

# include <stdio.h>

int main() {
    int arr[] = {10, 20, 0, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for(int i=0; i<size; i++) {
        sum += arr[i];
    }

    printf("Sum of elements: %d\n", sum);
    return 0;
}

//Given an arrray of integers, remove all the duplicates and return a new array without duplicates
//The order of elements should be preserved

#include <stdio.h>

int main() {
    int arr[] = {2, 3, 5, 3, 2, 6, 7, 8, 7, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int unique[size];
    int unique_index = 0;

    for (int i = 0; i < size; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < unique_index; j++) {
            if (arr[i] == unique[j]) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            unique[unique_index] = arr[i];
            unique_index++;
        }
    }

    printf("Array without duplicates: ");
    for (int i = 0; i < unique_index; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n\n");

    return 0;
}

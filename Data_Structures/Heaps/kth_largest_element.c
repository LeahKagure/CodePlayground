// Given an array of integers and an integer k, find the kth largest element in the array using a heap

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int capacity;
    int size;
} MaxHeap;

MaxHeap* create_max_heap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;

    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        max_heapify(heap, largest);
    }
}

void build_max_heap(MaxHeap* heap, int* array, int size) {
    heap->size = size;
    heap->arr = array;

    for (int i = size / 2 - 1; i >= 0; i--)
        max_heapify(heap, i);
}

int find_kth_largest(int* nums, int size, int k) {
    MaxHeap* heap = create_max_heap(size);
    build_max_heap(heap, nums, size);

    int kth_largest = 0;
    for (int i = 0; i < k; i++)
        kth_largest = heap->arr[0];

    //free(heap->arr);
    free(heap);

    return kth_largest;
}

int main() {
    int nums[] = {3, 1, 4, 2, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int kth_largest = find_kth_largest(nums, size, k);
    printf("Kth largest element: %d\n", kth_largest);
    printf("\n");

    return 0;
}

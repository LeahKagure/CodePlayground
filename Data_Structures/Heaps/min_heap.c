// Create a min heap data structure and implement insertions and extraction operations

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int capacity;
    int size;
} MinHeap;

MinHeap* create_min_heap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
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

void min_heapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        min_heapify(heap, smallest);
    }
}

void insert(MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    heap->arr[heap->size++] = value;

    int index = heap->size - 1;
    while (index != 0 && heap->arr[(index - 1) / 2] > heap->arr[index]) {
        swap(&heap->arr[(index - 1) / 2], &heap->arr[index]);
        index = (index - 1) / 2;
    }
}

int extract_min(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot extract.\n");
        return -1;
    }

    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    min_heapify(heap, 0);

    return min;
}

int main() {
    MinHeap* heap = create_min_heap(10);

    insert(heap, 4);
    insert(heap, 2);
    insert(heap, 7);
    insert(heap, 5);

    printf("Extracted min: %d\n", extract_min(heap));
    printf("Extracted min: %d\n", extract_min(heap));
    printf("\n");

    free(heap->arr);
    free(heap);

    return 0;
}

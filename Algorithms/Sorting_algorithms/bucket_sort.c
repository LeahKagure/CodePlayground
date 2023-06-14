// A program to sort an array of integers using the Bucket Sort algorithm
// Assume that the input array contains integers ranging from 0 to 99

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define BUCKET_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void bucketSort(int arr[], int n) {
    // Create an array of empty buckets
    Node* buckets[BUCKET_SIZE] = { NULL };

    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / BUCKET_SIZE;
        insert(&buckets[index], arr[i]);
    }

    // Sort elements within each bucket and update the original array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[index++] = curr->data;
            curr = curr->next;
        }
    }
}

int main() {
    int arr[SIZE] = { 75, 15, 30, 45, 60, 90, 20, 10, 80, 25 };

    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, SIZE);

    printf("Sorted array using Bucket Sort:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

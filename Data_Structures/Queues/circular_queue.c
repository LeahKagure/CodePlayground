// Implement a circular queue using an array and perform enqueue and dequeue operations

#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else if (rear == MAX_SIZE - 1)
        rear = 0;
    else
        rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else if (front == MAX_SIZE - 1)
        front = 0;
    else
        front++;
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    dequeue();
    enqueue(20);
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    printf("\n");
    return 0;
}

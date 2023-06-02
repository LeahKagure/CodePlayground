// A program to implement a queue using an array and perform basic operations like enqueue and dequeue

#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
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

    printf("\n");
    return 0;
}

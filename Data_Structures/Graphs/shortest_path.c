// Find the shortest path between two vertices in an unweighted graph

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define QUEUE_SIZE 100

// Structure to represent a queue
typedef struct
{
    int front, rear;
    int elements[QUEUE_SIZE];
} Queue;

// Function to initialize a queue
void initQueue(Queue* q)
{
    q->front = q->rear = -1;
}

// Function to check if a queue is empty
bool isQueueEmpty(Queue* q)
{
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(Queue* q, int element)
{
    if (q->rear == QUEUE_SIZE - 1)
    {
        printf("Queue Overflow\n");
        exit(1);
    }

    if (q->front == -1)
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }

    q->elements[q->rear] = element;
}

// Function to dequeue an element
int dequeue(Queue* q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    int element = q->elements[q->front];

    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }

    return element;
}

// Function to find the shortest path between two vertices
int shortestPath(int graph[][MAX_VERTICES], int numVertices, int source, int destination)
{
    bool visited[MAX_VERTICES] = {false};
    int distance[MAX_VERTICES] = {INT_MAX};

    Queue q;
    initQueue(&q);

    visited[source] = true;
    distance[source] = 0;
    enqueue(&q, source);

    while (!isQueueEmpty(&q))
    {
        int currentVertex = dequeue(&q);

        for (int i = 0; i < numVertices; i++)
        {
            if (graph[currentVertex][i] && !visited[i])
            {
                visited[i] = true;
                distance[i] = distance[currentVertex] + 1;
                enqueue(&q, i);
            }
        }
    }

    return distance[destination];
}

// Driver code
int main()
{
    int graph[][MAX_VERTICES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int numVertices = 5;
    int source = 0;
    int destination = 4;

    int shortestDistance = shortestPath(graph, numVertices, source, destination);

    printf("Shortest distance between %d and %d: %d\n", source, destination, shortestDistance);

    return 0;
}

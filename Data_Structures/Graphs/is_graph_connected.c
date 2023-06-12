// Given an undirected graph, write a function to determine if it is connected
// i.e. there is a path between every pair of vertices

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to perform Depth First Search (DFS)
void DFS(int graph[][MAX_VERTICES], int numVertices, int vertex, bool visited[])
{
    visited[vertex] = true;

    for (int i = 0; i < numVertices; i++)
    {
        if (graph[vertex][i] && !visited[i])
        {
            DFS(graph, numVertices, i, visited);
        }
    }
}

// Function to check if a graph is connected
bool isConnected(int graph[][MAX_VERTICES], int numVertices)
{
    bool visited[MAX_VERTICES] = {false};

    // Perform DFS from the first vertex
    DFS(graph, numVertices, 0, visited);

    // Check if all vertices were visited
    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }

    return true;
}

// Driver code
int main()
{
    int graph[][MAX_VERTICES] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    int numVertices = 4;

    bool connected = isConnected(graph, numVertices);

    if (connected)
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
    }

    return 0;
}

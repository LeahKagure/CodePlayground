# Given an undirected graph, write a function to determine if it is connected
# i.e. there is a path between every pair of vertices

# Function to perform Depth First Search (DFS)
def DFS(graph, vertex, visited):
    visited[vertex] = True

    for i in range(len(graph[vertex])):
        if graph[vertex][i] and not visited[i]:
            DFS(graph, i, visited)

# Function to check if a graph is connected
def is_connected(graph):
    num_vertices = len(graph)
    visited = [False] * num_vertices

    # Perform DFS from the first vertex
    DFS(graph, 0, visited)

    # Check if all vertices were visited
    for i in range(num_vertices):
        if not visited[i]:
            return False

    return True

# Driver code
if __name__ == '__main__':
    graph = [
        [0, 1, 1, 0],
        [1, 0, 0, 1],
        [1, 0, 0, 1],
        [0, 1, 1, 0]
    ]

    connected = is_connected(graph)

    if connected:
        print("The graph is connected.")
    else:
        print("The graph is not connected.")


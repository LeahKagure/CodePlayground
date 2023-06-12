# Find the shortest path between two vertices in an unweighted graph

# Function to find the shortest path between two vertices
def shortest_path(graph, source, destination):
    num_vertices = len(graph)
    visited = [False] * num_vertices
    distance = [float('inf')] * num_vertices

    queue = []
    visited[source] = True
    distance[source] = 0
    queue.append(source)

    while queue:
        current_vertex = queue.pop(0)

        for i in range(num_vertices):
            if graph[current_vertex][i] and not visited[i]:
                visited[i] = True
                distance[i] = distance[current_vertex] + 1
                queue.append(i)

    return distance[destination]

# Driver code
if __name__ == '__main__':
    graph = [
        [0, 1, 1, 0, 0],
        [1, 0, 0, 1, 0],
        [1, 0, 0, 1, 1],
        [0, 1, 1, 0, 1],
        [0, 0, 1, 1, 0]
    ]

    num_vertices = 5
    source = 0
    destination = 4

    shortest_distance = shortest_path(graph, source, destination)

    print(f"Shortest distance between {source} and {destination}: {shortest_distance}")

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#include "weightedGraph.h"

int minDistance(const vector<int> &distances, const vector<bool> &visited)
{
    int minDist = INT_MAX;
    int minIndex = -1;

    for (size_t i = 0; i < distances.size(); ++i)
    {
        if (!visited[i] && distances[i] < minDist)
        {
            minDist = distances[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(const Graph &graph, int source, vector<int> &distances)
{
    int n = graph.numberOfVertices; // Number of vertices in the graph

    // Initialize distances to "infinity" or INT_MAX
    distances.assign(n, INT_MAX);
    distances[source] = 0;

    vector<bool> visited(n, false);

    for (int i = 0; i < n - 1; ++i)
    {
        int u = minDistance(distances, visited);

        visited[u] = true;

        for (const Edge &edge : graph.adjList[u])
        {
            int v = edge.to;
            int weight = edge.weight;

            if (!visited[v] && distances[u] != INT_MAX && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
            }
        }
    }
}

int main()
{
    int n = 6;
    Graph graph(n);

    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 2, 6);

    graph.addEdge(3, 4, 2);

    graph.addEdge(4, 5, 3);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 8);

    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 4, 1);
    graph.addEdge(2, 5, 9);

    int source; // Source vertex for Dijkstra's algorithm
    std::cin >> source;

    vector<int> distances; // Stores shortest distances from the source vertex
    dijkstra(graph, source, distances);

    // Print shortest distances from the source vertex
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Distance from " << source << " to " << i << " is: " << distances[i] << std::endl;
    }

    return 0;
}
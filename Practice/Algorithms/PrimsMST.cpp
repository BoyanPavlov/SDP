#include "weightedGraph.h"
using namespace std;

int minKey(const vector<int> &key, const vector<bool> &mstSet)
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < key.size(); ++v)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void primMST(const Graph &graph, int source)
{
    int n = graph.numberOfVertices;

    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);

    key[source] = 0;

    for (int count = 0; count < n - 1; ++count)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (const Edge &edge : graph.adjList[u])
        {
            int v = edge.to;
            int weight = edge.weight;

            if (!mstSet[v] && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; ++i)
    {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << endl;
    }
}

int main()
{
    int n = 6;
    Graph graph(n);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 8);

    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 2, 5);

    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 4, 1);
    graph.addEdge(2, 5, 9);

    graph.addEdge(3, 4, 2);

    graph.addEdge(4, 5, 3);

    int source = 0; // Starting vertex for Prim's algorithm
    primMST(graph, source);

    return 0;
}

#include <iostream>
using namespace std;
#include "graph.h"

void DFS(int start, Graph<int> &graph)
{
    vector<bool> visited(graph.numberOfVertices, false);
    stack<int> stack;

    stack.push(start);
    visited[start] = true;

    while (!stack.empty())
    {
        int current = stack.top();
        stack.pop();
        cout << current << " ";

        for (int neighbor : graph.adjList[current])
        {
            if (!visited[neighbor])
            {
                stack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    Graph<int> g(6); // Creating a graph with 6 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    cout << "DFS starting from vertex 0: ";
    DFS(0, g);

    return 0;
}

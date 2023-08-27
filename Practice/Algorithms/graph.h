#pragma once

#include <iostream>
#include <vector>
#include <stack>

using std::vector;

// struct for the Edges

// struct Edge
// {
//     int to;
//     int weight;
//     Edge(int _to, int _weight) : to(_to), weight(_weight) {}
// };

// Graph representation using an adjacency list
template <class T>
class Graph
{
public:
    Graph(int vertices);
    void addEdge(int u, int v);

    int numberOfVertices;
    vector<vector<T>> adjList;
};
template <class T>
Graph<T>::Graph(int vertices)
{
    numberOfVertices = vertices;
    adjList.resize(numberOfVertices);
}
template <class T>
void Graph<T>::addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Uncomment this line for undirected graph
}

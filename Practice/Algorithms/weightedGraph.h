#pragma once

#include <iostream>
#include <vector>
#include <stack>

using std::vector;

// struct for the Edges

struct Edge
{
    int to;
    int weight;
    Edge(int _to, int _weight = 0) : to(_to), weight(_weight) {}
};

// Graph representation using an adjacency list
class Graph
{
public:
    Graph(int vertices);
    void addEdge(int u, int v, int cost = 0);

    int numberOfVertices;
    vector<vector<Edge>> adjList;
};
Graph::Graph(int vertices)
{
    numberOfVertices = vertices;
    adjList.resize(numberOfVertices);
}
void Graph::addEdge(int u, int v, int cost)
{
    Edge edgeToV(v, cost);
    Edge edgeToU(u, cost);
    adjList[u].push_back(edgeToV);
    adjList[v].push_back(edgeToU); // Uncomment this line for undirected graph
}

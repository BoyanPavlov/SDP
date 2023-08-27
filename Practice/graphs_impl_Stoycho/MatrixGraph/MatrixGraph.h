#ifndef GRAPH_IMPL_H
#define GRAPH_IMPL_H

#include <vector>
#include <cstddef>

class MatrixGraph
{
public:
    using vertex_t = unsigned int;
    using weight_t = unsigned int;

private:
    std::vector<std::vector<weight_t>> data;

public:
    MatrixGraph(size_t);

    void addVertex();
    void removeVertex(vertex_t);

    void addDirectedEdge(vertex_t from, vertex_t to, weight_t w);
    void addEdge(vertex_t from, vertex_t to, weight_t w);
    void removeEdge(vertex_t from, vertex_t to);

    bool validVertex(vertex_t) const;
    weight_t getWeight(vertex_t, vertex_t) const;

    size_t vertexCount() const;
    bool adjacent(vertex_t from, vertex_t to) const;

    std::vector<vertex_t> getSuccessors(vertex_t) const;
    std::vector<vertex_t> getPredecessors(vertex_t) const;
    // Same as getSuccessors, here for interface purposes.
    std::vector<vertex_t> adjacent(vertex_t) const;
};

#endif
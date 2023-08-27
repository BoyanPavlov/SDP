#include <iostream>
#include <vector>
#include "graph.h"
using std::cin;
using std::cout;
using std::exception;
using std::vector;

// Implementation of Linked Queue
#pragma region Queue
template <class T>
struct Element
{
    T data;
    Element<T> *next;
    Element<T> &operator=(const Element &other)
    {
        if (this != &other)
        {
            delete next;
            next = new Element(other.next->data, nullptr);
            data = other.data;
        }
        return *this;
    }
    Element(T const &_data, Element<T> *_next = nullptr)
        : data(_data),
          next(_next)
    {
    }
};

template <class T>
class Queue
{
private:
    void clear();
    void copy(const Queue<T> &other);

public:
    Queue();
    Queue(const Queue<T> &other);
    Queue &operator=(const Queue<T> &other);
    ~Queue();

    bool empty() const;
    void enqueue(const T &element);
    T dequeue();
    const T &head() const;
    T &head();

private:
    Element<T> *front;
    Element<T> *back;
};

template <class T>
Queue<T>::Queue()
    : front(nullptr), back(nullptr)
{
}

template <class T>
Queue<T>::~Queue()
{
    clear();
}

template <class T>
Queue<T>::Queue(const Queue<T> &other)
{
    copy(other);
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template <class T>
void Queue<T>::clear()
{
    while (!empty())
    {
        dequeue();
    }
}

template <class T>
void Queue<T>::copy(const Queue<T> &other)
{
    if (other.front != nullptr)
    {
        front = new Element<T>(other.front->data, nullptr);
        back = front;
        Element<T> *nextCopy = other.front->next;
        while (nextCopy)
        {
            back->next = new Element<T>(nextCopy->data, nullptr);
            back = back->next;
            nextCopy = nextCopy->next;
        }
    }
    else
    {
        front = back = nullptr;
    }
}

template <class T>
bool Queue<T>::empty() const
{
    return front == nullptr;
}

template <class T>
void Queue<T>::enqueue(const T &element)
{
    Element<T> *newElement = new Element<T>(element);
    if (empty())
    {
        front = newElement;
    }
    else
    {
        back->next = newElement;
    }

    back = newElement;
}

template <class T>
T Queue<T>::dequeue()
{
    if (!front)
    {
        throw std::runtime_error("Queue is already empty\n");
    }

    if (front == back)
    {
        back = nullptr;
    }

    Element<T> *toDel = front;
    T data = front->data;
    front = front->next;
    delete toDel;

    return data;
}

template <class T>
const T &Queue<T>::head() const
{
    if (!front)
    {
        throw std::runtime_error("Queue is empty\n");
    }
    return *front;
}

template <class T>
T &Queue<T>::head()
{
    if (!front)
    {
        throw std::runtime_error("Queue is empty\n");
    }
    return *front;
}

#pragma endregion

// Function to perform Breadth-First Search

void BFS(Graph<int> graph, int startNode)
{
    int numNodes = graph.numberOfVertices;
    vector<bool> visited(numNodes, false);

    Queue<int> q;
    q.enqueue(startNode);
    visited[startNode] = true;

    while (!q.empty())
    {
        int currentNode = q.dequeue();
        cout << currentNode << " ";

        for (int neighbor : graph.adjList[currentNode])
        {
            if (!visited[neighbor])
            {
                q.enqueue(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    Graph<int> g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    cout << "DFS starting from vertex 0: ";

    cout << "BFS traversal starting from node " << 0 << ": ";
    BFS(g, 0);

    return 0;
}

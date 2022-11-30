#ifndef __SQUEUE_HPP
#define __SQUEUE_HPP
#include <cstddef>
#include <stdexcept>
#include "abstractQueue.hpp"

template <typename DataType>
class StaticQueue : public AbstractQueue<DataType>
{
private:
    static const size_t SIZE = 100;
    DataType queue[SIZE];
    int front;
    int back;

    bool full() const
    {
        return (back + 2) % SIZE == front;
    }

public:
    // създава празна опашка
    StaticQueue() : front(0), back(-1) {}

    StaticQueue<DataType> &operator=(const StaticQueue<DataType> &other);

    /// checks if queue is empty
    virtual bool empty() const;

    /// adds to the queue one more element
    virtual void enqueue(DataType const &);

    /// returns the last added element and removes it from the queue
    virtual DataType dequeue();

    /// access the first element
    virtual DataType const &head() const;

    // access the first element and letting the user to change it
    virtual DataType &head();
};

template <class DataType>
StaticQueue<DataType> &StaticQueue<DataType>::operator=(const StaticQueue<DataType> &other)
{
    if (this != &other)
    {
        front = back = 0;
        for (int pos = other.front; pos != other.end; pos = (pos + 1) % SIZE)
        {
            enqueue(other.data[pos]);
        }
    }
    return *this;
}

template <class DataType>
bool StaticQueue<DataType>::empty() const
{
    return back < front;
}

template <class DataType>
void StaticQueue<DataType>::enqueue(DataType const &element)
{
    if (full())
    {
        throw std::runtime_error("Queue is already full, sorry\n");
    }
    queue[++back % SIZE] = element;
}

template <class DataType>
DataType StaticQueue<DataType>::dequeue()
{
    if (empty())
    {
        throw std::runtime_error("Attempt of extracting element from empty Queue\n");
    }
    DataType result = queue[front];
    // front %= SIZE  <---> front = (front == SIZE) ? 0 : front;
    ++front %= SIZE;
    return result;
}

template <class DataType>
DataType const &StaticQueue<DataType>::head() const
{
    if (empty())
    {
        throw std::runtime_error("An attempt of peeking from empty queue\n");
    }

    return queue[front];
}

template <class DataType>
DataType &StaticQueue<DataType>::head()
{
    if (empty())
    {
        throw std::runtime_error("An attempt of peeking from empty queue\n");
    }

    return queue[front];
}

#endif
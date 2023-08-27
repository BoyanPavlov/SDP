#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#include <iostream>
#include "abstractQueue.hpp"

template <class DataType>
struct QueueElement
{
    DataType data;
    QueueElement *next;

    // QueueElement()
    // // : data(NULL), next(nullptr)
    // {
    // }

    // QueueElement(DataType _data, QueueElement<DataType> *_next)
    //     : data(_data), next(_next)
    // {
    // }

    QueueElement<DataType> &operator=(const QueueElement<DataType> &other)
    {
        if (this != &other)
        {
            delete next;
            data = other.data;
            next = new QueueElement<DataType>(other.next->data, nullptr);
        }
        return this;
    }
    QueueElement(T const &_data, QueueElement<DataType> *_next = nullptr)
        : data(_data),
          next(_next)
    {
    }
};

template <class DataType>
class LinkedQueue : public AbstractQueue<DataType>
{
private:
    QueueElement<DataType> *front;
    QueueElement<DataType> *back;
    // front == nullptr && back == nullptr || front != nullptr && back != nullptr

    void copy(const LinkedQueue<DataType> &other);

    void erase();

public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue<DataType> &other);
    LinkedQueue<DataType> &operator=(const LinkedQueue<DataType> &other);
    ~LinkedQueue();

    virtual bool empty() const override;

    virtual void enqueue(const DataType &other) override;

    virtual DataType dequeue() override;

    virtual const DataType &head() const override;

    virtual DataType &head() override;
};

template <class DataType>
bool LinkedQueue<DataType>::empty() const
{
    return front == nullptr;
}

template <class DataType>
LinkedQueue<DataType>::LinkedQueue()
    : front(nullptr), back(nullptr)
{
}

template <class DataType>
LinkedQueue<DataType>::~LinkedQueue()
{
    erase();
}

template <class DataType>
LinkedQueue<DataType> &LinkedQueue<DataType>::operator=(const LinkedQueue<DataType> &other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }
    return *this;
}

template <class DataType>
LinkedQueue<DataType>::LinkedQueue(const LinkedQueue<DataType> &other)
{
    copy(other);
}

template <class DataType>
void LinkedQueue<DataType>::copy(const LinkedQueue<DataType> &other)
{
    /*
    !!!
    while (!other.empty())
        enqueue(other.dequeue());
    */

    if (other.front != nullptr)
    {
        front = new QueueElement<DataType>{other.front->data, nullptr};
        back = front;
        QueueElement<DataType> *nextCopy = other.front->next;
        while (nextCopy)
        {
            back->next = new QueueElement<DataType>{nextCopy->data, nullptr};
            back = back->next;
            nextCopy = nextCopy->next;
        }
    }
    else
    {
        front = back = nullptr;
    }
}

template <class DataType>
void LinkedQueue<DataType>::erase()
{
    while (!empty())
    {
        dequeue();
    }
}

template <class DataType>
void LinkedQueue<DataType>::enqueue(const DataType &other)
{
    QueueElement<DataType> *newElement = new QueueElement<DataType>{other};
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

template <class DataType>
DataType LinkedQueue<DataType>::dequeue()
{
    if (empty())
    {
        throw std::runtime_error("An attempt of excluding of empty queue\n");
    }

    if (front == back)
    {
        back = nullptr;
    }

    QueueElement<DataType> *oldElement = front;
    front = front->next;
    DataType result = oldElement->data;
    delete oldElement;
    return result;
}

template <class DataType>
const DataType &LinkedQueue<DataType>::head() const
{
    if (empty())
    {
        throw std::runtime_error("An attempt of extracting from empty queue\n");
    }
    return front->data;
}

template <class DataType>
DataType &LinkedQueue<DataType>::head()
{
    if (empty())
    {
        throw std::runtime_error("An attempt of extracting from empty queue\n");
    }
    return front->data;
}

#endif // _LINKED_QUEUE_
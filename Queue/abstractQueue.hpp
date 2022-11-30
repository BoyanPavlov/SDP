#ifndef _QUEUE_
#define _QUEUE_

template <class DataType>
class AbstractQueue
{
private:
public:
    /// checks if queue is empty
    virtual bool empty() const = 0;

    /// adds to the queue one more element
    // virtual void push_back(DataType const &) = 0;
    virtual void enqueue(DataType const &) = 0;

    /// returns the last added element and removes it from the queue
    // virtual DataType pop_front() const = 0;
    virtual DataType dequeue() = 0;

    /// access the first element
    // virtual DataType &front() = 0;
    virtual DataType const &head() const = 0;
    // access the first element and letting the user to change it
    virtual DataType &head() = 0;

    virtual ~AbstractQueue() {}

    /// returns the size of the queue
    // virtual int size() const = 0;

    /// constructs element in-place at the end
    // virtual void emplace(DataType &&) = 0;

    /// access the last element
    // virtual DataType &back() = 0;
};
#endif //_QUEUE_
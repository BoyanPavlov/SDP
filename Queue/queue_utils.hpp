#ifndef _QUEUE_UTILS_
#define _QUEUE_UTILS_

#include "abstractQueue.hpp"
#include <iostream>

template <class DataType>
class QueueUtils
{
private:
    /* data */
public:
    static const DataType &extractMin(AbstractQueue<DataType> &givenQueue)
    {
        if (givenQueue.empty())
        {
            throw std::runtime_error("An attempt of excluding of empty queue\n");
        }
        DataType min = givenQueue.dequeue();

        DataType sentinel = DataType();
        givenQueue.enqueue(sentinel);

        while (givenQueue.head() != sentinel)
        {
            DataType current = givenQueue.dequeue();
            if (current < min)
            {
                std::swap(min, current);
            }
            givenQueue.enqueue(current);
        }
        // head() == sentinel
        givenQueue.dequeue();
        return min;
    }

    static void sortQueue(AbstractQueue<DataType> &input, AbstractQueue<DataType> &result)
    {
        if (!result.empty())
        {
            std::runtime_error("Must be givn empty queue\n");
        }
        while (!input.empty())
        {
            result.enqueue(extractMin(input));
        }
    }
};

#endif // _QUEUE_UTILS_
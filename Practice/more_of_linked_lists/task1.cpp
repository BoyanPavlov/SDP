#include <iostream>

template <class T>
struct LinkedListNode
{
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(const T &elem, LinkedListNode<T> *node = nullptr)
        : data(elem), next(node)
    {
    }
};

template <class T>
LinkedListNode<T> *findMiddle(LinkedListNode<T> *ll)
{
    LinkedListNode<T> *mid = ll;
    int count = 0;
    while (ll)
    {
        if (count % 2 == 1)
        {
            mid = mid->next;
        }
        ll = ll->next;
        count++;
    }
    return mid;
}
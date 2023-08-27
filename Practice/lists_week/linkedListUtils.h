#ifndef _LINKED_LIST_UTILS_
#define _LINKED_LIST_UTILS_
#include <iostream>
#include <initializer_list>

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
void printLinkedList(const LinkedListNode<T> *ll)
{
    const LinkedListNode<T> *iterate = ll;
    while (iterate)
    {
        std::cout << iterate->data << ' ';
        iterate = iterate->next;
    }
    std::cout << std::endl;
}

template <class T>
void printLinkedList(const LinkedListNode<T> *ll, void (*print)(T)) //??????
{
    const LinkedListNode<T> *iterate = ll;

    while (iterate)
    {
        print(iterate->data);
        iterate = iterate->next;
    }

    std::cout << std::endl;
}

template <class T>
LinkedListNode<T> *fromList(const std::initializer_list<T> &l)
{
    LinkedListNode<T> *toReturn = nullptr;
    LinkedListNode<T> *iter = nullptr;

    // for (const LinkedListNode<T> *elem : l)
    for (const auto &elem : l)
    {
        LinkedListNode<T> *toInsert = new LinkedListNode<T> *(elem);
        if (iter == nullptr)
        {
            toReturn = toInsert;
            iter = toInsert;
        }
        else
        {
            iter->next = toInsert;
            iter = iter->next;
        }
    }
    return toReturn;
}

template <class T>
void freeList(LinkedListNode<T> *ll)
{
    LinkedListNode<T> *toDel = nullptr;
    while (ll)
    {
        toDel = ll;
        ll = ll->next;
        delete toDel;
    }
}

// new functions added
template <class T>
void insertAtTheBeggining(const T &elem, LinkedListNode<T> *&ll)
{
    LinkedListNode<T> *toInsert = new LinkedListNode<T>(elem, ll);
    ll = toInsert;
}

template <class T>
void reverseLinkedList(LinkedListNode<T> *&ll)
{
    LinkedListNode<T> *prev = nullptr;
    LinkedListNode<T> *current = ll;
    LinkedListNode<T> *next = nullptr;

    while (current)
    {
        next = current->next; // save where the next goes
        current->next = prev; // reverse the list - we are going backwards
        prev = current;       // the previous becomes where we are sitting now
        current = next;       // let's get to the next elemet to process
    }
    ll = prev;
}

template <class T>
LinkedListNode<T> *findMiddle(LinkedListNode<T> *ll)
{
    int count = 0;
    LinkedListNode<T> *mid = ll;
    while (ll)
    {
        if (count % 2 == 1)
        {
            mid = mid->next;
        }
        count++;
        ll = ll->next;
    }
    return mid;
}

template <class T>
LinkedListNode<T> *mergeLists(LinkedListNode<T> *first, LinkedListNode<T> *second)
{
    if (!first)
    {
        return second;
    }

    if (!second)
    {
        return first;
    }

    LinkedListNode<T> *result = first;
    LinkedListNode<T> *iter = first;

    while (iter->next)
    {
        iter = iter->next;
    }
    iter->next = second;
    return result;
}

#endif // _LINKED_LIST_UTILS_
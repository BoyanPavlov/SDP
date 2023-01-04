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
LinkedListNode<T> *_findMiddle(LinkedListNode<T> *ll)
{
    LinkedListNode<T> *mid = ll;
    int count = 0;
    while (ll)
    {
        if (count % 2 == 0)
        {
            mid = mid->next;
        }
        ll = ll->next;
        count++;
    }
    return mid;
}

template <class T>
void reverseLinkedList(LinkedListNode<T> *&ll)
{
    LinkedListNode<T> *prev = nullptr;
    LinkedListNode<T> *curr = ll;
    LinkedListNode<T> *next = nullptr;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    ll = prev;
}

template <class T>
void printLinkedList(LinkedListNode<T> *ll)
{
    while (ll)
    {
        std::cout << ll->data << " ";
        ll = ll->next;
    }
    std::cout << '\n';
}

template <class T>
LinkedListNode<T> *mergeLists(LinkedListNode<T> *first, LinkedListNode<T> *second)
{
    LinkedListNode<T> *iter = first;
    LinkedListNode<T> *result = iter;

    if (!first)
    {
        return second;
    }
    if (!second)
    {
        return first;
    }

    while (iter->next)
    {
        iter = iter->next;
    }
    iter->next = second;

    return result;
}

template <class T>
void reorder(LinkedListNode<T> *&first, LinkedListNode<T> *second)
{
    LinkedListNode<int> *result = first;
    LinkedListNode<int> *iter = result;

    while (iter->next != second)
    {
        iter = iter->next;
    }
    iter->next = nullptr;

    reverseLinkedList(second);
    first = mergeLists(second, result);
}

int main(int argc, char const *argv[])
{
    LinkedListNode<int> *ll = new LinkedListNode<int>(1, new LinkedListNode<int>(
                                                             2, new LinkedListNode<int>(
                                                                    3, new LinkedListNode<int>(
                                                                           4, new LinkedListNode<int>(
                                                                                  5, new LinkedListNode<int>(
                                                                                         6, new LinkedListNode<int>(
                                                                                                7, nullptr)))))));

    LinkedListNode<int> *mid = _findMiddle(ll);
    reorder(ll, mid);
    printLinkedList(ll);
    return 0;
}

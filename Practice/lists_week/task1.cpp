#include <iostream>
#include "linkedListUtils.h"

/// added to Utils
// template <class T>
// void insertAtTheBeggining(const T &elem, LinkedListNode<T> *&ll)
// {
//     LinkedListNode<T> *toInsert = new LinkedListNode<T>(elem, ll);
//     ll = toInsert;
// }

int main()
{
    LinkedListNode<int> *ll = new LinkedListNode<int>(1, new LinkedListNode<int>(
                                                             2, new LinkedListNode<int>(
                                                                    3, nullptr)));
    printLinkedList(ll);
    insertAtTheBeggining(7, ll);
    printLinkedList(ll);
    freeList(ll);
    return 0;
}

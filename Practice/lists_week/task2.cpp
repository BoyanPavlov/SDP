#include <iostream>
#include "linkedListUtils.h"

//added to utils
// template <class T>
// void reverseLinkedList(LinkedListNode<T> *&ll)
// {
//     LinkedListNode<T> *prev = nullptr;
//     LinkedListNode<T> *current = ll;
//     LinkedListNode<T> *next = nullptr;
//
//     while (current)
//     {
//         next = current->next; // save where the next goes
//         current->next = prev; // reverse the list - we are going backwards
//         prev = current;       // the previous becomes where we are sitting now
//         current = next;       // let's get to the next elemet to process
//     }
//     ll = prev;
// }

int main()
{
    LinkedListNode<int> *ll = new LinkedListNode<int>(1, new LinkedListNode<int>(
                                                             2, new LinkedListNode<int>(
                                                                    3, new LinkedListNode<int>(
                                                                           4, nullptr))));
    printLinkedList(ll);
    reverseLinkedList(ll);
    printLinkedList(ll);

    freeList(ll);
    return 0;
}

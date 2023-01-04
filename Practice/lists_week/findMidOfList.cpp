#include <iostream>
#include "linkedListUtils.h"

// my preferable version
// template <class T>
// LinkedListNode<T> *findMiddle(LinkedListNode<T> *ll)
// {
//     int count = 0;
//     LinkedListNode<T> *mid = ll;
//     while (ll)
//     {
//         if (count % 2 == 1)
//         {
//             mid = mid->next;
//         }
//         count++;
//         ll = ll->next;
//     }
//     return mid;
// }

// same logic but more complex for the reader and using pointers
template <class T>
LinkedListNode<T> *findMiddle2(LinkedListNode<T> *ll)
{
    LinkedListNode<T> *fast = ll;
    LinkedListNode<T> *slow = ll;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    LinkedListNode<int> *ll = new LinkedListNode<int>(1, new LinkedListNode<int>(
                                                             2, new LinkedListNode<int>(
                                                                    3, new LinkedListNode<int>(
                                                                           4, new LinkedListNode<int>(
                                                                                  5, new LinkedListNode<int>(
                                                                                         6, new LinkedListNode<int>(
                                                                                                7, new LinkedListNode<int>(
                                                                                                       8, nullptr))))))));
    printLinkedList(ll);
    // printLinkedList(findMiddle(ll));
    printLinkedList(findMiddle2(ll));

    freeList(ll);
    return 0;
}

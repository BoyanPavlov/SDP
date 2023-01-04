#include <iostream>
#include "linkedListUtils.h"

template <class T>
LinkedListNode<T> *mergeListsInSpecialOrder(LinkedListNode<T> *first, LinkedListNode<T> *second)
{
    LinkedListNode<T> *result = first;
    LinkedListNode<T> *iter = nullptr;
    int counter = 0;

    while (first && second)
    {
        LinkedListNode<T> *&toInsert = (counter % 2 == 0) ? first : second;
        if (iter == nullptr)
        {
            iter = toInsert;
        }
        else
        {
            iter->next = toInsert;
            iter = iter->next;
        }
        toInsert = toInsert->next;

        counter++;
    }

    LinkedListNode<T> *rest = (first == nullptr) ? second : first;
    if (iter)
    {
        while (rest != nullptr)
        {
            iter->next = rest;
            iter = iter->next;
            rest = rest->next;
        }
    }
    return result;
}


 template <class T>
 LinkedListNode<T> *mergeListsInSpecialOrder2(LinkedListNode<T> *first, LinkedListNode<T> *second)
 {
     LinkedListNode<T> *result = nullptr;
     LinkedListNode<T> *iter = nullptr;

     while (first || second)
     {
         if (first)
         {
             if (result == nullptr)
             {
                 result = first;
                 iter = result;
             }
             else
             {
                 iter->next = first;
                 iter = iter->next;
             }
             first = first->next;
         }
         if (second)
         {
             if (result == nullptr)
             {
                 result = second;
                 iter = result;
             }
             else
             {
                 iter->next = second;
                 iter = iter->next;
             }
             second = second->next;
         }
     }
     return result;
 }

template <class T>
LinkedListNode<T> *reorderLinkedList(LinkedListNode<T> *first, LinkedListNode<T> *second)
{
    LinkedListNode<T> *iter = first;
    // separating the first part of the list from the second
    while (iter->next != second)
    {
        iter = iter->next;
    }

    iter->next = nullptr;
    reverseLinkedList(second);

    // LinkedListNode<T> *result = mergeListsInSpecialOrder(first, second);
    LinkedListNode<T> *result = mergeListsInSpecialOrder2(first, second);

    printLinkedList(result);
    return result;
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

    LinkedListNode<int> *middleOfList = findMiddle(ll);
    //// reverseLinkedList(middleOfList); // this fucks up the original ll, so do it in a function =D
    // printLinkedList(middleOfList);
    // printLinkedList(ll);

    printLinkedList(reorderLinkedList(ll, middleOfList));
    printLinkedList(ll);

    freeList(ll);
    return 0;
}
// Expected output:
//  1 8 2 7 3 6 4 5
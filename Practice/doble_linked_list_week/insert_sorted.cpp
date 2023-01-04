#include <iostream>
#include "../lists_week/linkedListUtils.h"

template <class T>
void insertSorted(LinkedListNode<T> *&ll, const T &elem)
{
    LinkedListNode<T> *toInsert = new LinkedListNode(elem);

    if (!ll)
    {
        ll = toInsert;
    }
    else if (ll->data > elem)
    { // Елементът е по - малък от всички
        toInsert->next = ll;
        ll = toInsert;
    }
    else if (ll->next == nullptr)
    { // Списъкът е от един елемент и елементът не стои в началото (ако стоеше щяхме да сме в сл2)
        ll->next = toInsert;
    }
    else
    { // Елементът може да е в средата или в края
        LinkedListNode<T> *it = ll;

        while (it->next != nullptr)
        {
            if (it->next->data > elem)
            { // Намерена е позицията на елемента
                LinkedListNode<T> *nNext = it->next;
                it->next = toInsert;
                toInsert->next = nNext;
                return;
            }

            it = it->next;
        }

        it->next = toInsert; // Ако сме стигнали до тук то мястото на елемента е в края на списъка
    }
}
int main()
{
    LinkedListNode<int> *ll = new LinkedListNode<int>(1, new LinkedListNode<int>(
                                                             3, new LinkedListNode<int>(
                                                                    2, new LinkedListNode<int>(
                                                                           7, new LinkedListNode<int>(
                                                                                  6, new LinkedListNode<int>(
                                                                                         5, new LinkedListNode<int>(
                                                                                                8, nullptr)))))));

    printLinkedList(ll);
    insertSorted(ll, 4);
    insertSorted(ll, 3);
    printLinkedList(ll);

    return 0;
}

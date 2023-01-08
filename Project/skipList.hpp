#ifndef _SKIP_LIST_HPP_
#define _SKIP_LIST_HPP_

#include <iostream>
// Some of the code below is taken from
// github (Link lists) and modified as skipList

template <class T>
struct SkipListNode
{
    T data;
    SkipListNode *next;
    SkipListNode *jumpNode;
    SkipListNode(const T &elem, SkipListNode *n, SkipListNode *jN = nullptr)
        : data(elem), next(n), jumpNode(jN) {}
};

template <class T>
class SkipList
{
private:
    void free();
    void copy(const SkipList<T> &);

    SkipListNode<T> *head;
    SkipListNode<T> *tail;
    size_t sizeOfList;

public:
    class Iterator
    {
    private:
        SkipListNode<T> *currentNode;

        // constr in private so - if we make friends with SkipList
        // - only SkipList can call the iterator
        Iterator(SkipListNode<T> *arg)
            : currentNode(arg) {}

    public:
        Iterator &operator++()
        {
            if (currentNode == nullptr)
            {
                return *this;
            }
            currentNode = currentNode->next;
            return *this;
        }

        Iterator &operator++(int)
        {
            return ++(*this);
        }

        T &operator*()
        {
            return currentNode->data;
        }

        const T &operator*() const
        {
            return currentNode->data;
        }

        bool operator==(const Iterator &other) const
        {
            return other.currentNode == currentNode;
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }

        const Iterator next() const
        {
            return Iterator(currentNode->jumpNode);
        }

        // Don't need that anymore
        //  void addJumpingNode(const SkipListNode<T> *jNode)
        //  {
        //      this->currentNode->jumpNode = jNode;
        //  }

        SkipListNode<T> *&getNode()
        {
            return currentNode;
        }

        const SkipListNode<T> *&getNode() const
        {
            return currentNode;
        }

        friend class SkipList;
    };

    class ConstIterator
    {
    private:
        const SkipListNode<T> *currentNode;

        // constr in private so - if we make friends with SkipList
        // - only SkipList can call the iterator
        ConstIterator(SkipListNode<T> *arg)
            : currentNode(arg) {}

    public:
        ConstIterator &operator++()
        {
            if (currentNode == nullptr)
            {
                return *this;
            }
            currentNode = currentNode->next;
            return *this;
        }

        ConstIterator &operator++(int)
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        T &operator*()
        {
            return currentNode->data;
        }

        const T &operator*() const
        {
            return currentNode->data;
        }

        bool operator==(const ConstIterator &other) const
        {
            return other.currentNode == currentNode;
        }

        bool operator!=(const ConstIterator &other) const
        {
            return !(*this == other);
        }

        const ConstIterator next() const
        {
            return ConstIterator(currentNode->jumpNode);
        }

        SkipListNode<T> *&getNode()
        {
            return currentNode;
        }

        const SkipListNode<T> *&getNode() const
        {
            return currentNode;
        }

        friend class SkipList;
    };

    SkipList();

    SkipList(const SkipList<T> &);
    SkipList(SkipList<T> &&);

    SkipList &operator=(const SkipList<T> &);
    SkipList &operator=(SkipList<T> &&);

    void pushBack(const T &);
    void popBack();

    void pushFront(const T &);
    void popFront();

    const T &front() const;
    const T &back() const;

    T &front();
    T &back();

    bool empty() const;
    size_t size() const;

    ~SkipList();

    // bool resetIterator()
    // {
    //     return it = this->begin();
    // }

    void resetIterator()
    {
        it = this->begin();
    }

    Iterator getIterator()
    {
        return it;
    }

    ConstIterator getConstIterator()
    {
        return c_it;
    }

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    ConstIterator begin() const
    {
        return ConstIterator(head);
    }

    ConstIterator end() const
    {
        return ConstIterator(nullptr);
    }

    ConstIterator cbegin() const
    {
        return ConstIterator(head);
    }

    ConstIterator cend() const
    {
        return ConstIterator(nullptr);
    }

private:
    Iterator it;
    ConstIterator c_it;
};

template <class T>
SkipList<T>::SkipList()
    : head{nullptr}, tail{nullptr}, sizeOfList{0}, it(head), c_it(head) {}

template <class T>
void SkipList<T>::free()
{
    while (head)
    {
        SkipListNode<T> *toDelete = head;
        head = head->next;
        delete toDelete;
    }
    sizeOfList = 0;
}

template <class T>
void SkipList<T>::copy(const SkipList<T> &other)
{
    // free();
    //  we are expecting that our list is empty
    if (!empty())
    {
        throw std::logic_error("Our list is not empty\n");
    }

    SkipListNode<T> *iter = other.head;
    while (iter)
    {
        pushBack(iter->data);
        iter = iter->next;
    }

    sizeOfList = other.sizeOfList;
}

template <class T>
SkipList<T>::SkipList(const SkipList<T> &other)
    : head{nullptr}, tail{nullptr}
{
    copy(other);
}

template <class T>
SkipList<T>::SkipList(SkipList<T> &&other)
{
    head = other.head;
    tail = other.tail;
    sizeOfList = other.sizeOfList;

    other.head = other.tail = nullptr;
    other.sizeOfList = 0;
}

template <class T>
SkipList<T> &SkipList<T>::operator=(const SkipList<T> &other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

template <class T>
SkipList<T> &SkipList<T>::operator=(SkipList<T> &&other)
{
    if (this != &other)
    {
        free();

        head = other.head;
        tail = other.tail;
        sizeOfList = other.sizeOfList;

        other.head = other.tail = nullptr;
        other.sizeOfList = 0;
    }
    return *this;
}

template <class T>
void SkipList<T>::pushBack(const T &elem)
{
    SkipListNode<T> *toInsert = new SkipListNode<T>(elem, tail);
    ++sizeOfList;

    if (empty())
    {
        head = tail = toInsert;
    }
    else
    {
        tail->next = toInsert;
        tail = toInsert;
        tail->next = nullptr;
    }
}

template <class T>
void SkipList<T>::popBack()
{
    if (empty())
    {
        throw std::runtime_error("Popping out of empty lis!");
    }
    --sizeOfList;

    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        SkipListNode<T> *newTail = head;

        // O(n) за n дължината на свързания списък
        while (newTail->next != tail)
        {
            newTail = newTail->next;
        }

        delete tail;
        tail = newTail;
        tail->next = nullptr;
    }
}

template <class T>
void SkipList<T>::pushFront(const T &elem)
{
    SkipListNode<T> *toInsert = new SkipListNode(elem, head);

    if (empty())
    {
        tail = toInsert;
    }

    head = toInsert;

    ++sizeOfList;
}

template <class T>
void SkipList<T>::popFront()
{
    if (empty())
    {
        throw std::runtime_error("Popping out of empty list!");
    }

    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        SkipListNode<T> *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    --sizeOfList;
}

template <class T>
bool SkipList<T>::empty() const
{
    return head == nullptr;
}

template <class T>
size_t SkipList<T>::size() const
{
    return sizeOfList;
}

template <class T>
const T &SkipList<T>::front() const
{
    if (empty())
    {
        throw std::runtime_error("Empty list!");
    }

    return head->data;
}

template <class T>
T &SkipList<T>::front()
{
    if (empty())
    {
        throw std::runtime_error("Empty list!");
    }

    return head->data;
}

template <class T>
const T &SkipList<T>::back() const
{
    if (empty())
    {
        throw std::runtime_error("Empty list!");
    }

    return tail->data;
}

template <class T>
T &SkipList<T>::back()
{
    if (empty())
    {
        throw std::runtime_error("Empty list!");
    }

    return tail->data;
}

template <class T>
SkipList<T>::~SkipList()
{
    free();
}

#endif //_SKIP_LIST_HPP_
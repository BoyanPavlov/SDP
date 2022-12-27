#ifndef _DOUBLE_LINKED_LIST_
#define _DOUBLE_LINKED_LIST_

#include "abstractList.hpp"

template <class DataType>
struct DoubleLinkedListElement
{
    DataType data;
    DoubleLinkedListElement *next;
    DoubleLinkedListElement *prev;
    DoubleLinkedListElement(DataType const &_data,
                            DoubleLinkedListElement *_next = nullptr,
                            DoubleLinkedListElement *_prev = nullptr)
        : data(_data), next(_next), prev(_prev) {}
};

template <class DataType>
class DoubleLinkedList;

template <class DataType>
class DoubleLinkedListIterator : public Position<DataType, DoubleLinkedListIterator<DataType>>
{
private:
    DoubleLinkedListElement<DataType> *ptr;
    friend class DoubleLinkedList<DataType>;

public:
    DoubleLinkedListIterator(DoubleLinkedListElement<DataType> *_ptr = nullptr)
        : ptr(_ptr)
    {
    }

    bool valid() const
    {
        return ptr != nullptr;
    }

    const DataType &get() const
    {
        if (!valid())
        {
            throw std::runtime_error("Usage of invalid pos!");
        }
        return ptr->data;
    }

    DataType &get()
    {
        if (!valid())
        {
            throw std::runtime_error("Usage of invalid pos!");
        }
        return ptr->data;
    }

    DoubleLinkedListIterator next() const
    {
        if (!valid())
        {
            throw std::runtime_error("An attempt of accessing bad position\n");
        }
        return ptr->next;
    }

    DoubleLinkedListIterator prev() const
    {
        if (!valid())
        {
            throw std::runtime_error("An attempt of accessing bad position\n");
        }
        return ptr->prev;
    }

    bool operator==(Position<DataType, DoubleLinkedListIterator> const &pos)
    {
        // We are not checkng if pos is an obj from Iterator
        return ptr == ((DoubleLinkedListIterator const &)pos).ptr;
    }
};

template <class DataType>
class DoubleLinkedList : public AbstractList<DataType, DoubleLinkedListIterator<DataType>>
{
public:
    using I = DoubleLinkedListIterator<DataType>;
    using E = DoubleLinkedListElement<DataType>;

private:
    E *front, *back;

public:
    // TODO Big 4
    DoubleLinkedList() : front(nullptr), back(nullptr)
    {
    }

    DoubleLinkedList(DoubleLinkedList const &other)
        : front(nullptr), back(nullptr)
    {
        this->append(other);
    }

    DoubleLinkedList &operator=(DoubleLinkedList const &other)
    {
        if (this != &other)
        {
            this->erase();
            append(other);
        }
        return *this;
    }

    ~DoubleLinkedList()
    {
        this->erase();
    }

    bool insertBefore(DataType const &x, I const &pos)
    {
        if (this->empty())
            // искаме позицията да е невалидна понеже списъкът е празен
            assert(!pos.valid());

        if (pos.ptr == front)
        {
            // специална реализация за вмъкване в началото
            front = new E{x, front};
            return true;
        }
        return insertAfter(x, findPrev(pos))
    }

    bool insertAt(DataType const &x, I const &pos);

    bool insertAfter(DataType const &x, I const &pos)
    {
        if (this->empty())
        {
            // включване в празен списък
            front = back = new E(x);
            return true;
        }
        pos.ptr->next = new E(x, pos.ptr->next);
        if (pos.ptr == back)
            // трябва да обновим back, понеже вмъкваме след последния елемент
            back = back->next;
        return true;
    }

    bool deleteBefore(DataType &x, I const &pos)
    {
        if (this->empty())
            return false;
        if (pos.ptr == front)
            // опит за изтриване преди първия елемент
            return false;
        I prev = findPrev(pos);
        return deleteAt(x, prev);
    }
    bool deleteAt(DataType &x, I &pos)
    {
        if (this->empty())
            return false;
        if (!pos.valid())
            // опит за изтриване на невалидна позиция
            return false;
        I prev = findPrev(pos);
        if (!prev.valid())
        {
            // опит за изтриване на първия елемент
            x = *pos;
            front = front->next;
            back = nullptr;
            delete pos.ptr;
            return true;
        }
        pos = I();
        return deleteAfter(x, prev);
    }

    bool deleteAfter(DataType &x, I const &pos)
    {
        if (this->empty())
            return false;
        if (!pos.valid())
            return false;
        E *toDelete = pos.ptr->next;
        if (toDelete == nullptr)
            // опит за изключване след последния елемент
            return false;
        if (toDelete == back)
            // изтриваме последния елемент, трябва да пренасочим back
            back = pos.ptr;
        pos.ptr->next = toDelete->next;
        x = toDelete->data;
        delete toDelete;
        return true;
    }

    I begin() const
    {
        return I(front);
    }
    I last() const
    {
        return I(back);
    }

    I end() const
    {
        return I();
    }

    void appendAndDestroy(DoubleLinkedList &other)
    {
        back->next = other.front;
        back = other.back;
        other.back = other.front = nullptr;
    }
};

#endif // _DOUBLE_LINKED_LIST_
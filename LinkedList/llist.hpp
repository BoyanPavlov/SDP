#ifndef _LLIST_
#define _LLIST_

#include "abstractList.hpp"

template <class DataType>
struct LinkedListElement
{
    DataType data;
    LinkedListElement *next;
    LinkedListElement(DataType const &_data, LinkedListElement *_next = nullptr)
        : data(_data), next(_next) {}
};

template <class DataType>
class LinkedList;

template <class DataType>
class LinkedListIterator : public Position<DataType, LinkedListIterator<DataType>>
{
private:
    LinkedListElement<DataType> *ptr;
    friend class LinkedList<DataType>;

public:
    LinkedListIterator(LinkedListElement<DataType> *_ptr = nullptr)
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

    LinkedListIterator next() const
    {
        assert(valid());
        return ptr->next;
    }

    LinkedListIterator prev() const
    {
        throw std::logic_error("In the ordinary llist we don't have access to the prev elem\n");
    }

    bool operator==(Position<DataType, LinkedListIterator> const &pos)
    {
        // We are not checkng if pos is an obj from Iterator
        return ptr == ((LinkedListIterator const &)pos).ptr;
    }

    LinkedListIterator &assign(LinkedListIterator const &pos)
    {
        return *this = pos; 
    }
};

template <class DataType>
class LinkedList : public AbstractList<DataType, LinkedListIterator<DataType>>
{
public:
    using I = LinkedListIterator<DataType>;
    using E = LinkedListElement<DataType>;

private:
    E *front, *back;

public:
    // TODO Big 4
    LinkedList() : front(nullptr), back(nullptr)
    {
    }

    LinkedList(LinkedList const &other)
        : front(nullptr), back(nullptr)
    {
        this->append(other);
    }

    LinkedList &operator=(LinkedList const &other)
    {
        if (this != &other)
        {
            this->erase();
            append(other);
        }
        return *this;
    }

    ~LinkedList()
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

    void appendAndDestroy(LinkedList &other)
    {
        back->next = other.front;
        back = other.back;
        other.back = other.front = nullptr;
    }
};

#endif //_LLIST_
#ifndef _ABSTRACT_LIST
#define _ABSTRACT_LIST

#include <iostream>
#include <cassert>
#include <stdexcept>

// curiously recurring template pattern
// CRTP
template <class DataType, class ConcretePosition /*extends Position<DataType>*/>
class Position
{
    virtual bool valid() const = 0;

    virtual const DataType &get() const = 0;

    virtual DataType &get() = 0;

    virtual ConcretePosition next() const = 0;

    virtual ConcretePosition prev() const = 0;

    // function which moves us on next pos
    //++it
    ConcretePosition &operator++()
    {
        return *this = next();
    }

    ConcretePosition &operator++(int)
    {
        ConcretePosition save = *this;
        ++*this;
        return save;
    }

    virtual bool operator==(Position const &pos) const = 0;

    bool operator!=(Position const &pos)
    {
        return !(*this == pos);
    }

    const DataType &operator*() const { return get(); }
    DataType &operator*() { return get(); }
};

template <class DataType, class OtherType /*extends Possition<DataType> */>
class AbstractList
{
protected:
    void erase()
    {
        DataType x;
        while (!empty())
        {
            deleteFirst(x);
        }
    }

private:
    /* data */
public:
    virtual bool empty() const
    {
        return !begin().valid();
    }

    virtual bool insertFirst(DataType const &x)
    {
        insertBefore(x, begin());
    }
    virtual bool insertLast(DataType const &x)
    {
        insertAfter(x, end());
    }
    
    virtual bool insertBefore(DataType const &, OtherType const &pos) = 0;
    virtual bool insertAt(DataType const &, OtherType const &pos) = 0;
    virtual bool insertAfter(DataType const &, OtherType const &pos) = 0;

    virtual bool deleteFirst(DataType &x)
    {
        OtherType pos = begin();
        return deleteAt(x, pos);
    }
    virtual bool deleteLast(DataType &x)
    {
        OtherType pos = last();
        return deleteAt(x, pos);
    }
    virtual bool deleteBefore(DataType &, OtherType const &pos) = 0;
    virtual bool deleteAt(DataType &, OtherType &pos) = 0;
    virtual bool deleteAfter(DataType &, OtherType const &pos) = 0;

    virtual const DataType &getAt(const OtherType &pos) const
    {
        if (!pos.valid())
        {
            throw std::runtime_error("Given invalid pos\n");
        }
        return pos.get();
    }
    virtual DataType &getAt(OtherType &pos)
    {
        if (!pos.valid())
        {
            throw std::runtime_error("Given invalid pos\n");
        }
        return pos.get();
    }

    // !! we can change the elements of constant list
    // TODO - realise constPosition class

    // returns the possition in the beginning
    virtual OtherType begin() const = 0;
    // returns the pos after the end
    //[begin;end)
    virtual OtherType end() const = 0;

    virtual OtherType last() const = 0;

    void append(AbstractList const &other)
    {
        for (DataType const &x : other)
            insertLast(x);
    }

    void reverse()
    {
        DataType x;
        /*
        P originalFront = begin();
        // O(n²)
        while (originalFront != last()) {
            // O(n)
            deleteLast(x);
            // O(n)
            insertBefore(x, originalFront);
        }
        */

        OtherType originalBack = last();
        // O(n) по памет и по време
        while (originalBack != begin())
        {
            // O(1)
            deleteFirst(x);
            // O(1)
            insertAfter(x, originalBack);
        }
    }

    virtual ~AbstractList(){};
};

#endif // _ABSTRACT_LIST
#ifndef _ABSTRACT_STACK
#define _ABSTRACT_STACK

#include <iostream>
#include <cassert>
#include <cstddef>

template <class DataType>
class AbstractStack
{
private:
    // empty here
public:
    /// checks if stack is empty
    virtual bool empty() const = 0;
    /// returns the last added element and removes it from the stack
    virtual DataType pop() = 0;
    /// adds to the stack one more element
    virtual void push(DataType const &) = 0;
    /// returns the last added element without removing it from the stack
    virtual DataType const &peek() const = 0;
};

#endif // _ABSTRACT_STACK
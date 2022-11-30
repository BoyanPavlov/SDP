//////
// Stack realized using statically declared array
//////

#include <iostream>
#include <cassert>

#ifndef _STACK_
#define _STACK_

#include "abstractStack.hpp"
template <class DataType>
class Stack : public AbstractStack<DataType>
{
private:
    static const int MAX_SIZE = 100;
    static const int EMPTY_STACK = -1;

    /// the stack - used array as a base
    DataType stack[MAX_SIZE];

    /// the index of the top element
    int top;
    /// checks if the stack is full to it's fullest capacity
    bool full() const;

public:
    Stack();

    /// checks if the stack is empty
    bool empty() const;

    /// adds element to the stack
    void push(DataType const &var);

    /// returns the last added element
    DataType const &peek() const;

    /// exclude the last added element
    DataType pop();

};

template <class DataType>
Stack<DataType>::Stack()
{
    top = EMPTY_STACK;
}

template <class DataType>
bool Stack<DataType>::empty() const
{
    return top == EMPTY_STACK;
}

template <class DataType>
void Stack<DataType>::push(DataType const &var)
{
    if (full())
    {
        throw std::runtime_error("Attempting including element in already full stack\n");
    }
    stack[++top] = var;
}

template <typename DataType>
DataType const &Stack<DataType>::peek() const
{
    if (empty())
    {
        throw std::runtime_error("An attempt to peek in empty stack");
    }

    assert(top >= 0 && top < MAX_SIZE);
    return stack[top];
}

template <class DataType>
DataType Stack<DataType>::pop()
{
    if (empty())
    {
        throw std::runtime_error("An attempt of popping from empty stack\n");
    }
    return stack[top--];
}

template <class DataType>
bool Stack<DataType>::full() const
{
    return top == MAX_SIZE - 1;
}
#endif // _STACK_
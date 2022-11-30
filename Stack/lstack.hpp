#ifndef _LINKED_STACK
#define _LINKED_STACK

#include "abstractStack.hpp"
template <class DataType>
struct StackElement
{
    DataType data;
    StackElement *next;
};

template <class DataType>
class LinkedStack : public AbstractStack<DataType>
{
private:
    // pointer to the top of the stack
    StackElement<DataType> *top;

    // A method for coping the stack
    void copyStack(LinkedStack const &);

    // deleting the stack
    void erase();

public:
    // creates an empty stack
    LinkedStack();

    // A destructor
    ~LinkedStack();

    // copy constructor
    LinkedStack(LinkedStack const &);

    // assignments operator
    LinkedStack &operator=(LinkedStack const &);

    // move constructor
    LinkedStack(LinkedStack &&);

    // move assignment operator
    LinkedStack &operator=(LinkedStack &&);

    // checks if stack is emtpy
    bool empty() const;

    // adds new element to the stack
    void push(DataType const &);

    // returns the top element of the stack
    DataType const &peek() const;

    DataType &peek();

    // safely finding the top element of the stack and indicating for success
    bool peek(DataType &) const;

    // removes the top element of the stack
    DataType pop();

    // safely removing the top element of the stack and indicating for success
    DataType pop(bool &success);

    void steal(LinkedStack &&other)
    {
        if (top != nullptr)
            // erase();
            throw std::runtime_error("Stealing from not an empty obj!");
        top = other.top;
        other.top = nullptr;
    }
};

template <class DataType>
void LinkedStack<DataType>::copyStack(LinkedStack<DataType> const &other)
{
    if (other.top != nullptr)
    {
        top = new StackElement<DataType>{other.top->data, nullptr};
        StackElement<DataType> *lastAdded = top;
        StackElement<DataType> *nextToCopy = other.top->next;
        while (nextToCopy)
        {
            lastAdded->next = new StackElement<DataType>{nextToCopy->data, nullptr};
            lastAdded = lastAdded->next;
            nextToCopy = nextToCopy->next;
        }
    }
}

template <class DataType>
void LinkedStack<DataType>::erase()
{
    while (!empty())
    {
        pop();
    }
}

template <class DataType>
LinkedStack<DataType>::LinkedStack()
    : top(nullptr)
{
}

template <class DataType>
LinkedStack<DataType>::~LinkedStack()
{
    erase();
}

template <class DataType>
LinkedStack<DataType>::LinkedStack(LinkedStack const &other)
    : top(nullptr)
{
    // std::clog << "Coping a stack" << std::endl;
    copyStack(other);
}

template <class DataType>
LinkedStack<DataType> &LinkedStack<DataType>::operator=(LinkedStack const &other)
{
    std::clog << "Assigning the stack" << std::endl;
    if (this != &other)
    {
        erase();
        copyStack(other);
    }
    return *this;
}

template <class DataType>
LinkedStack<DataType>::LinkedStack(LinkedStack &&other)
    : top(other.top)
{
    /*std::clog << "Конструктор за преместване на LinkedStack" << std::endl;*/
    other.top = nullptr;
}

template <class DataType>
LinkedStack<DataType> &LinkedStack<DataType>::operator=(LinkedStack &&other)
{
    // std::cout << "Operation for moving the LinkedStack" << std::endl;
    if (this != &other)
    {
        erase();
        top = other.top;
        other.top = nullptr;
    }
    return *this;
}

template <class DataType>
bool LinkedStack<DataType>::empty() const
{
    return top == nullptr;
}

template <class DataType>
void LinkedStack<DataType>::push(DataType const &element)
{
    top = new StackElement<DataType>{element, top};
}

template <class DataType>
DataType const &LinkedStack<DataType>::peek() const
{
    if (empty())
        throw std::runtime_error("An attemt to peek in emtpy stack");
    return top->data;
}

template <class DataType>
DataType &LinkedStack<DataType>::peek()
{
    if (empty())
        throw std::runtime_error("An attempt to peek in emtpy stack");
    return top->data;
}

template <class DataType>
bool LinkedStack<DataType>::peek(DataType &result) const
{
    if (empty())
        return false;
    result = top->data;
    return true;
}

template <class DataType>
DataType LinkedStack<DataType>::pop()
{
    if (empty())
    {
        throw std::runtime_error("An attempt of popping from empty stack\n");
    }

    StackElement<DataType> *newtop = top->next;
    DataType data = top->data;
    delete top;
    top = newtop;
    return data;
}

template <class DataType>
DataType LinkedStack<DataType>::pop(bool &success)
{
    if (empty())
    {
        success = false;
        return DataType();
    }
    success = true;
    return pop();
}

#endif // _LINKED_STACK
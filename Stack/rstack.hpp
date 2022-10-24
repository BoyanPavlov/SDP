#ifndef _RESIZING_STACK_
#define _RESIZING_STACK_

template <class DataType>
class ResizingStack
{
private:
    static const int EMPTY_STACK = -1;
    static const size_t INIT_STACK = 10;

    DataType *stack;

    int top;

    size_t capacity;

    bool full() const;

    void resize();

    void copyData(ResizingStack const &);

public:
    ResizingStack();

    ~ResizingStack();

    ResizingStack(ResizingStack const &);

    ResizingStack &operator=(ResizingStack const &);

    bool empty() const;

    void push(DataType const &element);

    DataType const &peek() const;

    DataType pop();
};

#endif // _RESIZING_STACK_

template <class DataType>
bool ResizingStack<class DataType>::full() const
{
    return top == capacity - 1;
}

template <class DataType>
void ResizingStack<class DataType>::resize()
{
    size_t newCapacity = 2 * capacity;
    std::clog << "Resizing the stack to" << newCapacity << std::endl;
    DataType *newStack = new DataType[newCapacity];
    for (int i = 0; i < capacity; i++)
    {
        newStack[i] = stack[i];
    }
    capacity = newCapacity;
    delete[] stack;
    stack = newStack;
}

template <class DataType>
void ResizingStack<class DataType>::copyData(ResizingStack<class DataType> const &other)
{
    stack = new DataType[capacity];
    for (size_t i = 0; i <= top; i++)
    {
        stack[i] = other.stack[i];
    }
}

template <class DataType>
ResizingStack<class DataType>::ResizingStack()
    : capacity(INIT_STACK), top(EMPTY_STACK)
{
    stack = new T[capacity];
}

template <class DataType>
ResizingStack<class DataType>::~ResizingStack()
{
    delete[] stack;
}

template <class DataType> // защо не пишем типове пред всеки ResizingStack тук ?
ResizingStack<class DataType>::ResizingStack(ResizingStack const &other)
    : top(other.top), capacity(other.capacity)
{
    copyData(other);
}

template <class DataType>
ResizingStack<class DataType> &ResizingStack<class DataType>::operator=(ResizingStack const &other)
{
    if (this != &other)
    {
        delete[] stack;
        top = other.top;
        capacity = other.capacity;
        copyData(other);
    }
    return *this;
}

template <class DataType>
bool ResizingStack<class DataType>::empty() const
{
    return top == EMPTY_STACK;
}

template <class DataType>
void ResizingStack<class DataType>::push(DataType const &element)
{
    if (full())
        resize();
    stack[++top] = element;
}

template <class DataType>
DataType const &ResizingStack<class DataType>::peek() const
{
    if (empty())
    {
        throw std::runtime_error("An attempt to peek in empty stack");
    }
    assert(top >= 0 && top < capacity);
    return stack[top];
}

template <class DataType>
DataType ResizingStack<class DataType>::pop()
{
    if (empty())
    {
        throw std::runtime_error("An attempt of popping from empty stack\n");
    }
    return stack[top--];
}
#ifndef _ABSTRACT_STACK
#define _ABSTRACT_STACK

template <class DataType>
class AbstractStack
{
private:
    // empty here
public:
    /// checks if stack is empty
    virtual bool empty() const = 0;
    /// returns the last added element and removes it from the stack
    virtual DataType pop() const = 0;
    /// adds to the pile one more element
    virtual void push(DataType const &) = 0;
    /// returns the last added element without removing it from the stack
    virtual DataType peek() const = 0;
};

#endif // _ABSTRACT_STACK
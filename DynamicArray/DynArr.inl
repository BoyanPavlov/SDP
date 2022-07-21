#pragma once

/******************************************************************
 *  Sample code to the course "Data Structures And Algorithms", FMI
 *
 * A template class for dynamic array.
 *
 * Inline implementation of the member methods.
 *
 * (cc) Petar Armyanov, FMI, 2020
 *******************************************************************/

#ifndef _DYN_ARRAY_IMPLEMENTATION_INCLUDED__
#define _DYN_ARRAY_IMPLEMENTATION_INCLUDED__

template <class DataType>
inline DynArr<DataType>::DynArr(int initialCapacity)
    : data(nullptr), size(0), capacity(initialCapacity)
{
    // Ensure object correctness with an exception
    if (initialCapacity <= 0)
    {
        throw std::invalid_argument("Illegal initial size");
    }

    // If the memory can not be allocated an exception will be thrown
    data = new DataType[capacity];
}

template <class DataType>
inline DynArr<DataType>::~DynArr()
{
    clear();
}

template <class DataType>
inline DynArr<DataType>::DynArr(const DynArr &other)
    : data(nullptr), size(other.getSize()), capacity(other.getCapacity())
{
    capacity = capacity ? capacity : 1;
    data = new DataType[capacity];

    try
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other[i];
        }
    }
    catch (...)
    {
        // Ensure no memory will leak if data assignment throws
        delete[] data;
        throw; // no exception swallowing
    }
}

template <class DataType>
inline DynArr<DataType> &DynArr<DataType>::operator=(const DynArr<DataType> &other)
{
    if (this != &other)
    {
        // eventually no reallocation is done
        if (capacity < other.getSize())
        {
            clear();
            ensureSize(other.getCapacity());
        }
        size = other.getSize();

        for (size_t i = 0; i < size; ++i)
        {
            // If exception is thrown we do not handle it,
            // but no menace of memory leak here.
            data[i] = other[i];
        }
    }
    return *this;
}

// Note the syntax of the double-template function.
// Note also, that two constructors have to be implemented
template <class DataType>
template <class OtherType>
inline DynArr<DataType>::DynArr(const DynArr<OtherType> &other)
    : data(nullptr), size(other.getSize()), capacity(other.getCapacity())
{
    capacity = capacity ? capacity : 1;
    data = new DataType[capacity];
    try
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other[i];
        }
    }
    catch (...)
    {
        delete[] data;
        throw;
    }
}

// Note the syntax of the double-template function.
// Note also, that two assignment operators have to be implemented
template <class DataType>
template <class OtherType>
inline DynArr<DataType> &DynArr<DataType>::operator=(const DynArr<OtherType> &other)
{
    // In that case two objects have different types, so
    // no need to check for self-assignment
    size = other.getSize();
    if (capacity < other.getSize())
    {
        clear();
        ensureSize(other.getSize());
    }

    for (size_t i = 0; i < size; ++i)
    {
        data[i] = other[i];
    }

    return *this;
}

// In that case we do not need function to append vector of the same type
template <class DataType>
template <class OtherType>
inline DynArr<DataType> &DynArr<DataType>::operator+=(const DynArr<OtherType> &other)
{
    ensureSize(size + other.getSize());
    for (size_t i = 0; i < other.getSize(); ++i)
    {
        data[size + i] = other[i];
    }
    size += other.getSize();
    return *this;
}

// In that case we do not need function to append element of different type
template <class DataType>
inline DynArr<DataType> &DynArr<DataType>::operator+=(const DataType &elem)
{
    append(elem);
    return *this;
}

template <class DataType>
inline void DynArr<DataType>::append(const DataType &elem)
{
    ensureSize(size + 1);
    data[size] = elem;
    ++size;
}

template <class DataType>
inline size_t DynArr<DataType>::getSize() const
{
    return size;
}

template <class DataType>
inline size_t DynArr<DataType>::getCapacity() const
{
    return capacity;
}

template <class DataType>
inline bool DynArr<DataType>::isEmpty() const
{
    return size == 0;
}

template <class DataType>
inline void DynArr<DataType>::clear()
{
    delete[] data;
    data = nullptr;
    capacity = size = 0;
}

template <class DataType>
inline DataType DynArr<DataType>::get(size_t index) const
{
    if (index < size)
    {
        return data[index];
    }

    // In this implementation the method is designed to return
    // default-constructed element in case of out-of-range access
    return DataType();
}

template <class DataType>
inline void DynArr<DataType>::remove(size_t index)
{
    // As this is destructive operation, here we can not ignore out-of-range access
    if (index >= size)
    {
        throw std::invalid_argument("Illegal index");
    }

    for (size_t i = index; i < size - 1; ++i)
    {
        data[i] = data[i + 1];
    }
    --size;
}

//  This function returns only bool result.
// In many cases it is better to return the index or -1 of the element is not persistent
template <class DataType>
inline bool DynArr<DataType>::contains(const DataType &elem) const
{
    for (size_t i = 0; i < size; ++i)
    {
        if (elem == data[i])
        {
            return true;
        }
    }
    return false;
}

// Note, that there are two same operators.
// It is possible to implement one using the other, but it is a bit ugly to use casts
// As the code is simple enough, in that case it OK to have duplication.
template <class DataType>
inline const DataType &DynArr<DataType>::operator[](size_t index) const
{
    if (index < size)
    {
        return data[index];
    }
    throw std::invalid_argument("Illegal index");
}

template <class DataType>
inline DataType &DynArr<DataType>::operator[](size_t index)
{
    if (index < size)
    {
        return data[index];
    }
    throw std::invalid_argument("Illegal index");
}

template <class DataType>
inline void DynArr<DataType>::ensureSize(size_t size)
{
    // As it is internal helper, the assert is the better way to check.
    assert(!data || capacity != 0);

    size_t newSize = data ? capacity : 1;

    while (newSize < size)
    {
        newSize *= 2;
    }

    // Note that in case of same or smaller size nothing is changed
    if (newSize != capacity)
    {
        resize(newSize);
    }
}

// This method can be used not only to increase the size,
// but also to shrink the array.
template <class DataType>
inline void DynArr<DataType>::resize(size_t newCapacity)
{
    DataType *newData = new DataType[newCapacity];

    try
    {
        for (size_t i = 0; i < size && i < newCapacity; ++i)
        {
            newData[i] = data[i];
        }
    }
    catch (...)
    {
        delete[] newData;
        throw;
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    size = size < capacity ? size : capacity;
}

// Note the implementation - it uses the assignment version of the same operator
template <class DataType>
inline DynArr<DataType> operator+(const DynArr<DataType> &array, const DataType &data)
{
    return DynArr<DataType>(array) += data;
}

template <class DataType, class OtherType>
inline DynArr<DataType> operator+(const DynArr<DataType> &array, const DynArr<OtherType> &other)
{
    return DynArr<DataType>(array) += other;
}

#endif //_DYN_ARRAY_IMPLEMENTATION_INCLUDED__

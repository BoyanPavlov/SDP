#ifndef _MY_VECTOR_
#define _MY_VECTOR_

template <class DataType>
class MyVector
{
private:
protected:
	DataType *data;
	size_t size;
	size_t capacity;

public:
	explicit MyVector(int initialCapacity = 16);

	// destr
	~MyVector();

	// copy constr
	MyVector(const MyVector &rhs);

	// assignment operator
	MyVector &operator=(const MyVector &rhs);

	// A constructor, that creates an array as a copy.
	// The source array can have different type of elements!
	// In that case implicit cast operator between two types is expected.
	template <class OtherType>
	DynArray(const DynArray<OtherType> &other);
};

#endif // _MY_VECTOR_

#pragma once
#include "Iterator.h"
namespace my
{
template<class T>
class Vector {
public:
	typedef my::Iterator<T> Iterator;
	typedef my::Iterator<const T> ConstIterator;

	Vector();
	Vector(const std::initializer_list<T>&);
	Vector(const Vector&);
	~Vector();

	void resize(const int32_t&);
	void push_back(const T&);
	void pop_back();

	T& at(const int32_t&) const;

	int32_t size() const;

	ConstIterator begin() const;
	ConstIterator end() const;
	Iterator begin();
	Iterator end();
private:
	int32_t m_length;
	int32_t m_size;
	T* m_data;
};
}
#include "Vector.inl"

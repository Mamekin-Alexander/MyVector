#pragma once
#include <iterator>
namespace my {

template <class ValueType>
class Iterator : public std::iterator<std::random_access_iterator_tag, ValueType>
{
	template<class T>
	friend class Vector;
public:
	Iterator();

	Iterator(const Iterator&);
	Iterator& operator=(const Iterator&);

	Iterator(Iterator&&) noexcept;
	Iterator& operator=(Iterator&&) noexcept;

	Iterator(ValueType*);

	ValueType& operator*() const;
	ValueType* operator->()const;

	Iterator& operator++();
	Iterator operator++(int);
	Iterator& operator--();
	Iterator operator--(int);
	Iterator& operator+=(const ptrdiff_t&);

	template <class U>
	friend Iterator<U> operator+(const ptrdiff_t&, const Iterator<U>&);

	template <class U>
	friend Iterator<U> operator+(const Iterator<U>&, const ptrdiff_t&);

	Iterator& operator-=(const ptrdiff_t&);

	template <class U>
	friend Iterator<U> operator-(const Iterator<U>&, const ptrdiff_t&);

	template <class U>
	friend ptrdiff_t operator-(const Iterator<U>&, const Iterator<U>&);

	ValueType& operator[](const ptrdiff_t&);

	bool operator<(const Iterator&) const;
	bool operator>(const Iterator&) const;
	bool operator>=(const Iterator&) const;
	bool operator<=(const Iterator&) const;
	bool operator!=(const Iterator&) const;
	bool operator==(const Iterator&) const;

	~Iterator();
private:
	ValueType* m_ptr;
};

}

#include "Iterator.inl"
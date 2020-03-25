#pragma once
#include <iterator>
namespace my {

template <class ValueType>
class Iterator : public std::iterator<std::input_iterator_tag, ValueType>
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
	bool operator!=(const Iterator&) const;
	bool operator==(const Iterator&) const;

	~Iterator();
private:
	ValueType* m_ptr;
};

}
#include "Iterator.inl"
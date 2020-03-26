#pragma once
#include "Iterator.h"
namespace my {
	//Default constructor
	template <class ValueType>
	Iterator<ValueType>::Iterator()
	{
		m_ptr = nullptr;
	}


	//Copy constructor and copy assignable
	template <class ValueType>
	Iterator<ValueType>::Iterator(const Iterator<ValueType>& other)
	{
		m_ptr = other.m_ptr;
	}

	template <class ValueType>
	Iterator<ValueType>& Iterator<ValueType>::operator= (const Iterator<ValueType>& other)
	{
		if (this == &other)
		{
			return *this;
		}
		m_ptr = other.m_ptr;
		return *this;
	}



	//Move constructor and move assignable
	template <class ValueType>
	Iterator<ValueType>::Iterator(Iterator<ValueType>&& other) noexcept
	{
		m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}

	template <class ValueType>
	Iterator<ValueType>& Iterator<ValueType>::operator= (Iterator<ValueType>&& other) noexcept
	{
		if (this == &other)
		{
			return *this;
		}
		m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
		return *this;
	}



	//Constructor from ptr
	template <class ValueType>
	Iterator<ValueType>::Iterator(ValueType* ptr)
	{
		m_ptr = ptr;
	}




	//Dereferencing operators
	template <class ValueType>
	ValueType& Iterator<ValueType>::operator*() const
	{
		return *(m_ptr);
	}

	template <class ValueType>
	ValueType* Iterator<ValueType>::operator->() const
	{
		return m_ptr;
	}

	template<class ValueType>
	ValueType& Iterator<ValueType>::operator[](const ptrdiff_t& n)
	{
		return *((*this) + n);
	}


	//Arithmetic operators
	template <class ValueType>

	Iterator<ValueType>& Iterator<ValueType>::operator++()
	{
		++m_ptr;
		return *this;
	}
	template <class ValueType>

	Iterator<ValueType> Iterator<ValueType>::operator++(int)
	{
		Iterator<ValueType> tmp = *this;
		++(*this);
		return tmp;
	}
	template <class ValueType>

	Iterator<ValueType>& Iterator<ValueType>::operator--()
	{
		--m_ptr;
		return *this;
	}
	template <class ValueType>

	Iterator<ValueType> Iterator<ValueType>::operator--(int)
	{
		Iterator<ValueType> tmp = *this;
		--(*this);
		return tmp;
	}
	template <class ValueType>

	Iterator<ValueType>& Iterator<ValueType>::operator+=(const ptrdiff_t& n)
	{
		ptrdiff_t m = n;
		if (m >= 0) {
			while (m != 0)
			{
				++(*this);
				--m;
			}
		}
		else {
			while (m != 0)
			{
				--(*this);
				++m;
			}
		}
		return (*this);
	}

	template<class U>
	Iterator<U> operator+(const Iterator<U>& iter, const ptrdiff_t& n)
	{
		Iterator<U> tmp = iter;
		return tmp += n;
	}

	template<class U>
	Iterator<U> operator+(const ptrdiff_t& n, const Iterator<U>& iter)
	{
		Iterator<U> tmp = iter;
		return tmp += n;
	}

	template<class ValueType>
	Iterator<ValueType>& Iterator<ValueType>::operator-=(const ptrdiff_t& n)
	{
		return (*this) += -n;
	}

	template<class U>
	Iterator<U> operator-(const Iterator<U>& iter, const ptrdiff_t& n)
	{
		Iterator<U> tmp = iter;
		return tmp -= n;
	}

	template<class U>
	ptrdiff_t operator-(const Iterator<U>& left, const Iterator<U>& right)
	{
		return left.m_ptr - right.m_ptr;
	}



	//Bool operators
	template<class ValueType>
	bool Iterator<ValueType>::operator<(const Iterator<ValueType>& other) const
	{
		return (other - (*this) > 0);
	}

	template<class ValueType>
	bool Iterator<ValueType>::operator>(const Iterator<ValueType>& other) const
	{
		return (other - (*this) < 0);
	}

	template<class ValueType>
	bool Iterator<ValueType>::operator>=(const Iterator<ValueType>& other) const
	{
		return !((*this)<other);
	}

	template<class ValueType>
	bool Iterator<ValueType>::operator<=(const Iterator<ValueType>& other) const
	{
		return !((*this) > other);
	}

	template<class ValueType>
	bool Iterator<ValueType>::operator==(const Iterator<ValueType>& other) const
	{
		return (m_ptr == other.m_ptr);
	}

	template<class ValueType>
	bool Iterator<ValueType>::operator!=(const Iterator<ValueType>& other) const
	{
		return (m_ptr != other.m_ptr);
	}


	//Distructor
	template<class ValueType>
	Iterator<ValueType>::~Iterator()
	{

	}
}
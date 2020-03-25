#pragma once
#include "Iterator.h"

//Default constructor
template <class ValueType>
my::Iterator<ValueType>::Iterator()
{
	m_ptr = nullptr;
}


//Copy constructor and copy assignable
template <class ValueType>
my::Iterator<ValueType>::Iterator(const Iterator<ValueType>& other)
{
	m_ptr = other.m_ptr;
}

template <class ValueType>
my::Iterator<ValueType>& my::Iterator<ValueType>::operator= (const Iterator<ValueType>& other)
{
	if (this==&other)
	{
		return *this;
	}
	m_ptr = other.m_ptr;
	return *this;
}



//Move constructor and move assignable
template <class ValueType>
my::Iterator<ValueType>::Iterator(Iterator<ValueType>&& other) noexcept
{
	m_ptr = other.m_ptr;
	other.m_ptr = nullptr;
}

template <class ValueType>
my::Iterator<ValueType>& my::Iterator<ValueType>::operator= (Iterator<ValueType>&& other) noexcept
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
my::Iterator<ValueType>::Iterator(ValueType* ptr)
{
	m_ptr = ptr;
}




//Dereferencing operators
template <class ValueType>
ValueType& my::Iterator<ValueType>::operator*() const
{
	return *(m_ptr);
}

template <class ValueType>
ValueType* my::Iterator<ValueType>::operator->() const
{
	return m_ptr;
}



//Arithmetic operators
template <class ValueType>
my::Iterator<ValueType>  &my::Iterator<ValueType>::operator++()
{
	++m_ptr;
	return *this;
}
template <class ValueType>
my::Iterator<ValueType> my::Iterator<ValueType>::operator++(int)
{
	Iterator<ValueType> tmp = *this;
	++(*this);
	return tmp;
}


//Bool operators
template<class ValueType>
bool my::Iterator<ValueType>::operator==(const my::Iterator<ValueType>& other) const
{
	return (m_ptr == other.m_ptr);
}

template<class ValueType>
bool my::Iterator<ValueType>::operator!=(const my::Iterator<ValueType>& other) const
{
	return (m_ptr != other.m_ptr);
}


//Distructor
template<class ValueType>
my::Iterator<ValueType>::~Iterator()
{

}
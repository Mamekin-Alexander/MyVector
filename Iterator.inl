#pragma once
#include "Iterator.h"

//Initializing and copying
template <class ValueType>
my::Iterator<ValueType>::Iterator()
{
	m_ptr = nullptr;
}

template <class ValueType>
my::Iterator<ValueType>::Iterator(const Iterator<ValueType>& other)
{
	m_ptr = other.m_ptr;
}

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
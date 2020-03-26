#pragma once
#include "Vector.h"
#include <assert.h>
#include <cstring>
namespace my {
	//Constructors and detructor
	template <class T>
	Vector<T>::Vector()
	{
		m_length = 10;
		m_size = 0;
		m_data = new T[m_length];
	}

	template <class T>
	Vector<T>::Vector(const Vector<T>& other)
	{
		m_length = other.m_length;
		m_size = other.m_size;
		if (other.m_length != 0)
		{
			m_data = new T[m_length];
			memcpy(m_data, other.m_data, m_size * sizeof(T));
		}
		else
		{
			m_data = nullptr;
		}
	}

	template <class T>
	Vector<T>& Vector<T>::operator=(const Vector<T>& other)
	{
		if (this != &other)
		{
			if (m_data != nullptr)
			{
				delete[]m_data;
			}
			m_size = other.m_size;
			m_length = other.m_length;
			if (m_length != 0)
			{
				m_data = new T[m_length];
				memcpy(m_data, other.m_data, m_size*sizeof(T));
			}
		}
		return *this;
	}

	template <class T>
	Vector<T>::Vector(Vector<T>&& other) noexcept
	{
		m_length = other.m_length;
		m_size = other.m_size;
		m_data = other.m_data;
	}

	template <class T>
	Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
	{
		if (this != &other)
		{
			if (m_data != nullptr)
			{
				delete[]m_data;
			}
			m_size = other.m_size;
			m_length = other.m_length;
			m_data = other.m_data;
		}
		return *this;
	}

	template <class T>
	Vector<T>::Vector(const std::initializer_list<T>& list)
	{
		m_length = list.size();
		m_size = m_length;
		m_data = new T[m_length];
		int32_t count = 0;
		for (const T& element : list)
		{
			m_data[count] = element;
			count++;
		}
	}

	template <class T>
	Vector<T>::~Vector()
	{
		delete[] m_data;
		m_length = 0;
		m_size = 0;
	}



	//Accessing methods
	template<class T>
	T& Vector<T>::at(const int32_t& index) const
	{
		assert(index >= 0 && index < m_size && "Index is out of range!");
		return m_data[index];
	}



	//Editing methods
	template <class T>
	void Vector<T>::resize(const int32_t& new_length)
	{
		assert(new_length >= 0 && "Invaild new length of vector!");
		T* new_data = nullptr;
		if (new_length != 0)
		{
			new_data = new T[new_length];
			if (new_length <= m_length)
			{
				memcpy(new_data, m_data, sizeof(T) * new_length);
				m_size = new_length;
			}
			else
			{
				memcpy(new_data, m_data, sizeof(T) * m_length);
			}

		}
		else
		{
			m_size = 0;
		}

		if (m_data != nullptr)
		{
			delete[] m_data;
		}	
		m_length = new_length;
		m_data = new_data;
	}

	template <class T>
	void Vector<T>::push_back(const T& new_element)
	{
		if (m_size == m_length)
		{
			if (m_length == 0)
			{
				resize(10);
			}
			else {
				resize(2 * m_length);
			}
		}
		m_data[m_size] = new_element;
		m_size++;
	}

	template <class T>
	void Vector<T>::pop_back()
	{
		if (m_size > 0) {
			m_size--;
		}
		if ((m_size < m_length / 3) && (m_length > 10))
		{
			resize(m_length / 2);
		}
	}



	//Info methods
	template <class T>
	int32_t Vector<T>::size() const
	{
		return m_size;
	}

	template <class T>
	typename Vector<T>::ConstIterator Vector<T>::begin() const
	{
		if (m_size != 0)
		{
			return ConstIterator(m_data);
		}
		else
		{
			return ConstIterator(nullptr);
		}
	}

	template <class T>
	typename Vector<T>::ConstIterator Vector<T>::end() const
	{
		if (m_length != 0)
		{
			return ConstIterator(m_data + m_size);
		}
		else
		{
			return ConstIterator(nullptr);
		}
	}

	template <class T>
	typename Vector<T>::Iterator Vector<T>::begin()
	{
		if (m_size != 0)
		{
			return Iterator(m_data);
		}
		else
		{
			return Iterator(nullptr);
		}
	}

	template <class T>
	typename Vector<T>::Iterator Vector<T>::end()
	{
		if (m_length != 0) {
			return Iterator(m_data + m_size);
		}
		else
		{
			return Iterator(nullptr);
		}
	}
}

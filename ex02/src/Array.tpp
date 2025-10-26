/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:26:33 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/26 20:57:32 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# ifndef ARRAY_HPP
#  error __FILE__ " sould only be included from Array.hpp"
#  include "Array.hpp"
# endif

# include <stdexcept>
# include <stdint.h>

template <typename T>
Array<T>::Array(): _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(uint32_t n)
: _data(n ? new T[n]() : NULL)
, _size(n)
{}

template <typename T>
Array<T>::Array(const Array& other)
: _data(other._size ? new T[other._size] : NULL)
, _size(other._size)
{
	for (uint32_t i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
Array<T>& 		Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T *newData = other._size ? new T[other._size] : NULL;
		try
		{
			for (uint32_t i = 0; i < other._size; i++)
				newData[i] = other._data[i];
		} catch (...)
		{
			delete[] newData;
			throw;
		}
		delete[] _data;
		_data = newData;
		_size = other._size;
	}
	return *this;
}

template <typename T>
T&			Array<T>::operator[](uint32_t index)
{
	if (index >= _size)
		throw std::out_of_range("Array index out of range");
	return _data[index];
}

template <typename T>
T const&			Array<T>::operator[](uint32_t index) const
{
	if (index >= _size)
		throw std::out_of_range("Array index out of range");
	return _data[index];
}

template <typename T>
uint32_t	Array<T>::size(void) const
{
	return _size;
}

#endif

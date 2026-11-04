/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:28:36 by vrads             #+#    #+#             */
/*   Updated: 2026/11/04 15:57:46 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// 1. Orthodox Canonical Form

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]()), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	T				*new_array;
	unsigned int	i;

	if (this == &other)
		return (*this);
	new_array = new T[other._size]();
	i = 0;
	while (i < other._size)
	{
		new_array[i] = other._array[i];
		i++;
	}
	delete[] _array;
	_array = new_array;
	_size = other._size;
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

// 2. Other Templates

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfBoundsException();
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw OutOfBoundsException();
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return "Index out of bounds o.O";
}

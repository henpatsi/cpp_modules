/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:51:25 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/18 11:05:04 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	public:
		Array( void );
		Array( unsigned int n );
		Array( const Array<T>& );
		~Array( void );
		
		Array<T>& operator=( const Array<T>& );
		T& operator[]( size_t index );

		size_t size( void );

	private:
		T*		ptr;
		size_t	number_of_elements;
};

// CONSTRUCTORS

template <typename T>
Array<T>::Array(void)
{
	this->ptr = new T[0];
	this->number_of_elements = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->ptr = new T[n];
	this->number_of_elements = n;
}

template <typename T>
Array<T>::Array(const Array<T>& from)
{
	this->ptr = new T[from.number_of_elements];
	this->number_of_elements = from.number_of_elements;

	for (size_t i = 0; i < from.number_of_elements; i++)
		this->ptr[i] = from.ptr[i];
}

// DESTRUCTOR

template <typename T>
Array<T>::~Array( void )
{
	delete[] this->ptr;
}

// OPERATORS

template <typename T>
Array<T>& Array<T>::operator=( const Array<T>& from )
{
	if (this != &from)
	{
		delete[] this->ptr;
		this->ptr = new T[from.number_of_elements];
		this->number_of_elements = from.number_of_elements;

		for (size_t i = 0; i < from.number_of_elements; i++)
			this->ptr[i] = from.ptr[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= this->number_of_elements)
	{
		throw std::exception();
		return *(this->ptr);
	}
	return this->ptr[index];
}

// MEMBER FUNCTIONS
template <typename T>
size_t Array<T>::size(void)
{
	return this->number_of_elements;
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:44 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/04 11:09:51 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// CONSTRUCTOR

Span::Span(void)
{
	this->maximumSize = 0;
}

Span::Span(unsigned int size)
{
	this->maximumSize = size;
}

// COPY

Span::Span(const Span& from)
{
	this->maximumSize = from.maximumSize;
	this->vec = from.vec;
}

// DESTRUCTOR

Span::~Span(void)
{
}

// OPERATOR

Span& Span::operator=(const Span& from)
{
	if (this != &from)
	{
		this->maximumSize = from.maximumSize;
		this->vec = from.vec;
	}
	return *this;
}

// MEMBER FUNCTIONS

void Span::addNumber(int number)
{
	if (this->vec.size() == this->maximumSize)
		throw std::runtime_error("Span is already at maximum size");

	this->vec.push_back(number);
}

unsigned int Span::shortestSpan(void)
{
	if (this->vec.size() < 2)
		throw std::runtime_error("Less than two numbers in Span");

	std::vector<int> sorted_vec;

	sorted_vec = this->vec;
	std::sort(sorted_vec.begin(), sorted_vec.end());

	unsigned int shortest = std::abs(sorted_vec[0] - sorted_vec[1]);
	for (std::vector<int>::iterator i = sorted_vec.begin() + 1; i != sorted_vec.end(); i++)
	{
		unsigned int span = std::abs(*i - *(i - 1));
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

unsigned int Span::longestSpan(void)
{
	if (this->vec.size() < 2)
		throw std::runtime_error("Less than two numbers in Span");

	std::vector<int>::iterator min_ptr;
	std::vector<int>::iterator max_ptr;

	min_ptr = std::min_element(this->vec.begin(), this->vec.end());
	max_ptr = std::max_element(this->vec.begin(), this->vec.end());

	return (*max_ptr - *min_ptr);
}

void Span::print(void)
{
	std::cout << "{ ";
	for (int num : this->vec)
	{
		std::cout << num << " ";
	}
	std::cout << "}\n";
}

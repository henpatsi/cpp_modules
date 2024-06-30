/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:44 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/30 14:16:53 by hpatsi           ###   ########.fr       */
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
		return ;

	this->vec.push_back(number);
}

unsigned int Span::shortestSpan(void)
{
	if (this->vec.size() < 2)
		return 0;

	std::vector<int> sorted_vec;

	sorted_vec = this->vec;
	std::sort(sorted_vec.begin(), sorted_vec.end());

	unsigned int shortest = std::abs(sorted_vec[0] - sorted_vec[1]);
	for (std::vector<int>::iterator i = sorted_vec.begin(); i != sorted_vec.end(); i++)
	{
		if (i == sorted_vec.begin())
			continue;
		if (std::abs(*i - *(i - 1)) < shortest)
			shortest = std::abs(*i - *(i - 1));
	}
	return shortest;
}

unsigned int Span::longestSpan (void)
{
	if (this->vec.size() < 2)
		return 0;

	std::vector<int>::iterator min_ptr;
	std::vector<int>::iterator max_ptr;

	min_ptr = std::min_element(this->vec.begin(), this->vec.end());
	max_ptr = std::max_element(this->vec.begin(), this->vec.end());

	return (*max_ptr - *min_ptr);
}

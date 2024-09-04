/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:44 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/04 12:06:16 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// CONSTRUCTOR

Span::Span(void)
{
	m_maximumSize = 0;
}

Span::Span(unsigned int size)
{
	m_maximumSize = size;
}

// COPY

Span::Span(const Span& from)
{
	m_maximumSize = from.m_maximumSize;
	m_vec = from.m_vec;
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
		m_maximumSize = from.m_maximumSize;
		m_vec = from.m_vec;
	}
	return *this;
}

// MEMBER FUNCTIONS

void Span::addNumber(int number)
{
	if (m_vec.size() == m_maximumSize)
		throw std::runtime_error("Span is already at maximum size");

	m_vec.push_back(number);
}

unsigned int Span::shortestSpan(void)
{
	if (m_vec.size() < 2)
		throw std::runtime_error("Less than two numbers in Span");

	std::vector<int> sorted_vec;

	sorted_vec = m_vec;
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
	if (m_vec.size() < 2)
		throw std::runtime_error("Less than two numbers in Span");

	auto minmax = std::minmax_element(m_vec.begin(), m_vec.end());

	return (*minmax.second - *minmax.first);
}

void Span::print(void)
{
	std::cout << "{ ";
	for (int num : m_vec)
	{
		std::cout << num << " ";
	}
	std::cout << "}\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:47 by hpatsi            #+#    #+#             */
/*   Updated: 2024/08/30 12:44:10 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

int main(void)
{
	// ADD

	Span sp = Span(10);
	sp.print();

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	sp.addNumber(6);
	sp.print();

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print();

	Span copy1 = Span(sp);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// RANGE ADD

	std::vector<int> vec{1, 2, 3, 4, 5};
	sp.addIteratorRange(vec.begin(), vec.begin() + 3);
	
	sp.print();

	Span copy2;
	copy2 = sp;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// ADD OVER LIMIT

	try
	{
		sp.addIteratorRange(vec.begin(), vec.begin() + 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	sp.print();

	try
	{
		sp.addNumber(10);
		sp.addNumber(11);
		sp.addNumber(12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	sp.print();

	// COPY

	copy1.print();
	copy2.print();

	return 0;
}

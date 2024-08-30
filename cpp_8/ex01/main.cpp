/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:47 by hpatsi            #+#    #+#             */
/*   Updated: 2024/08/30 14:47:57 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <stdlib.h>
#include <time.h>


#include "Span.hpp"

int main(void)
{
	{
		// ADD

		Span sp = Span(10);
		sp.print();

		try
		{
			std::cout << sp.shortestSpan() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << sp.longestSpan() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		sp.addNumber(6);
		sp.print();

		try
		{
			std::cout << sp.shortestSpan() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << sp.longestSpan() << "\n";
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

		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";

		// RANGE ADD

		std::vector<int> vec{1, 2, 3, 4, 5};
		std::cout << "\nAdding iterator range of size 3\n";
		sp.addIteratorRange(vec.begin(), vec.begin() + 3);
		
		sp.print();

		Span copy2;
		copy2 = sp;

		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";

		// ADD OVER LIMIT

		try
		{
			std::cout << "\nAdding iterator range of size 3\n";
			sp.addIteratorRange(vec.begin(), vec.begin() + 3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		sp.print();

		try
		{
			std::cout << "Adding 10\n";
			sp.addNumber(10);
			std::cout << "Adding 11\n";
			sp.addNumber(11);
			std::cout << "Adding 12\n";
			sp.addNumber(12);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		sp.print();

		// COPY

		std::cout << "\nCopy constructed from 5 size Span:\n";
		copy1.print();
		std::cout << "Copy constructed from 8 size Span:\n";
		copy2.print();
	}

	srand (time(NULL));

	std::cout << "\nCreating span of 100 000 random ints\n";
	Span sp = Span(100000);
	for (unsigned int i = 0; i < 100000; i++)
		sp.addNumber(rand());
	std::cout << sp.shortestSpan() << "\n";
	std::cout << sp.longestSpan() << "\n";
}

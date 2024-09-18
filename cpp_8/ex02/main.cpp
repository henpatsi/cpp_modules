/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:47 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/18 09:44:34 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::list<int> list;

	mstack.push(5);
	list.push_back(5);
	mstack.push(17);
	list.push_back(17);

	std::cout << mstack.top() << std::endl;
	std::cout << list.back() << std::endl;

	mstack.pop();
	list.pop_back();

	std::cout << mstack.size() << std::endl;
	std::cout << list.size() << std::endl;

	mstack.push(3);
	list.push_back(3);
	mstack.push(5);
	list.push_back(5);
	mstack.push(737);
	list.push_back(737);
	mstack.push(0);
	list.push_back(0);

	// MUTANTSTACK PRINT

	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Printing MutantStack:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	// LIST PRINT

	{
		std::list<int>::iterator lit = list.begin();
		std::list<int>::iterator lite = list.end();
		std::cout << "Printing list:\n";
		while (lit != lite)
		{
			std::cout << *lit << std::endl;
			++lit;
		}
	}

	// TEST COPY CONSTRUCT

	{
		MutantStack<int> x(mstack);
		std::cout << "Printing MutantStack copy construct:\n";
		MutantStack<int>::iterator it = x.begin();
		MutantStack<int>::iterator ite = x.end();
		mstack.push(42);
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		mstack.pop();
	}

	// TEST COPY ASSIGNMENT

	{
		MutantStack<int> x;
		x = mstack;
		std::cout << "Printing MutantStack copy assign:\n";
		MutantStack<int>::iterator it = x.begin();
		MutantStack<int>::iterator ite = x.end();
		mstack.push(42);
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		mstack.pop();
	}

	std::stack<int> s(mstack);

	// TEST CONST AND OTHER ITERATORS

	{
		const MutantStack<int> cmstack(mstack);
		// cmstack.push(3);
		// MutantStack<int>::iterator cit = cmstack.begin();

		MutantStack<int>::const_iterator it = cmstack.begin();
		MutantStack<int>::const_iterator ite = cmstack.end();
		std::cout << "Printing const MutantStack:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		MutantStack<int>::const_reverse_iterator rit = cmstack.rbegin();
		MutantStack<int>::const_reverse_iterator rite = cmstack.rend();
		std::cout << "Printing const MutantStack reversed:\n";
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}

	// TEST CONSTRUCT FROM OTHER CONTAINER

	{
		std::vector<int> vec = {1, 2, 3, 4, 5};
		
		std::stack<int, std::vector<int>> stack(vec);
		MutantStack<int, std::vector<int>> vmstack(vec);

		MutantStack<int, std::vector<int>>::const_iterator it = vmstack.begin();
		MutantStack<int, std::vector<int>>::const_iterator ite = vmstack.end();
		std::cout << "Printing vector MutantStack:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}

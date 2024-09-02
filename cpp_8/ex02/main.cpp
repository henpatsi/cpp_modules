/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:47 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/02 16:22:55 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

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

	{
		std::list<int>::iterator lit = list.begin();
		std::list<int>::iterator lite = list.end();
		++lit;
		--lit;
		std::cout << "Printing list:\n";
		while (lit != lite)
		{
			std::cout << *lit << std::endl;
			++lit;
		}
	}

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

	const MutantStack<int> cmstack;
	// cmstack.push(3);
	// MutantStack<int>::iterator cit = cmstack.begin();

	const std::deque<int> dq;
	// dq.push_back(3);
	// std::deque<int>::iterator dit = dq.begin();

	return 0;
}

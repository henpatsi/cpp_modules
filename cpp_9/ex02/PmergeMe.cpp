/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:59:58 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/03 13:57:04 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// CONSTRUCTOR

PmergeMe::PmergeMe(size_t argc, char *argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		int argInt;
		std::string argStr(argv[i]);
		
		if (!strIsDigit(argStr))
			throw ArgumentException();
		try
		{
			argInt = std::stoi(argStr);
		}
		catch(const std::exception& e)
		{
			throw ArgumentException();
		}

		m_vec.push_back(argInt);
		m_list.push_back(argInt);
	}

	printVector("Before:\t");

	sortVector();
	sortList();

	printVector("After:\t");

	std::cout << "Time to process a range of " << m_vec.size() 
				<< " elements with std::vector :\t" << m_vecSortTime.count() << "us\n";
	std::cout << "Time to process a range of " << m_list.size() 
				<< " elements with std::list :\t" << m_listSortTime.count() << "us\n";
}

// DESTRUCTOR

PmergeMe::~PmergeMe(void)
{
}

// MEMBER FUNCTIONS

void PmergeMe::printVector(std::string pretext)
{
	std::cout << pretext;
	for (size_t i = 0; i < m_vec.size(); i++)
	{
		if (i != 0)
			std::cout << " ";
		std::cout << m_vec[i];
	}
	std::cout << "\n";
}

void PmergeMe::sortVector()
{
	auto startTime = std::chrono::high_resolution_clock::now();

	

	auto stopTime = std::chrono::high_resolution_clock::now();
	m_vecSortTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
}

void PmergeMe::sortList()
{
	auto startTime = std::chrono::high_resolution_clock::now();



	auto stopTime = std::chrono::high_resolution_clock::now();	
	m_listSortTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
}


// HELPER FUNCTIONS

bool strIsDigit(std::string str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

// EXCEPTIONS

const char* PmergeMe::ArgumentException::what() const throw()
{
	return "Error";
}

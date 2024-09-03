/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:59:58 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/03 20:54:20 by hpatsi           ###   ########.fr       */
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

	auto startTime = std::chrono::high_resolution_clock::now();
	sortVector();
	auto stopTime = std::chrono::high_resolution_clock::now();
	m_vecSortTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

	startTime = std::chrono::high_resolution_clock::now();
	sortList();
	stopTime = std::chrono::high_resolution_clock::now();
	m_listSortTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

	printVector("After:\t");

	std::cout << "Time to process a range of " << m_vec.size() 
				<< " elements with std::vector : " << m_vecSortTime.count() << "us\n";
	std::cout << "Time to process a range of " << m_list.size() 
				<< " elements with std::list : " << m_listSortTime.count() << "us\n";
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
	if (m_vec.size() == 1)
		return ;

	std::vector<std::pair<int, int>> pairs;
	int oddInt = -1;

	for (size_t i = 0; i + 1 < m_vec.size(); i += 2)
	{
		pairs.push_back(std::pair<int, int>(m_vec[i], m_vec[i + 1]));
	}
	if (m_vec.size() % 2 == 1)
		oddInt = m_vec.back();

	m_vec.clear();

	for (std::pair<int, int>& pair : pairs)
	{
		if (pair.second < pair.first)
			std::swap(pair.first, pair.second);
		m_vec.push_back(pair.second);
	}
	if (oddInt != -1)
		m_vec.push_back(oddInt);

	// std::cout << "pairs:\n";
	// printIntPairVector(pairs);

	// std::cout << "m_vec:\n";
	// printIntVector(m_vec);

	sortVector();

	for (std::pair<int, int>& pair : pairs)
	{
		std::vector<int>::iterator it = m_vec.begin();
		while (*it < pair.first)
			it++;
		m_vec.insert(it, pair.first);
	}

	// std::cout << "\nm_vec2:\n";
	// printIntVector(m_vec);
}

void PmergeMe::sortList()
{
	return ;
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

void printIntVector(std::vector<int> vector)
{
	std::cout << "{ ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i != 0)
			std::cout << " ";
		std::cout << vector[i];
	}
	std::cout << " }\n";
}

void printIntPairVector(std::vector<std::pair<int, int>> vector)
{
	std::cout << "{ ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i != 0)
			std::cout << " ";
		std::cout << "(" << vector[i].first << ", " << vector[i].second << ")";

	}
	std::cout << " }\n";
}

// EXCEPTIONS

const char* PmergeMe::ArgumentException::what() const throw()
{
	return "Error";
}

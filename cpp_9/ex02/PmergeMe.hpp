/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:00:00 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/03 20:15:26 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <chrono>
# include <vector>
# include <list>

bool strIsDigit(std::string str);
void printIntVector(std::vector<int> vector);
void printIntPairVector(std::vector<std::pair<int, int>> vector);

class PmergeMe
{
	public:
		PmergeMe(size_t argc, char *argv[]);
		~PmergeMe(void);
		
		class ArgumentException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		PmergeMe(void) = delete;
		PmergeMe(const PmergeMe&) = delete;
		PmergeMe& operator=(const PmergeMe&) = delete;

		std::vector<int> m_vec {};
		std::list<int> m_list {};
		std::chrono::microseconds m_vecSortTime;
		std::chrono::microseconds m_listSortTime;

		void printVector(std::string pretext);
		void sortVector();
		void sortList();
};

#endif

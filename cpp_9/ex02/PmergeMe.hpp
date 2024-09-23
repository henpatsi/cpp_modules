/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:00:00 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/23 13:28:27 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <chrono>
# include <vector>
# include <list>

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

		void printVector(std::string t_pretext);
		void printList(std::string t_pretext);
		void sortVector();
		void sortList();

		std::vector<int> m_vec {};
		std::list<int> m_list {};
		std::chrono::microseconds m_vecSortTime;
		std::chrono::microseconds m_listSortTime;
};

#endif

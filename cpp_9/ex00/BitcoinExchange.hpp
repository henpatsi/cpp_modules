/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:37:16 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/23 13:26:44 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <ctime>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>

const std::string btc_prices_db = "data.csv";

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string t_inputPath);
		~BitcoinExchange(void);

		class DataFormatException : public std::exception
		{
			public:
				DataFormatException(std::string t_message) : m_message(t_message) {}
				virtual const char* what() const throw();
			private:
				std::string m_message;
		};

		class InputFormatException : public std::exception
		{
			public:
				InputFormatException(std::string t_message) : m_message(t_message) {}
				virtual const char* what() const throw();
			private:
				std::string m_message;
		};

	private:
		BitcoinExchange(void) = delete;
		BitcoinExchange(const BitcoinExchange&) = delete;
		BitcoinExchange& operator=(const BitcoinExchange&) = delete;

		void parseDataLine(std::string t_line);
		void parseInputLine(std::string t_line);
		void printResult(std::string t_dateString, double t_value);
		std::string findClosestDate(std::string t_dateString);

		std::map<std::string, double> m_exchangeRates {}; // TODO check if double is enough, should use unsigned int and store as cents?
};

#endif

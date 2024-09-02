/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:37:13 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/02 23:19:23 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// CONSTRUCTOR

BitcoinExchange::BitcoinExchange(std::string t_inputPath)
{
	std::ifstream db(std::string(BTC_PRICES_DB));
	std::string line;

	getline(db, line); // Skip header
	while (getline(db, line))
	{
		parseDataLine(line);
	}

	std::ifstream input(t_inputPath);

	getline(input, line); // Skip header
	while (getline(input, line))
	{
		try
		{
			parseInputLine(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}

// DESTRUCTOR

BitcoinExchange::~BitcoinExchange(void)
{
}

// MEMBER FUNCTIONS

void BitcoinExchange::parseDataLine(std::string t_line)
{
	std::string::iterator start = t_line.begin();
	std::string::iterator end = std::find(start, t_line.end(), ',');

	if (end == t_line.end()
		|| t_line.front() == ','
		|| t_line.back() == ',')
		throw DataFormatException("Empty fields");
	
	std::string dateString(start, end);

	start = std::next(end);
	end = std::find(start, t_line.end(), ',');
	if (end != t_line.end())
		throw DataFormatException("Extra fields");

	std::string valueString(start, end);
	if (!strIsNum(valueString))
		throw DataFormatException("Value is not a valid number");
	double value = std::stod(valueString);

	m_values[dateString] = value;
}

void BitcoinExchange::parseInputLine(std::string t_line)
{
	std::string separator = " | ";
	std::string::iterator start = t_line.begin();
	std::string::iterator end = std::search(start, t_line.end(), separator.begin(), separator.end());

	if (end == t_line.end())
		throw InputFormatException("bad input => " + t_line);
	
	std::string dateString(start, end);
	if (dateString.empty())
		throw InputFormatException("bad input => " + t_line);
	Date date;
	if (!extractDate(dateString, date))
		throw InputFormatException("invalid date");

	start = std::next(end, 3);
	end = std::search(start, t_line.end(), separator.begin(), separator.end());
	if (end != t_line.end())
		throw InputFormatException("bad input => " + t_line);

	std::string valueString(start, end);
	if (!strIsNum(valueString))
		throw InputFormatException("not a number");
	double value = std::stod(valueString);
	if (value < 0)
		throw InputFormatException("not a positive number");
	if (value > 1000)
		throw InputFormatException("too large a number");

	std::cout << dateString << " => " << valueString << " = " << "x\n";
}

// HELPER FUNCTIONS

bool strIsNum(std::string str)
{
	bool decimalCounted = false;

	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		else if (str[i] == '.' && !decimalCounted && i != 0)
		{
			decimalCounted = true;
			continue;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool extractDate(std::string dateString, Date& date)
{
	std::string segment;
	std::stringstream dateStringStream(dateString);
	int dateInt;

	for (int i = 0; i < 3; i++)
	{
		getline(dateStringStream, segment, '-');
		if (!strIsNum(segment))
			return false;
		dateInt = std::stoi(segment);

		switch (i)
		{
			case 0:
				if (dateInt < 0 || dateInt > 3000 || segment.length() > 4)
					return false;
				date.year = dateInt;
				break;
			case 1:
				if (dateInt < 1 || dateInt > 12  || segment.length() > 2)
					return false;
				date.month = dateInt;
				break;
			case 2:
				if (dateInt < 1 || dateInt > 31  || segment.length() > 2)
					return false;
				if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && dateInt > 30)
					return false;
				if (date.month == 2 && dateInt > 29)
					return false;
				if (date.month == 2 && dateInt > 28 && (date.year % 4 != 0 || (date.year % 100 == 0 && date.year % 400 != 0)))
					return false;
				date.day = dateInt;
				break;
		}
	}

	if (getline(dateStringStream, segment, '-'))
		return false;

	return true;
}

// EXCEPTIONS

const char* BitcoinExchange::DataFormatException::what() const throw()
{
	return m_message.c_str();
}

const char* BitcoinExchange::InputFormatException::what() const throw()
{
	return m_message.c_str();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:37:13 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/03 09:55:43 by hpatsi           ###   ########.fr       */
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
	if (!checkDate(dateString))
		throw DataFormatException("Invalid date");

	start = std::next(end);
	end = std::find(start, t_line.end(), ',');
	if (end != t_line.end())
		throw DataFormatException("Extra fields");

	std::string exchangeRateString(start, end);
	if (!strIsNum(exchangeRateString))
		throw DataFormatException("Invalid number");
	double exchangeRate = std::stod(exchangeRateString);

	m_exchangeRates[dateString] = exchangeRate;
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
	if (!checkDate(dateString))
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
	
	printResult(dateString, value);
}

void BitcoinExchange::printResult(std::string t_dateString, double t_value)
{
	double result = -1;

	if (m_exchangeRates.contains(t_dateString))
		result = t_value * m_exchangeRates[t_dateString];
	else
	{
		std::string closestDate = findClosestDate(t_dateString);
		if (closestDate.empty())
			throw InputFormatException("date does not exist and no ealier entries");
		result = t_value * m_exchangeRates[closestDate];
	}

	std::cout << t_dateString << " => " << t_value << " = " << result << "\n";
}

std::string BitcoinExchange::findClosestDate(std::string t_dateString)
{
	std::string closestDate;
	std::string segment;
	std::stringstream dateStringStream(t_dateString);

	getline(dateStringStream, segment, '-');
	int year = std::stoi(segment);
	getline(dateStringStream, segment, '-');
	int month = std::stoi(segment);
	getline(dateStringStream, segment, '-');
	int day = std::stoi(segment);

	for (; year >= 2009; year--)
	{
		for (; month >= 1; month--)
		{
			for (; day >= 1; day--)
			{
				closestDate = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
				if (month < 10)
					closestDate.insert(closestDate.begin() + 5, '0');
				if (day < 10)
					closestDate.insert(closestDate.begin() + 8, '0');

				if (m_exchangeRates.contains(closestDate))
					return closestDate;
			}
			day = 31;
		}
		month = 12;
	}

	return ("");
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

bool checkDate(std::string dateString)
{
	std::string segment;
	std::stringstream dateStringStream(dateString);
	int dateInt;
	int year;
	int month;

	for (int i = 0; i < 3; i++)
	{
		getline(dateStringStream, segment, '-');
		if (!strIsNum(segment))
			return false;
		dateInt = std::stoi(segment);

		switch (i)
		{
			case 0:
				if (dateInt < 2009 || segment.length() > 4)
					return false;
				year = dateInt;
				break;
			case 1:
				if (dateInt < 1 || dateInt > 12  || segment.length() > 2)
					return false;
				month = dateInt;
				break;
			case 2:
				if (dateInt < 1 || dateInt > 31  || segment.length() > 2)
					return false;
				if ((month == 4 || month == 6 || month == 9 || month == 11) && dateInt > 30)
					return false;
				if (month == 2 && dateInt > 29)
					return false;
				if (month == 2 && dateInt > 28 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
					return false;
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

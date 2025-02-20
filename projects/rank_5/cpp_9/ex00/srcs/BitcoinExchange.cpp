/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:12:29 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/14 12:36:40 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");

	if (!file.is_open())
		throw NoDatabaseException();
	this->_populateDatabase(file);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& obj) : _database(obj.getDatabase())
{
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& obj)
{
	this->_database = obj.getDatabase();
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	
}

std::map<std::string, float>&	BitcoinExchange::getDatabase()
{
	return (this->_database);
}

void	BitcoinExchange::convertHistory(std::string filename)
{
	std::ifstream	file(filename.c_str());
	
	if (!file.is_open())
		throw FileFailureException();
	this->_populateHistory(file);
}

void	BitcoinExchange::_populateHistory(std::ifstream& file)
{
	std::string			str;
	std::string			key;
	std::string			value;
	std::stringstream	ss;

	getline(file, str);
	if (str != "date | value")
		throw WrongFormatException();
	while (getline(file, str))
	{
		ss.clear();
		ss.str(str);
		getline(ss, key, '|');
		getline(ss, value, '|');
		value.erase(0, value.find_first_not_of (" "));
		this->_printHistory(key, std::strtof(value.c_str(), NULL));
	}
}

void	BitcoinExchange::_printHistory(std::string key, float value)
{

	try
	{
		key = this->_checkDates(key);
		this->_checkValues(value);
		std::cout << key << " => " << value << " = " << this->_database[key] * value << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
	}
}

std::string	BitcoinExchange::_checkDates(std::string & date)
{
	std::stringstream	ss;
	std::string			year;
	std::string			month;
	std::string			day;
	std::string			try_date;
	float				aux_y;
	float				aux_m;
	float				aux_d;

	date.erase(0, date.find_first_not_of (" "));
	date.erase(date.find_last_not_of(" ") + 1);
	ss.str(date);
	getline(ss, year, '-');
	getline(ss, month, '-');
	getline(ss, day, '-');
	if (!year.c_str() || !month.c_str() || !day.c_str())
		throw BadInputException(date);
	aux_y = std::strtof(year.c_str(), NULL);
	aux_m = std::strtof(month.c_str(), NULL);
	aux_d = std::strtof(day.c_str(), NULL);
	if (aux_m < 0 || aux_m > 12)
		throw BadInputException(date);
	if (aux_d < 0 || aux_d > this->_maxDay(aux_y, aux_m))
		throw BadInputException(date);
	while (aux_y >= 2011)
	{
		while (aux_m > 0)
		{
			while (aux_d > 0)
			{
				ss.clear();
			ss.str("");
				ss << std::setfill('0') << std::setw(2) << aux_y << std::setw(0) << "-" << std::setw(2) << aux_m << std::setw(0) << "-" << std::setw(2) << aux_d;
				ss >> try_date;
				if (this->_database[try_date])
					return (try_date);
				aux_d--;
			}
			aux_d = std::strtof(day.c_str(), NULL);
			aux_m--;
		}
		aux_m = std::strtof(month.c_str(), NULL);
		aux_y--;
	}
	return (date);
}

void	BitcoinExchange::_checkValues(float & value)
{
	if (value < 0)
		throw NegativeException();
	if (value > 1000)
		throw TooLargeException();
}

int	BitcoinExchange::_maxDay(int year, int month)
{
	if (month == 2)
	{
		if (year % 4 == 0)
			return (29);
		else
			return (28);
	}
	else if (month == 8)
		return (31);
	else if (month % 2)
		return (31);
	else
		return (30);
}

void	BitcoinExchange::_populateDatabase(std::ifstream& file)
{
	std::string			str;
	std::string			key;
	std::string			value;
	std::stringstream	ss;

	getline(file, str);
	if (str != "date,exchange_rate")
		throw WrongFormatException();
	while (getline(file, str))
	{
		ss.clear();
		ss.str(str);
		getline(ss, key, ',');
		getline(ss, value, ',');
		this->_database[key] = std::strtof(value.c_str(), NULL);
	}
}

const char* BitcoinExchange::TooLargeException::what() const throw()
{
	return ("too large a number.");
}

const char* BitcoinExchange::NegativeException::what() const throw()
{
	return ("not a possitive number.");
}

const char* BitcoinExchange::WrongFormatException::what() const throw()
{
	return ("wrong file format.");
}

BitcoinExchange::BadInputException::BadInputException(std::string input)
{
	this->_input = "bad input => " + input;
}

const char* BitcoinExchange::BadInputException::what() const throw()
{
	return (this->_input.c_str());
}

const char* BitcoinExchange::NoDatabaseException::what() const throw()
{
	return ("data.csv not found.");
}

const char* BitcoinExchange::FileFailureException::what() const throw()
{
	return ("could not open file.");
}


BitcoinExchange::BadInputException::~BadInputException() throw()
{

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:12:05 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/15 12:56:47 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <exception>
# include <map>
# include <cstdlib>
# include <sstream>
# include <string>
# include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;
		
		void							_populateDatabase(std::ifstream& file);
		void							_populateHistory(std::ifstream& file);
		void							_printHistory(std::string key, std::string value, std::string str);
		std::string						_checkDates(std::string & date);
		void							_checkValues(std::string & value);
		int								_maxDay(int year, int month);

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange& obj);
		BitcoinExchange& operator=(BitcoinExchange& obj);
		~BitcoinExchange();

		std::map<std::string, float>&	getDatabase();
		void							convertHistory(std::string file);
		
		class TooLargeException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NegativeException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class WrongFormatException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class BadInputException : public std::exception
		{
			private:
				std::string	_input;
			public:
				BadInputException(std::string input);
				virtual ~BadInputException() throw();
				const char* what() const throw();
		};
		class NoDatabaseException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FileFailureException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
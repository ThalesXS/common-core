/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:12:05 by txisto-d          #+#    #+#             */
/*   Updated: 2025/02/14 11:53:36 by txisto-d         ###   ########.fr       */
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

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;
		std::map<std::string, float>	_history;
		
		void							_populateDatabase(std::ifstream& file);
		void							_populateHistory(std::ifstream& file);
		void							_checkDates(std::string& date);
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
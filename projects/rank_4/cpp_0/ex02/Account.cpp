/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:33:35 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 02:33:11 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

static void	timePrint(int time);
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << "\n";
}

Account::Account( int initial_deposit )
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed\n";
	_totalAmount -= _amount;
	_totalNbWithdrawals++;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused\n";
		return (false);
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
		return (true);
	}
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp(void)
{
	time_t timer;
	struct tm *clock;
	
	time(&timer);
	clock = localtime(&timer);
	std::cout << "[";
	std::cout << 1900 + clock->tm_year;
	timePrint(clock->tm_mon + 1);
	timePrint(clock->tm_mday);
	std::cout << "_";
	timePrint(clock->tm_hour);
	timePrint(clock->tm_min);
	timePrint(clock->tm_sec);
	std::cout << "]";
}

static void	timePrint(int time)
{
	if (time < 10)
		std::cout << "0" << time;
	else
		std::cout << time;
}

Account::Account(void)
{
	_nbAccounts++;;
	_accountIndex = _nbAccounts - 1;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created\n";
}
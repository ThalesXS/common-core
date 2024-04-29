/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:33:35 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/28 19:14:49 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

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

}

Account::Account(int initial_deposit)
{
	_nbAccounts++;;
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::~Account(void)
{

}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount)
		return (false);
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		return (true);
	}
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	displayStatus(void) const
{

}

void	Account::_displayTimestamp(void)
{
	time_t timer;
	struct tm y2k = {0};
	double seconds;

	y2k.tm_hour = 0;
	y2k.tm_year = 100;
	y2k.tm_min = 0;
	y2k.tm_mon = 0;
	y2k.tm_sec = 0;
	y2k.tm_mday = 1;
	time(&timer);
	seconds = difftime(timer, mktime(&y2k));
	std::cout << seconds;
}
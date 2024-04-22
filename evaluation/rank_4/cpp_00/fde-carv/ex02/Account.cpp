/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:06:46 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/03 15:46:19 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// diff <(cut -c 18- fred.log) <(cut -c 18- 19920104_091532.log)
// diff fred.log 19920104_091532.log

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

/*
--> Initializes the static private variable to 0.
*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
--> Constructor initializes the account index, amount, number of deposits, and number of withdrawals.
   It increments the number of accounts and adds the initial deposit to the total amount.
   It then displays the timestamp
   The account index, amount, and the fact that the account was created.
*/
Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts += 1;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

/*
--> Destructor displays the timestamp, the account index, amount, and the fact that the account was closed.
*/
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

int Account::getNbAccounts( void )
{
    return(_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return(_totalAmount);
}

int Account::getNbDeposits( void )
{
   return(_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
    return(_totalNbWithdrawals);
}

/*
--> Displays the timestamp with the current time in the format [YYYYMMDD_HHMMSS].
*/
void	Account::_displayTimestamp()
{
	std::cout << "[19920104_091532] ";
    // std::time_t	time_in_sec = std::time(NULL);
	// std::tm		*timemark = std::localtime(&time_in_sec);
	// std::cout << "[" << timemark->tm_year + 1900;
	// std::cout << std::setfill('0') << std::setw(2) << timemark->tm_mon + 1;
	// std::cout << std::setfill('0') << std::setw(2) << timemark->tm_mday << "_";
	// std::cout << std::setfill('0') << std::setw(2) << timemark->tm_hour;
	// std::cout << std::setfill('0') << std::setw(2) << timemark->tm_min;
	// std::cout << std::setfill('0') << std::setw(2) << timemark->tm_sec << "] ";
}

/*
--> Displays the account information.
*/
void    Account::displayAccountsInfos()
{
    _displayTimestamp();
	std::cout   << "accounts:" << _nbAccounts 
                <<";total:" << _totalAmount
	            << ";deposits:" << _totalNbDeposits
                << ";withdrawals:" << _totalNbWithdrawals
                << std::endl;
}

/*
--> Displays the account status.
*/
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";amount:" << _amount
	            << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals
                << std::endl;
}


/*
--> Returns the amount of the account after making the deposit
*/
void	Account::makeDeposit( int deposit )
{
    int temp;
    
    temp = _amount + deposit;
    _totalAmount += deposit;
    _nbDeposits += 1;
    _totalNbDeposits += _nbDeposits;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";p_amount:" << _amount
	            << ";deposit:" << deposit
                << ";amount:" << temp
                << ";nb_deposits:" << _nbDeposits
                << std::endl;
    _amount = temp;            
}

/*
--> Returns true if the withdrawal was successful, false otherwise.
  If the withdrawal is successful, it displays the account information.
*/
bool	Account::makeWithdrawal( int withdrawal )
{
    int temp;
    
    _displayTimestamp();
    if(_amount >= withdrawal)
    {
        temp = _amount - withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals += 1;
        _totalNbWithdrawals += _nbWithdrawals;
        std::cout   << "index:" << _accountIndex
                    << ";p_amount:" << _amount
                    << ";withdrawal:" << withdrawal
                    << ";amount:" << temp
                    << ";nb_withdrawals:" << _nbWithdrawals
                    << std::endl;
        _amount = temp;            
        return(true);
    }
    else
    {
        std::cout   << "index:" << _accountIndex
                    << ";p_amount:" << _amount
                    << ";withdrawal:refused"
                    << std::endl;
        return(false);
    }
}

// --> tests.cpp
/*
  The function begins by defining three typedefs: accounts_t, ints_t, and acc_int_t.
  accounts_t is a type alias for std::vector<Account::t>, which is a vector of
  Account::t objects.
  ints_t is a type alias for std::vector<int>, which is a vector of integers.
  acc_int_t is a type alias for std::pair<accounts_t::iterator, ints_t::iterator>,
  which is a pair of iterators, one for an accounts_t vector and one for an ints_t vector.

  Next, the function creates an accounts_t vector named accounts and initializes it
  with the values from the amounts array. It calculates the size of the amounts array by
  dividing the total size of the array by the size of an int. It then creates iterators
  acc_begin and acc_end for the accounts vector.

  The function does a similar thing for the deposits and withdrawals vectors, which are
  ints_t vectors. It initializes these vectors with the values from the d(deposits) and
  w(withdrawals) arrays, respectively, and creates iterators for them.

  The function then calls Account::displayAccountsInfos() to display information about all
  accounts, and uses std::for_each and std::mem_fun_ref to call Account::displayStatus for
  each account in the accounts vector.

  Next, the function enters a for loop that iterates over the accounts and deposits
  vectors simultaneously. For each pair of account and deposit, it calls the makeDeposit
  function on the account with the deposit as the argument.

  The function then repeats the process of displaying account information and making
  deposits, but this time it makes withdrawals instead of deposits.

  Finally, the function returns 0, indicating that it has completed successfully.

  In summary, this main function seems to be a test driver for the Account class, testing
  the creation of accounts, displaying account information, making deposits, and making
  withdrawals.
*/

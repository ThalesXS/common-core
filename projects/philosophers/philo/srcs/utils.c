/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:22:47 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/03 13:43:36 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	ft_atol(const char *str)
{
	long	i;
	int		neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		||str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * neg);
}

int	ft_which_fork(t_table *table, t_philo *philo)
{
	if (philo->id % 2 == 1)
		return (ft_odd_id(table, philo));
	else
	{
		pthread_mutex_lock(&philo->forks[philo->right_fork]);
		pthread_mutex_lock(&table->dead_mutex);
		if (table->dead)
		{
			pthread_mutex_unlock(&table->dead_mutex);
			pthread_mutex_unlock(&philo->forks[philo->right_fork]);
			return (0);
		}
		pthread_mutex_unlock(&table->dead_mutex);
		pthread_mutex_lock(&table->print);
		printf("%ld %d has taken a fork\n", ft_get_time() - table->start,
			philo->id);
		pthread_mutex_unlock(&table->print);
		pthread_mutex_lock(&philo->forks[philo->left_fork]);
	}
	return (1);
}

int	ft_odd_id(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->left_fork]);
	pthread_mutex_lock(&table->dead_mutex);
	if (table->dead)
	{
		pthread_mutex_unlock(&table->dead_mutex);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		return (0);
	}
	pthread_mutex_unlock(&table->dead_mutex);
	pthread_mutex_lock(&table->print);
	printf("%ld %d has taken a fork\n", ft_get_time() - table->start,
		philo->id);
	pthread_mutex_unlock(&table->print);
	pthread_mutex_lock(&philo->forks[philo->right_fork]);
	return (1);
}

void	ft_time_init(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->print);
	if (table->start == 0)
	{
		table->start = ft_get_time();
		while (i < table->nb_philo)
		{
			table->philo[i].last_eat = table->start;
			i++;
		}
	}
	pthread_mutex_unlock(&table->print);
}

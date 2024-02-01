/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:57:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/01 22:52:37 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;

	table = (t_table *)arg;
	pthread_mutex_lock(&table->print);
	philo = &table->philo[table->nb_threads];
	table->nb_threads++;
	pthread_mutex_unlock(&table->print);
	while (table->nb_threads < table->nb_philo)
		;
	pthread_mutex_lock(&table->print);
	table->start = ft_get_time();
	pthread_mutex_unlock(&table->print);
	philo->last_eat = table->start;
	while (1)
	{
		if (philo->state == THINK)
			ft_think(table, philo);
		else if (philo->state == EAT)
			ft_eat(table, philo);
		else if (philo->state == SLEEP)
			ft_sleep(table, philo);
		if (table->dead)
			return (NULL);
	}
	return (NULL);
}

void	ft_think(t_table *table, t_philo *philo)
{
	printf("%ld %d is thinking\n", ft_get_time() - table->start, philo->id);
	philo->state = EAT;
}

void	ft_eat(t_table *table, t_philo *philo)
{
	if (!ft_which_fork(table, philo))
		return ;
	printf("%ld %d has taken a fork\n", ft_get_time() - table->start, philo->id);
	printf("%ld %d is eating\n", ft_get_time() - table->start, philo->id);
	usleep(table->time_to_eat);
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&philo->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->forks[philo->right_fork]);
	philo->eat_count++;
	if (philo->eat_count == table->nb_eat)
		table->finished_threads++;
	philo->state = SLEEP;
}

void	ft_sleep(t_table *table, t_philo *philo)
{
	printf("%ld %d is sleeping\n", ft_get_time() - table->start, philo->id);
	usleep(table->time_to_sleep);
	philo->state = THINK;
}

void	*ft_end_threads(void *arg)
{
	t_table *table;
	t_philo *philo;
	int i;

	table = (t_table *) arg;
	philo = table->philo;
	i = 0;
	while (1)
	{
		if (ft_get_time() - (philo[i].last_eat + 5) > table->time_to_die)
		{
			printf("%ld %d died\n",  ft_get_time() - table->start - 5, philo[i].id);
			table->dead = 1;
			return (NULL);
		}
		else if (table->finished_threads == table->nb_philo)
		{
			table->dead = 1;
			return (NULL);
		}
		if (i < table->nb_philo - 1)
			i++;
		else
			i = 0;
	}
}

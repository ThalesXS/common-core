/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:32:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/03/20 18:40:23 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat_2(t_table *table, t_philo *philo)
{
	usleep(table->time_to_eat);
	pthread_mutex_lock(&table->dead_mutex);
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&table->dead_mutex);
	pthread_mutex_unlock(&philo->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->forks[philo->right_fork]);
	philo->eat_count++;
	if (philo->eat_count == table->nb_eat)
	{
		pthread_mutex_lock(&table->dead_mutex);
		table->finished_threads++;
		pthread_mutex_unlock(&table->dead_mutex);
	}
	philo->state = SLEEP;
}

void	ft_only_one(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->left_fork]);
	printf("%ld %d has taken a fork\n", ft_get_time() - table->start,
		philo->id);
	pthread_mutex_unlock(&philo->forks[philo->left_fork]);
	philo->state = DEAD;
}

int	ft_life_loop(t_table *table, t_philo *philo)
{
	if (philo->state == THINK)
		ft_think(table, philo);
	else if (philo->state == EAT)
		ft_eat(table, philo);
	else if (philo->state == SLEEP)
		ft_sleep(table, philo);
	pthread_mutex_lock(&table->dead_mutex);
	if (table->dead || philo->state == DEAD)
	{
		pthread_mutex_unlock(&table->dead_mutex);
		return (0);
	}
	pthread_mutex_unlock(&table->dead_mutex);
	return (1);
}

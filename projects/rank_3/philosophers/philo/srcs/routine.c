/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:57:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/03/20 18:39:08 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;
	int		loop;

	loop = 1;
	table = (t_table *)arg;
	pthread_mutex_lock(&table->print);
	philo = &table->philo[table->nb_threads];
	table->nb_threads++;
	pthread_mutex_unlock(&table->print);
	pthread_mutex_lock(&table->dead_mutex);
	ft_time_init(table);
	pthread_mutex_unlock(&table->dead_mutex);
	while (loop)
		loop = ft_life_loop(table, philo);
	return (NULL);
}

void	ft_think(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->dead_mutex);
	pthread_mutex_lock(&table->print);
	if (!table->dead)
		printf("%ld %d is thinking\n", ft_get_time() - table->start, philo->id);
	pthread_mutex_unlock(&table->print);
	pthread_mutex_unlock(&table->dead_mutex);
	usleep(1000);
	philo->state = EAT;
}

void	ft_eat(t_table *table, t_philo *philo)
{
	if (table->nb_philo == 1)
	{
		ft_only_one(table, philo);
		return ;
	}
	if (!ft_which_fork(table, philo))
		return ;
	pthread_mutex_lock(&table->dead_mutex);
	if (!table->dead)
	{
		pthread_mutex_lock(&table->print);
		printf("%ld %d has taken a fork\n", ft_get_time() - table->start,
			philo->id);
		printf("%ld %d is eating\n", ft_get_time() - table->start, philo->id);
		pthread_mutex_unlock(&table->print);
	}
	pthread_mutex_unlock(&table->dead_mutex);
	ft_eat_2(table, philo);
}

void	ft_sleep(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->dead_mutex);
	pthread_mutex_lock(&table->print);
	if (!table->dead)
		printf("%ld %d is sleeping\n", ft_get_time() - table->start, philo->id);
	pthread_mutex_unlock(&table->print);
	pthread_mutex_unlock(&table->dead_mutex);
	usleep(table->time_to_sleep);
	philo->state = THINK;
}

void	*ft_end_threads(void *arg)
{
	t_table	*table;
	t_philo	*philo;
	int		i;

	table = (t_table *) arg;
	philo = table->philo;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&table->dead_mutex);
		if (ft_get_time() - (philo[i].last_eat) > table->time_to_die
			&& philo[i].last_eat > 0)
			return (ft_died(table, philo));
		else if (table->finished_threads == table->nb_philo)
		{
			table->dead = 1;
			pthread_mutex_unlock(&table->dead_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&table->dead_mutex);
		if (i < table->nb_philo - 1)
			i++;
		else
			i = 0;
	}
}

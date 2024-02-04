/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:37:51 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/02 22:07:31 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_table(t_table *table, int argc, char **argv)
{
	int	i;

	i = 0;
	if (ft_check_arguments(argc, argv))
		return (1);
	table->nb_philo = ft_atol(argv[1]);
	table->nb_threads = 0;
	table->finished_threads = 0;
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (argc == 6)
		table->nb_eat = ft_atol(argv[5]);
	else
		table->nb_eat = -1;
	table->dead = 0;
	table->start = ft_get_time();
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	table->threads = malloc(sizeof(pthread_t) * table->nb_philo);
	if (!table->forks || !table->threads)
		return (1);
	pthread_mutex_init(&table->print, NULL);
	while (i < table->nb_philo)
		pthread_mutex_init(&table->forks[i++], NULL);
	return (0);
}

int	ft_init_philos(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philo)
		return (1);
	while (i < table->nb_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].eat_count = 0;
		if ((table->philo[i].id + table->philo[i].eat_count) % 2 == 0)
			table->philo[i].state = THINK;
		else
			table->philo[i].state = EAT;
		table->philo[i].left_fork = i;
		if (i == table->nb_philo - 1)
			table->philo[i].right_fork = 0;
		else
			table->philo[i].right_fork = (i + 1);
		table->philo[i].forks = table->forks;
		table->philo[i].last_eat = -1;
		i++;
	}
	return (0);
}

int	ft_init_threads(t_table *table)
{
	int			i;
	pthread_t	thread;

	i = 0;
	table->start = 0;
	pthread_mutex_init(&table->dead_mutex, NULL);
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->threads[i], NULL,
				ft_routine, (void *) table))
			return (1);
		i++;
	}
	pthread_create(&thread, NULL, ft_end_threads, (void *) table);
	pthread_join(thread, NULL);
	return (0);
}

int	ft_check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_only_digit(argv[i]))
			return (1);
		else if (atol(argv[i]) > INT_MAX || atol(argv[i]) < 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_only_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-'
			&& arg[i] != '+' && arg[i] != '\t' && arg[i] != '\n'
			&& arg[i] != '\v' && arg[i] != '\f' && arg[i] != '\r'
			&& arg[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:03:13 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/03 00:35:17 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (ft_init_table(&table, argc, argv))
	{
		printf("Error: Invalid arguments.\n");
		return (1);
	}
	if (ft_init_philos(&table))
		return (1);
	if (ft_init_threads(&table))
	{
		printf("Error: Could not create threads.\n");
		return (1);
	}
	ft_wait_threads(&table);
	ft_free_table(&table);
	return (0);
}

void	ft_wait_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
		pthread_join(table->threads[i++], NULL);
}

void	ft_free_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i++]);
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->dead_mutex);
	free(table->forks);
	free(table->threads);
	free(table->philo);
}

void	*ft_died(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->print);
	printf("%ld %d died\n", ft_get_time() - table->start,
		philo->id);
	pthread_mutex_unlock(&table->print);
	table->dead = 1;
	pthread_mutex_unlock(&table->dead_mutex);
	return (NULL);
}

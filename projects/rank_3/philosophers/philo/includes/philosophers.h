/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:39:57 by txisto-d          #+#    #+#             */
/*   Updated: 2024/03/20 18:33:31 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

//	====================		MACROS		====================

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DEAD 3
# define FORK 4

//	====================	STRUCTURES		====================

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				state;
	int				left_fork;
	int				right_fork;
	long			last_eat;
	pthread_mutex_t	*forks;
}					t_philo;

typedef struct s_table
{
	int				nb_philo;
	int				nb_threads;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				finished_threads;
	int				dead;
	long			start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
	pthread_t		*threads;
	t_philo			*philo;
}					t_table;

// ====================		UTILS				====================

long	ft_atol(const char *str);
long	ft_get_time(void);
int		ft_which_fork(t_table *table, t_philo *philo);
int		ft_odd_id(t_table *table, t_philo *philo);
void	ft_time_init(t_table *table);

// ====================		INITIALIZER			====================

int		ft_init_table(t_table *table, int argc, char **argv);
int		ft_init_philos(t_table *table);
int		ft_init_threads(t_table *table);
int		ft_check_arguments(int argc, char **argv);
int		ft_only_digit(char *arg);
// ====================		ROUTINE				====================

void	*ft_routine(void *arg);
void	ft_eat(t_table *table, t_philo *philo);
void	ft_sleep(t_table *table, t_philo *philo);
void	ft_think(t_table *table, t_philo *philo);
void	*ft_end_threads(void *arg);

// ====================		ROUTINE2			====================

void	ft_eat_2(t_table *table, t_philo *philo);
void	ft_only_one(t_table *table, t_philo *philo);
int		ft_life_loop(t_table *table, t_philo *philo);

// ====================		PHILOSOPHERS		====================

void	ft_wait_threads(t_table *table);
void	ft_free_table(t_table *table);
void	*ft_died(t_table *table, t_philo *philo);

#endif
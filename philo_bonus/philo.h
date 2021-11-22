/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:49:27 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/18 13:49:31 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <semaphore.h>

typedef struct s_group
{
	int				all_philos;
	int				starving_philos;
	int 			priority;
	struct s_group	*next;
}					t_group;

typedef struct s_philo
{
	int				position;
	long long		time_limit;
	int				*status;
	int				*is_starving;
	pthread_t 		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				amount;
	int 			amount_of_groups;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int 			must_eat_count;
	int				dead_philo;
	long 			start_time;
	pthread_mutex_t	monitor;
	t_philo			*philos;
	t_group			*groups;
	pid_t			*pids;
	sem_t			*sem;
	sem_t			*write;
}					t_data;

void		init_data(t_data **data, int argc, char **argv);
void		print_status(t_philo *philo, char *status);
void		print_dead(t_philo *philo);
long long	get_time(void);
void		ft_usleep(int time);

void		take_forks(t_philo *philo);
void		put_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

int			ft_atoi(const char *str);

#endif

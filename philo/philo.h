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
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

typedef struct s_group
{
	int				all_in_group;
	int				starving_philos;
	int				priority;
	struct s_group	*next;
}					t_group;

typedef struct s_philo
{
	int				position;
	uint64_t		time_limit;
	int				*status;
	int				*is_starving;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				amount;
	int				amount_of_groups;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				stop_simulation;
	uint64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	t_philo			*philos;
	t_group			*groups;
	pthread_t		control;
}					t_data;

int			check_arguments(int argc, char **argv);
t_data		*init_data(int argc, char **argv);
int			start_control(t_data *data);
void		*control(void *struct_data);
void		*control_count(void *struct_data);
void		print_status(t_philo *philo, char *status);
void		print_exit_status(t_data *data);
void		join_threads(t_data *data);
void		destroy_mutexes(t_data *data);
void		free_allocated_memory(t_data *data);

void		take_forks(t_philo *philo);
void		put_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

uint64_t	philo_atol(const char *str);
uint64_t	get_time(void);
void		ft_usleep(int time);

#endif

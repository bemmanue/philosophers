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
# include <signal.h>
# include <sys/types.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				position;
	uint64_t		time_limit;
	int				has_eaten;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				amount;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				stop_simulation;
	uint64_t		start_time;
	t_philo			*philos;
	pid_t			*pids;
	sem_t			*forks;
	sem_t			*write;
}					t_data;

int			check_arguments(int argc, char **argv);
t_data		*init_data(int argc, char **argv);

void		open_sems(t_data *data);
void		close_sems(t_data *data);

void		take_forks(t_philo *philo);
void		put_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

void		print_status(t_philo *philo, char *status);
void		print_exit_status(t_data *data, int status);

void		free_allocated_memory(t_data *data);
void		exit_processes(t_data *data);
void		kill_processes(t_data *data, int died_philo, int amount);

uint64_t	get_time(void);
void		ft_usleep(int time);
uint64_t	philo_atol(const char *str);

#endif

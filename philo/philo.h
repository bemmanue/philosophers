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

typedef struct s_control
{
	int 			first_group;
	int 			second_group;
	int 			third_group;
}					t_control;

typedef struct s_philo
{
	int				position;
	int				is_eating;
	long long		time_limit;
	int				*status;
	pthread_t 		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				amount;
	int 			groups;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int 			must_eat_count;
	long 			start_time;
	int				*priority;
	pthread_mutex_t	*forks;
	pthread_mutex_t	monitor;
	pthread_mutex_t	write;
	t_philo			*philos;
}					t_data;

void		init_data(t_data **data, int argc, char **argv);
void		print_status(t_philo *philo, char *status);
long long	get_time(void);
void		ft_usleep(int time);

void		take_forks(t_philo *philo);
void		put_forks(t_philo *philo);

void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

int			ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putlong_fd(long long n, int fd);
size_t		ft_strlen(const char *str);

#endif

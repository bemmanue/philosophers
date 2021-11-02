/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:41:41 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/20 19:41:47 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void	init_waiter(t_data *data)
//{
//	int	i;
//
//	i = 0;
//	data->waiter->forks_status = malloc(sizeof(int) * data->amount);
//	while (i < data->amount)
//		data->waiter->forks_status[i++] = 0;
//	data->waiter->philos = data->philos;
//}

void	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	while (i < data->amount)
		pthread_mutex_init(&data->eating[i++], NULL);
	pthread_mutex_init(&data->monitor, NULL);
	pthread_mutex_init(&data->write, NULL);
//	pthread_mutex_init(&data->waiter, NULL);
}

void	init_philos(t_data *data)
{
	int	left_neighbour;
	int	right_neighbour;
	int	i;

	i = 0;
	while (i < data->amount)
	{
		left_neighbour = (i + data->amount - 1) % data->amount;
		right_neighbour = (i + 1) % data->amount;
		data->philos[i].left_neighbour = (i + data->amount - 1) % data->amount;
		data->philos[i].right_neighbour = (i + 1) % data->amount;
		data->philos[i].position = i;
		data->philos[i].is_eating = 0;
		data->philos[i].current_time = 0;
		data->philos[i].time_limit = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->amount];
		data->philos[i].data = data;
		data->philos[i].eating = &data->eating[i];
//		data->philos[left_neighbour].eating = &data->eating[i];
//		data->philos[right_neighbour].eating = &data->eating[i];
		i++;
	}
}

void	init_data(t_data **data, int argc, char **argv)
{
	*data = malloc(sizeof(t_data));
	(*data)->amount = ft_atoi(argv[1]);
	(*data)->time_to_die = ft_atoi(argv[2]) * 1000;
	(*data)->time_to_eat = ft_atoi(argv[3]) * 1000;
	(*data)->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		(*data)->must_eat_count = ft_atoi(argv[5]);
	else
		(*data)->must_eat_count = 0;
	(*data)->philos = malloc(sizeof(t_philo) * (*data)->amount);
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->amount);
	(*data)->eating = malloc(sizeof(pthread_mutex_t) * (*data)->amount);
//	(*data)->waiter = malloc(sizeof(t_waiter) * 1);
//	init_waiter(*data);
	init_mutexes(*data);
	init_philos(*data);
}

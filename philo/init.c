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

void	init_priority(t_data *data)
{
	data->priority[0] = 1;
	data->priority[1] = 0;
	if (data->groups == 3)
		data->priority[2] = 0;
}

void	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->monitor, NULL);
	pthread_mutex_init(&data->write, NULL);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		data->philos[i].position = i;
		data->philos[i].is_eating = 0;
		data->philos[i].time_limit = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->amount];
		data->philos[i].data = data;
		if (data->groups == 3 && i == data->amount - 1)
			data->philos[i].status = &data->priority[2];
		else if (i % 2 == 1)
			data->philos[i].status = &data->priority[1];
		else
			data->philos[i].status = &data->priority[0];
		i++;
	}
}

void	init_data(t_data **data, int argc, char **argv)
{
	*data = malloc(sizeof(t_data));
	(*data)->amount = ft_atoi(argv[1]);
	if ((*data)->amount % 2 == 0)
		(*data)->groups = 2;
	else
		(*data)->groups = 3;
	(*data)->time_to_die = ft_atoi(argv[2]) * 1000;
	(*data)->time_to_eat = ft_atoi(argv[3]) * 1000;
	(*data)->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		(*data)->must_eat_count = ft_atoi(argv[5]);
	else
		(*data)->must_eat_count = 0;
	(*data)->philos = malloc(sizeof(t_philo) * (*data)->amount);
	(*data)->priority = malloc(sizeof(int) * (*data)->groups);
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->amount);
	init_priority(*data);
	init_mutexes(*data);
	init_philos(*data);
}

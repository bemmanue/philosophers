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

void	init_groups(t_data *data)
{
	int	i;
	int	last_group;

	i = 0;
	last_group = data->amount_of_groups - 1;
	while (i < data->amount_of_groups)
	{
		data->groups[i].priority = 0;
		if (data->amount_of_groups == 3 && i == last_group)
			data->groups[i].all_in_group = 1;
		else
			data->groups[i].all_in_group = data->amount / 2;
		data->groups[i].starving_philos = data->groups[i].all_in_group;
		data->groups[i].next = &data->groups[(i + 1) % data->amount_of_groups];
		i++;
	}
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->write, NULL))
		return (1);
	return (0);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		data->philos[i].position = i;
		data->philos[i].time_limit = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->amount];
		data->philos[i].data = data;
		if (data->amount_of_groups == 3 && i == data->amount - 1)
		{
			data->philos[i].status = &data->groups[2].priority;
			data->philos[i].is_starving = &data->groups[2].starving_philos;
		}
		else
		{
			data->philos[i].status = &data->groups[i % 2].priority;
			data->philos[i].is_starving = &data->groups[i % 2].starving_philos;
		}
		i++;
	}
}

int	init_data(t_data **data, int argc, char **argv)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (1);
	(*data)->amount = (int)philo_atol(argv[1]);
	(*data)->amount_of_groups = 2 + ((*data)->amount % 2);
	(*data)->time_to_die = (int)philo_atol(argv[2]) * 1000;
	(*data)->time_to_eat = (int)philo_atol(argv[3]) * 1000;
	(*data)->time_to_sleep = (int)philo_atol(argv[4]) * 1000;
	if (argc == 6)
		(*data)->must_eat_count = (int)philo_atol(argv[5]);
	else
		(*data)->must_eat_count = 0;
	(*data)->stop_simulation = 0;
	(*data)->philos = malloc(sizeof(t_philo) * (*data)->amount);
	(*data)->groups = malloc(sizeof(t_group) * (*data)->amount_of_groups);
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->amount);
	if ((!(*data)->philos || !(*data)->groups || !(*data)->forks)
		& init_mutexes(*data))
	{
		free_allocated_memory(*data);
		return (1);
	}
	init_groups(*data);
	init_philos(*data);
	return (0);
}

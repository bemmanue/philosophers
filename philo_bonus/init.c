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
	int last_group;

	i = 0;
	last_group = data->amount_of_groups - 1;
	while (i < data->amount_of_groups)
	{
		data->groups[i].priority = 0;
		if (data->amount_of_groups == 3 && i == last_group)
			data->groups[i].all_philos = 1;
		else
			data->groups[i].all_philos = data->amount / 2;
		data->groups[i].starving_philos = data->groups[i].all_philos;
		data->groups[i].next = &data->groups[(i + 1) % data->amount_of_groups];
		i++;
	}
	data->groups[0].priority = 1;
}

void	init_mutexes(t_data *data)
{
	pthread_mutex_init(&data->monitor, NULL);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		data->philos[i].position = i;
		data->philos[i].time_limit = 0;
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

void	init_data(t_data **data, int argc, char **argv)
{
	*data = malloc(sizeof(t_data));
	(*data)->amount = ft_atoi(argv[1]);
	(*data)->amount_of_groups = 2 + ((*data)->amount % 2);
	(*data)->time_to_die = ft_atoi(argv[2]) * 1000;
	(*data)->time_to_eat = ft_atoi(argv[3]) * 1000;
	(*data)->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		(*data)->must_eat_count = ft_atoi(argv[5]);
	else
		(*data)->must_eat_count = 0;
	(*data)->dead_philo = 0;
	(*data)->philos = malloc(sizeof(t_philo) * (*data)->amount);
	(*data)->groups = malloc(sizeof(t_group) * (*data)->amount_of_groups);
	(*data)->pids = malloc(sizeof(pid_t) * (*data)->amount);
	init_groups(*data);
	init_philos(*data);
}

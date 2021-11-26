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

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		data->philos[i] = malloc(sizeof(t_philo));
		if (!data->philos[i])
		{
			free_allocated_memory(data);
			return ;
		}
		data->philos[i]->position = i;
		data->philos[i]->time_limit = 0;
		data->philos[i]->data = data;
		i++;
	}
}

t_data	*init_data(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->amount = (int)philo_atol(argv[1]);
	data->time_to_die = (int)philo_atol(argv[2]) * 1000;
	data->time_to_eat = (int)philo_atol(argv[3]) * 1000;
	data->time_to_sleep = (int)philo_atol(argv[4]) * 1000;
	if (argc == 6)
		data->must_eat_count = (int)philo_atol(argv[5]);
	else
		data->must_eat_count = 0;
	data->stop_simulation = 0;
	data->philos = malloc(sizeof(t_philo *) * data->amount);
	data->pids = malloc(sizeof(pid_t) * data->amount);
	if (!data->philos)
	{
		free_allocated_memory(data);
		return (NULL);
	}
	init_philos(data);
	return (data);
}

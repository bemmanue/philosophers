/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:36:03 by bemmanue          #+#    #+#             */
/*   Updated: 2021/11/24 19:38:32 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_allocated_memory(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->groups)
		free(data->groups);
	if (data->forks)
		free(data->forks);
	free(data);
}

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(&data->write);
	pthread_mutex_destroy(&data->write);
	while (i < data->amount)
	{
		pthread_mutex_unlock(&data->forks[i]);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	pthread_join(data->control, NULL);
	i = 0;
	while (i < data->amount)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

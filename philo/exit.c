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

void	free_data(t_data *data)
{
	free(data->philos);
	free(data->groups);
	free(data->forks);
	free(data);
}

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	pthread_join(data->eating_control, NULL);
	while (i < data->amount)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

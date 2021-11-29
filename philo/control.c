/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:54:31 by bemmanue          #+#    #+#             */
/*   Updated: 2021/11/24 15:54:33 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*control_count(void *struct_data)
{
	t_data	*data;
	t_group	*group;
	int		times_to_eat;

	data = struct_data;
	times_to_eat = data->must_eat_count * data->amount_of_groups;
	group = &data->groups[0];
	group->priority = 1;
	while (times_to_eat > 0 && !data->stop_simulation)
	{
		ft_usleep(5000);
		if (group->starving_philos <= 0)
		{
			group->priority = 0;
			group->starving_philos = group->all_in_group;
			group = group->next;
			group->priority = 1;
			times_to_eat--;
			if (times_to_eat == 0)
				data->stop_simulation = -1;
		}
	}
	return (NULL);
}

void	*control(void *struct_data)
{
	t_data	*data;
	t_group	*group;

	data = struct_data;
	group = &data->groups[0];
	group->priority = 1;
	while (!data->stop_simulation)
	{
		ft_usleep(5000);
		if (group->starving_philos <= 0)
		{
			group->priority = 0;
			group->starving_philos = group->all_in_group;
			group = group->next;
			group->priority = 1;
		}
	}
	return (NULL);
}

int	start_control(t_data *data)
{
	int		check;

	if (data->must_eat_count)
		check = pthread_create(&data->control, NULL, &control_count, data);
	else
		check = pthread_create(&data->control, NULL, &control, data);
	if (check)
		return (1);
	return (0);
}

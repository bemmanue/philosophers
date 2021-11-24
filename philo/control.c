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

void	*control(void *struct_data)
{
	t_data	*data;
	t_group	*group;

	data = struct_data;
	group = &data->groups[0];
	while (!data->dead_philo)
	{
		group->priority = 1;
		if (group->starving_philos <= 0)
		{
			group->priority = 0;
			group->starving_philos = group->all_in_group;
			group = group->next;
		}
		ft_usleep(5000);
	}
	return (NULL);
}


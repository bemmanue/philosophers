/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sems.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:01:59 by bemmanue          #+#    #+#             */
/*   Updated: 2021/11/29 17:02:01 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	open_sems(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("write");
	data->forks = sem_open("forks", O_CREAT, 0777, data->amount);
	data->write = sem_open("write", O_CREAT, 0777, 1);
	if (data->forks == SEM_FAILED || data->write == SEM_FAILED)
	{
		free_allocated_memory(data);
		write(2, "\033[22;33mError\n", 14);
		exit(0);
	}
}

void	close_sems(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->write);
}

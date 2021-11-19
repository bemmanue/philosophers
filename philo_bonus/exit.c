/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:40:39 by bemmanue          #+#    #+#             */
/*   Updated: 2021/11/19 14:40:41 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_all(t_data *data)
{
	int i;

	i = 0;
	while (i < data->amount)
	{
		kill(data->pids[i], SIGTERM);
	}
	sem_close(data->sem);
}

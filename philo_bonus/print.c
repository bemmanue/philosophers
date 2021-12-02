/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:37:30 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/29 13:37:32 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_exit_status(t_data *data, int status)
{
	if (status == 0)
		printf("\033[22;32m%-20lld all have eaten\n",
			get_time() - data->start_time);
	if (status > 0)
		printf("\033[22;31m%-20lld %d is dead\n",
			get_time() - data->start_time, status);
}

void	print_status(t_philo *philo, char *status)
{
	sem_wait(philo->data->write);
	printf("%-20lld %d %s", get_time() - philo->data->start_time,
		philo->position + 1, status);
	sem_post(philo->data->write);
}

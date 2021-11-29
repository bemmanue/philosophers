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

void	print_exit_status(t_data *data)
{
	if (data->stop_simulation < 0)
		printf("\033[22;34m%-10lld all have eaten\n",
			get_time() - data->start_time);
	else if (data->stop_simulation > 0)
		printf("\033[22;34m%-10lld %d is dead\n",
			get_time() - data->start_time, data->stop_simulation);
}

void	print_status(t_philo *philo, char *status)
{
	if (philo->data->stop_simulation)
		return ;
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->stop_simulation)
		return ;
	printf("%-10lld %d %s",
		get_time() - philo->data->start_time, philo->position + 1, status);
	pthread_mutex_unlock(&philo->data->write);
}

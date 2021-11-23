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

void	print_death(t_philo *philo)
{
	printf("\033[22;34m%-10lld %d is dead\n",
		get_time() - philo->data->start_time, philo->position + 1);
}

void	print_status(t_philo *philo, char *status)
{
	if (philo->data->dead_philo)
		return ;
	pthread_mutex_lock(&philo->data->write);
	printf("%-10lld %d %s",
		get_time() - philo->data->start_time, philo->position + 1, status);
	pthread_mutex_unlock(&philo->data->write);
}
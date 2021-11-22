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

//"\033[22;34mHello, world!\033[0m"

void	print_dead(t_philo *philo)
{
	sem_wait(philo->data->write);
	printf("%-10lld %d is dead\n", get_time() - philo->data->start_time,
		philo->position + 1);
	sem_post(philo->data->write);
}

void	print_status(t_philo *philo, char *status)
{
	sem_wait(philo->data->write);
	printf("%-10lld %d %s", get_time() - philo->data->start_time,
		philo->position + 1, status);
	sem_post(philo->data->write);
}
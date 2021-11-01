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

void	print_status(t_philo *philo, char *status)
{
	struct timeval	get_time;

	gettimeofday(&get_time, NULL);
	philo->current_time = (get_time.tv_usec - philo->data->start_time) / 1000;

	pthread_mutex_lock(&philo->data->write);
	ft_putlong_fd(philo->current_time, 1);
//	ft_putstr_fd("     ", 1);
//	ft_putlong_fd(philo->current_time, 1);
	ft_putstr_fd("     ", 1);
	ft_putlong_fd(get_time.tv_usec, 1);
	ft_putstr_fd("     ", 1);
	ft_putnbr_fd(philo->position + 1, 1);
	ft_putstr_fd(status, 1);
	pthread_mutex_unlock(&philo->data->write);
}
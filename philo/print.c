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

void	print_status(t_data *data, int philo, char *status)
{
	pthread_mutex_lock(&data->write);
	ft_putlong_fd(get_time() - data->start_time, 1);
	ft_putstr_fd("     ", 1);
	ft_putnbr_fd(philo, 1);
	ft_putstr_fd(status, 1);
	pthread_mutex_unlock(&data->write);
}
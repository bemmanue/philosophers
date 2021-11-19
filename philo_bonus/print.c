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
	printf("%-10lld %d is dead\n", get_time() - philo->data->start_time, philo->position + 1);
//	ft_putlong_fd(get_time() - philo->data->start_time, 1);
//	ft_putstr_fd("     ", 1);
//	ft_putnbr_fd(philo->position + 1, 1);
//	ft_putstr_fd(" is dead\n", 1);
}

void	print_status(t_philo *philo, char *status)
{
	sem_wait(philo->data->write);
	printf("%-10lld %d %s", get_time() - philo->data->start_time, philo->position + 1, status);
//	ft_putlong_fd(get_time() - philo->data->start_time, 1);
//	ft_putstr_fd("     ", 1);
//	ft_putnbr_fd(philo->position + 1, 1);
//	ft_putstr_fd(status, 1);
	sem_post(philo->data->write);
}
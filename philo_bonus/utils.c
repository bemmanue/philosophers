/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:45:22 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/18 14:45:25 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	philo_atol(const char *str)
{
	uint64_t	nbr;
	int			dgt;

	nbr = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		nbr *= 10;
		dgt = *str++ - 48;
		nbr += dgt;
	}
	return (nbr);
}

uint64_t	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	ft_usleep(int time)
{
	uint64_t	current_time;
	uint64_t	finish_time;

	finish_time = get_time() + time / 1000;
	current_time = get_time();
	while (current_time < finish_time)
	{
		usleep(100);
		current_time = get_time();
	}
}

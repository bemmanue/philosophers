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

long long	philo_atol(const char *str)
{
	long	nbr;
	int		dgt;

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

int	ft_atoi(const char *str)
{
	int	min;
	int	nbr;
	int	dgt;

	min = 0;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			min++;
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		dgt = *str++ - 48;
		nbr += dgt;
	}
	if (min)
		nbr = -nbr;
	return (nbr);
}

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	ft_usleep(int time)
{
	long long	current_time;
	long long	finish_time;

	finish_time = get_time() + time / 1000;
	current_time = get_time();
	while (current_time < finish_time)
	{
		usleep(100);
		current_time = get_time();
	}
}
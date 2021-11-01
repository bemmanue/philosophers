/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:11:10 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/26 18:11:12 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	eat(t_philo *philo)
{
//	struct timeval	get_time;
//
//	gettimeofday(&get_time, NULL);
//	philo->time_limit = get_time.tv_usec + philo->data->time_to_die;

	philo->is_eating = 1;
	print_status(philo, " is eating\n");
	usleep(philo->data->time_to_eat);
}

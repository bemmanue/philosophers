/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:13:51 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/26 17:13:54 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	permission(t_data *data, t_philo *philo)
{
	int	left_neighbour;
	int	right_neighbour;

	left_neighbour = (philo->position + data->amount - 1) % data->amount;
	right_neighbour = (philo->position + 1) % data->amount;
	if (data->philos[left_neighbour].is_eating
		|| data->philos[right_neighbour].is_eating)
		return (0);
	if (philo->time_limit > data->philos[left_neighbour].time_limit ||
	philo->time_limit > data->philos[right_neighbour].time_limit)
		return (0);
	return (1);
}

void	take_forks(t_philo *philo)
{
//	if (!permission(philo->data, philo))
//	pthread_mutex_lock(philo->eating);
//	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, " has taken a fork\n");

		pthread_mutex_lock(philo->left_fork);
		print_status(philo, " has taken a fork\n");
//	}
//	pthread_mutex_unlock(philo->eating);
//	pthread_mutex_unlock(&philo->data->waiter);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}



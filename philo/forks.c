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

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("philosopher %d has taken a fork\n", philo->position + 1);
	pthread_mutex_lock(philo->left_fork);
	printf("philosopher %d has taken a fork\n", philo->position + 1);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("philosopher %d is sleeping\n", philo->position + 1);
	usleep(philo->data->time_to_sleep);
	printf("philosopher %d is thinking\n", philo->position + 1);
}

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
	while ((*philo->status) == 0)
		ft_usleep(1);
	pthread_mutex_lock(philo->left_fork);
	print_status(philo->data, philo->position + 1, " has taken a fork\n");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo->data, philo->position + 1, " has taken a fork\n");
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

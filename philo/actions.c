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

void	take_forks(t_philo *philo)
{
	if (philo->data->dead_philo)
		return ;
	while (!(*philo->status))
		ft_usleep(philo->data->time_to_eat / 10);
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, " has taken a fork\n");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, " has taken a fork\n");
}

void	eating(t_philo *philo)
{
	if (philo->data->dead_philo)
		return ;
	philo->time_limit = get_time() + philo->data->time_to_die / 1000;
	(*philo->is_starving)--;
	print_status(philo, " is eating\n");
	ft_usleep(philo->data->time_to_eat);
}

void	put_forks(t_philo *philo)
{
	if (philo->data->dead_philo)
		return ;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	if (philo->data->dead_philo)
		return ;
	print_status(philo, " is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	if (philo->data->dead_philo)
		return ;
	print_status(philo, " is thinking\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
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
	if (philo->data->stop_simulation)
		return ;
	while (!(*philo->status))
	{
		if (philo->data->stop_simulation)
			return ;
		ft_usleep(5000);
	}
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, " has taken a fork\n");
	if (philo->data->amount == 1)
	{
		ft_usleep(philo->data->time_to_die + 1000);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, " has taken a fork\n");
}

void	eating(t_philo *philo)
{
	if (philo->data->stop_simulation)
		return ;
	philo->time_limit = get_time() + philo->data->time_to_die / 1000;
	(*philo->is_starving)--;
	print_status(philo, " is eating\n");
	ft_usleep(philo->data->time_to_eat);
}

void	put_forks(t_philo *philo)
{
	if (philo->data->stop_simulation)
		return ;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	if (philo->data->stop_simulation)
		return ;
	print_status(philo, " is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	if (philo->data->stop_simulation)
		return ;
	print_status(philo, " is thinking\n");
}

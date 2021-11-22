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
//	while (!(*philo->status))
//			ft_usleep(philo->data->time_to_eat / 3);
	sem_wait(philo->data->sem);
	sem_wait(philo->data->sem);
	print_status(philo, " has taken a fork\n");
	print_status(philo, " has taken a fork\n");
}

void	put_forks(t_philo *philo)
{
	sem_post(philo->data->sem);
	sem_post(philo->data->sem);
}

void	eating(t_philo *philo)
{
	philo->time_limit = get_time() + philo->data->time_to_die / 1000;
	(*philo->is_starving)--;
	print_status(philo, " is eating\n");
	ft_usleep(philo->data->time_to_eat);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, " is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_status(philo, " is thinking\n");
}
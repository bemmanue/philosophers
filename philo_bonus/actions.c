/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.                                           :+:      :+:    :+:   */
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
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	print_status(philo, " has taken a fork\n");
	print_status(philo, " has taken a fork\n");
}

void	eating(t_philo *philo)
{
	philo->has_eaten++;
	philo->time_limit = get_time() + philo->data->time_to_die / 1000;
	print_status(philo, " is eating\n");
	ft_usleep(philo->data->time_to_eat);
}

void	put_forks(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	if (philo->data->must_eat_count > 0
		&& philo->has_eaten >= philo->data->must_eat_count)
		exit(0);
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

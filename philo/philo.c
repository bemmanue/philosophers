/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:49:17 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/18 13:49:20 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *struct_philo)
{
	t_philo		*philo;
	long long	current_time;

	philo = struct_philo;
	while (!philo->data->dead_philo)
	{
		current_time = get_time();
		if (current_time > philo->time_limit)
		{
			philo->data->dead_philo = 1;
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			print_death(philo);
			break ;
		}
		ft_usleep(5000);
	}
	pthread_mutex_unlock(&philo->data->write);
	pthread_mutex_destroy(&philo->data->write);
	return (NULL);
}

void	*routine(void *struct_philo)
{
	t_philo		*philo;
	pthread_t	pthread;

	philo = struct_philo;
	philo->time_limit = get_time() + philo->data->time_to_die / 1000;
	pthread_create(&pthread, NULL, &monitor, philo);
	pthread_detach(pthread);
	while (!philo->data->dead_philo)
	{
		take_forks(philo);
		eating(philo);
		put_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

int	start_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	data->start_time = get_time();
	while (i < data->amount)
	{
		philo = &data->philos[i];
		if (pthread_create(&philo->thread, NULL, &routine, philo))
			return (1);
		i++;
	}
	return (0);
}

int	start_philosophers(int argc, char **argv)
{
	t_data	*data;

	if (init_data(&data, argc, argv))
		return (1);
	if (pthread_create(&data->eating_control, NULL, &control, data))
		return (1);
	if (start_threads(data))
		return (1);
	join_threads(data);
	destroy_mutexes(data);
	free_data(data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_arguments(argc, argv))
	{
		printf("Error: wrong arguments\n");
		return (1);
	}
	if (start_philosophers(argc, argv))
	{
		printf("Unexpected error\n");
		return (1);
	}
	return (0);
}

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
	t_philo			*philo;
	long long		current_time;

	philo = struct_philo;
	while (1)
	{
		pthread_mutex_lock(&philo->data->monitor);
		current_time = get_time();
		if (!philo->is_eating && current_time > philo->time_limit)
		{
			print_status(philo, " is dead\n");
			exit(0);
		}
		pthread_mutex_unlock(&philo->data->monitor);
	}
	return (NULL);
}

void	*routine(void *struct_philo)
{
	t_philo		*philo;
	pthread_t	pthread;

	philo = struct_philo;
	pthread_create(&pthread, NULL, &monitor, philo);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
	}
	return (NULL);
}

void	start_threads(t_data *data)
{
	pthread_t		pthread;
	t_philo			*philo;

	int i = 0;
	data->start_time = get_time();
	while (i < data->amount)
	{
		pthread = data->philos[i].thread;
		philo = (void*)(&data->philos[i]);
		pthread_create(&pthread, NULL, &routine, philo);
		philo->current_time = data->start_time;
		philo->time_limit = philo->current_time + data->time_to_die / 1000;
		pthread_detach(pthread);
		i++;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
	{
		printf("wrong arguments\n");
		return (0);
	}
	init_data(&data, argc, argv);
	start_threads(data);
	sleep (200);
	return (0);
}

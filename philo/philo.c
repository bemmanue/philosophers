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

void	*routine(void *struct_philo)
{
	t_philo			*philo;

	philo = struct_philo;
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
	pthread_t	pthread;
	void		*philo;

	int i = 0;
	while (i < data->amount)
	{
		pthread = data->philos[i].thread;
		philo = (void*)(&data->philos[i]);
		pthread_create(&pthread, NULL, &routine, philo);
//		pthread_detach(pthread);
//		pthread_join(pthread, NULL);
		i++;
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

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

void	*routine(void *philo_v)
{
	(void)philo_v;
	return (NULL);
}

void	start_threads(t_data *data)
{
	pthread_t	pthread;
	void		*philo;

	philo = (void*)(&data->philos[0]);
	pthread_create(&pthread, NULL, &routine, philo);
	pthread_detach(pthread);

	philo = (void*)(&data->philos[1]);
	pthread_create(&pthread, NULL, &routine, philo);
	pthread_detach(pthread);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (0);
	init_data(&data, argc, argv);
	start_threads(&data);
	return (0);
}

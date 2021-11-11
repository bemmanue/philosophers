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

void	*control_2(void *struct_data)
{
	t_data	*data;
	t_group	*group;
	int		i;

	data = struct_data;
	group = &data->groups[0];
	i = data->must_eat_count * data->amount_of_groups;
	while (!data->dead_philo && i > 0)
	{
		if (group->priority == 1 && group->starving_philos == 0)
		{
			group->priority = 0;
			group->starving_philos = group->all_philos;
			group->next->priority = 1;
			group = group->next;
			i--;
		}
	}
	return (NULL);
}

void	*control(void *struct_data)
{
	t_data	*data;
	t_group	*group;

	data = struct_data;
	group = &data->groups[0];
	while (!data->dead_philo)
	{
		if (group->starving_philos <= 0)
		{
			group->priority = 0;
			group->starving_philos = group->all_philos;
			group->next->priority = 1;
			group = group->next;
		}
		ft_usleep(5000);
	}
	return (NULL);
}

void	*monitor(void *struct_philo)
{
	t_philo		*philo;
	long long	current_time;

	philo = struct_philo;
	while (1)
	{
		current_time = get_time();
		if (current_time > philo->time_limit)
		{
			print_dead(philo);
			philo->data->dead_philo = philo->position + 1;
			break;
		}
		ft_usleep(5000);
	}
	return (NULL);
}

void	*routine(void *struct_philo)
{
	t_philo		*philo;
	pthread_t	pthread;

	philo = struct_philo;
	philo->time_limit = get_time() + philo->data->time_to_die / 1000;
	pthread_create(&pthread, NULL, &monitor, philo);
	while (1)
	{
		take_forks(philo);
		eating(philo);
		put_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	start_threads(t_data *data)
{
	pthread_t	pthread;
	t_philo		*philo;

	int i = 0;
	if (!data->must_eat_count)
		pthread_create(&pthread, NULL, &control, data);
	else
		pthread_create(&pthread, NULL, &control_2, data);
	data->start_time = get_time();
	while (i < data->amount)
	{
		philo = &data->philos[i];
		pthread_create(&philo->thread, NULL, &routine, philo);
		pthread_detach(data->philos[i].thread);
		i++;
//		ft_usleep(1000);
	}
	pthread_join(pthread, NULL);
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
	return (0);
}

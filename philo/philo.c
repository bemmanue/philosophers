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

void	*control_count(void *struct_data)
{
	t_data	*data;
	t_group	*group;
	int		i;

	data = struct_data;
	group = &data->groups[0];
	i = data->must_eat_count * data->amount_of_groups;
	while (!data->dead_philo && i > 0)
	{
		if (group->starving_philos <= 0)
		{
			group->priority = 0;
			group->starving_philos = group->all_philos;
			group->next->priority = 1;
			group = group->next;
			i--;
		}
		ft_usleep(5000);
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
	while (!philo->data->dead_philo)
	{
		current_time = get_time();
		if (current_time > philo->time_limit)
		{
			philo->data->dead_philo = 1;
			print_death(philo);
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

void	start_threads(t_data *data)
{
	pthread_t	eating_control;
	t_philo		*philo;
	int 		i;

	i = 0;
	if (!data->must_eat_count)
		pthread_create(&eating_control, NULL, &control, data);
	else
		pthread_create(&eating_control, NULL, &control_count, data);
	data->start_time = get_time();
	while (i < data->amount)
	{
		philo = &data->philos[i];
		pthread_create(&philo->thread, NULL, &routine, philo);
		i++;
	}
	pthread_join(eating_control, NULL);
	i = 0;
	while (i < data->amount)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	check_arguments(int argc, char **argv)
{
	int		i;
	long	check;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (i < argc)
	{
		check = philo_atol(argv[i]);
		if (check < 0 || check > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!check_arguments(argc, argv))
	{
		printf("Error: wrong arguments\n");
		return (0);
	}
	init_data(&data, argc, argv);
	start_threads(data);
	return (0);
}

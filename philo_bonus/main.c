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
	uint64_t	current_time;

	philo = struct_philo;
	while (1)
	{
		current_time = get_time();
		if (current_time > philo->time_limit)
		{
			sem_wait(philo->data->write);
			print_exit_status(philo->data, philo->position + 1);
			exit(philo->position + 1);
		}
		ft_usleep(4000);
	}
	return (NULL);
}

void	*routine(void *struct_philo)
{
	t_philo		*philo;
	pthread_t	pthread;

	philo = struct_philo;
	philo->time_limit = get_time() + philo->data->time_to_die / 1000;
	if (pthread_create(&pthread, NULL, &monitor, philo)
		|| pthread_detach(pthread))
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
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

void	start_processes(t_data *data)
{
	int	pid;
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->amount)
	{
		pid = fork();
		if (pid == 0)
			routine(&data->philos[i]);
		data->pids[i] = pid;
		ft_usleep(2000);
		i++;
	}
}

int	start_philosophers(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	if (!data)
	{
		free_allocated_memory(data);
		return (1);
	}
	open_sems(data);
	start_processes(data);
	exit_processes(data);
	close_sems(data);
	free_allocated_memory(data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_arguments(argc, argv))
	{
		write(2, "Error: wrong arguments\n", 23);
		return (1);
	}
	if (start_philosophers(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

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
	while (1)
	{
		current_time = get_time();
		if (current_time > philo->time_limit)
		{
			sem_wait(philo->data->write);
			philo->data->stop_simulation = philo->position + 1;
			print_exit_status(philo->data);
			exit(0);
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
			routine(data->philos[i]);
		data->pids[i] = pid;
		ft_usleep(2000);
		i++;
	}
}

void	set_sems(t_data *data)
{
	sem_unlink("sem");
	sem_unlink("write");
	data->forks = sem_open("sem", O_CREAT, 0777, data->amount);
	data->write = sem_open("write", O_CREAT, 0777, 1);
}

int	start_philosophers(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	if (!data)
		return (1);
	set_sems(data);
	start_processes(data);
	exit_processes(data);
	sem_close(data->forks);
	sem_close(data->write);
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

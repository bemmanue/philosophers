/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:57:44 by bemmanue          #+#    #+#             */
/*   Updated: 2021/12/01 21:18:37 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_allocated_memory(t_data *data)
{
	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->pids)
			free(data->pids);
		free(data);
	}
}

void	kill_processes(t_data *data, int died_philo, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (data->pids[i] != died_philo)
			kill(data->pids[i], SIGKILL);
		i++;
	}
}

void	exit_processes(t_data *data)
{
	int	pid;
	int	status;
	int	i;

	pid = waitpid(0, &status, 0);
	i = 1;
	while (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		if (i == data->amount)
		{
			print_exit_status(data, 0);
			break ;
		}
		i++;
		waitpid(0, &status, 0);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status))
		kill_processes(data, pid, data->amount);
}

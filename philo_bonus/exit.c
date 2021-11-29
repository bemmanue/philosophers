/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:57:44 by bemmanue          #+#    #+#             */
/*   Updated: 2021/11/26 19:57:46 by bemmanue         ###   ########.fr       */
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
			print_exit_status(data, -1);
			break ;
		}
		i++;
		waitpid(0, &status, 0);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status))
	{
		while (i < data->amount)
		{
			if (data->pids[i] != pid)
				kill(data->pids[i], SIGKILL);
			i++;
		}
	}
}

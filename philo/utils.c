/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:45:22 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/18 14:45:25 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	min;
	int	nbr;
	int	dgt;

	min = 0;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			min++;
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		dgt = *str++ - 48;
		nbr += dgt;
	}
	if (min)
		nbr = -nbr;
	return (nbr);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd > 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int len;

	if (!s || fd < 1)
		return ;
	i = 0;
	len = (int)ft_strlen(s);
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	b;

	if (n >= 0 && n / 10 == 0)
	{
		b = n + 48;
		ft_putchar_fd(b, fd);
	}
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	ft_putlong_fd(long long n, int fd)
{
	char	b;

	if (n >= 0 && n / 10 == 0)
	{
		b = n + 48;
		ft_putchar_fd(b, fd);
	}
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	ft_usleep(int time)
{
	long long	current_time;
	long long	finish_time;

	finish_time = get_time() + time / 1000;
	current_time = get_time();
	while (current_time < finish_time)
	{
		usleep(1);
		current_time = get_time();
	}
}
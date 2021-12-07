/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgreyman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:09:06 by bgreyman          #+#    #+#             */
/*   Updated: 2021/12/07 15:09:18 by bgreyman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

int	ft_atoi(const char *str)
{
	int			s;
	int			z;
	long int	num;

	s = 0;
	z = 1;
	num = 0;
	while ((str[s] >= 9 && str[s] <= 13) || str[s] == 32)
		s++;
	if (str[s] == '-' || str[s] == '+')
	{
		if (str[s] == '-')
			z = -1;
		s++;
	}
	while (str[s] && str[s] >= '0' && str[s] <= '9')
	{
		num = num * 10 + z * (str[s] - '0');
		s++;
		if (z == 1 && num < 0 && s > 18)
			return (-1);
		if (z == -1 && num > 0 && s > 19)
			return (0);
	}
	return (num);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2", 2);
		ft_putnbr_fd (147483648, fd);
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		ft_putnbr_fd (n * -1, fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

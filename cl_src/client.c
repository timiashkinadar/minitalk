/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgreyman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:11:51 by bgreyman          #+#    #+#             */
/*   Updated: 2021/12/07 15:12:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "client.h"

void	ascii_to_bin(pid_t pid, char c)
{
	int	i;

	i = 7;
	if (!pid)
		exit(EXIT_FAILURE);
	while (i > 0)
	{
		if (c & 64)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		c = c << 1;
		usleep(800);
	}
}

void	ft_signal(pid_t pid, char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ascii_to_bin(pid, argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong arguments", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_putstr_fd("Unknown PID", 1);
		exit(EXIT_FAILURE);
	}
	ft_signal(pid, argv[2]);
}

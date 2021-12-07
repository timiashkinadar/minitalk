/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgreyman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:13:53 by bgreyman          #+#    #+#             */
/*   Updated: 2021/12/07 16:03:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	output(int sig)
{
	static int	bit;
	static char	buf;

	if (--bit == -1)
		bit = 6;
	if (sig == SIGUSR1)
		buf |= (1 << bit);
	if (bit == 0)
	{
		write(1, &buf, 1);
		buf = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, output);
	signal(SIGUSR2, output);
	while (1)
		pause();
}

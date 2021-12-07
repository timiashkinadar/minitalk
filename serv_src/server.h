/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgreyman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:13:59 by bgreyman          #+#    #+#             */
/*   Updated: 2021/12/07 15:14:02 by bgreyman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SERVER_H
# define SERVER_H
# include <unistd.h>
# include <signal.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif

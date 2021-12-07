/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgreyman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:11:58 by bgreyman          #+#    #+#             */
/*   Updated: 2021/12/07 15:12:11 by bgreyman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLIENT_H
# define CLIENT_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_signal(pid_t pid, char *argv);
void	ascii_to_bin(pid_t pid, char c);
#endif

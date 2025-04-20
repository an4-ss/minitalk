/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:22:04 by arokhsi           #+#    #+#             */
/*   Updated: 2025/04/20 17:25:39 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdlib.h>

void	ft_send_bits(int pid, char c);
int		check(char **av, int pid);
void	ft_handler(int sig, siginfo_t *info, void *context);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:19:15 by arokhsi           #+#    #+#             */
/*   Updated: 2025/04/20 14:19:17 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd >= 0 && s)
	{
		while (s[i])
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
}

static int	ft_sign(char **str)
{
	int	signe;

	signe = 1;
	while (**str == ' ' || **str == '\n' || **str == '\t'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			signe *= (-1);
		(*str)++;
	}
	return (signe);
}

int	ft_atoi(char *str)
{
	unsigned long	r;
	int				signe;

	r = 0;
	signe = ft_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		str++;
	}
	if (r > LONG_MAX && signe == 1)
		return (-1);
	if (r > (unsigned long)LONG_MAX + 1 && signe == -1)
		return (0);
	return ((int)r * signe);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nb;

	if (fd >= 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			ft_putnbr_fd(n, fd);
		}
		else if (n > 9)
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putnbr_fd((n % 10), fd);
		}
		else
		{
			nb = n + 48;
			write(fd, &nb, 1);
		}
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

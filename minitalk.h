#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <limits.h>

void	send_signal(int pid, unsigned char character);
void    ft_handler(int sig, siginfo_t *info, void *context);
void	ft_putstr_fd(char *s, int fd);
int    ft_atoi(char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
#endif
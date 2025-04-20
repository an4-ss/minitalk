#include "minitalk.h"

void    ft_handler(int signal, siginfo_t *info, void *context)
{
    static int            bit;
    static unsigned int    c;
    static int          g_pid;

    (void)context;
    if (info->si_pid != g_pid)
    {
            ft_putchar_fd('\n', 1);
        g_pid = info->si_pid;
        bit = 0;
        c = 0;
    }
    if (signal == SIGUSR1)
        c |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        ft_putchar_fd(c, 1);
        bit = 0;
        c = 0;
    }
}

int    main(int argc, char **argv)
{
    int                    pid;
    struct sigaction    sa;

    (void)argv;
    if (argc != 1)
    {
        ft_putstr_fd("Usage: ./server\n", 1);
        return (0);
    }
    pid = getpid();
    ft_putstr_fd("PID: ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    sa.sa_sigaction = ft_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause ();
    return (0);
}
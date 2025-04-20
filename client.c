#include "minitalk.h"


void    ft_send_bits(int pid, char c)
{
    int    bit;

    bit = 0;
    while (bit < 8)
    {
        if ((c & (1 << bit)) != 0 && kill(pid, SIGUSR1) == -1)
        {
            write(2, "kill failed", 11);
            exit(0);
        }
        else if ((c & (1 << bit)) == 0 && kill(pid, SIGUSR2) == -1)
        {
            write (2, "kill failed", 11);
            exit(0);
        }
        bit++;
        usleep(180);
        usleep(180);
    }
}

int    check(char **av, int pid)
{
    int    j;

    j = 0;
    while (av[1][j])
    {
        if ((av[1][j] < '0' || av[1][j] > '9') || pid <= 0)
        {
			ft_putstr_fd("pid error\n", 2);
            return (0);
        }
        j++;
    }
    return (1);
}

int    main(int argc, char **argv)
{
    int    pid;
    int    i;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        if (check(argv, pid) == 0)
            return (0);
        while (argv[2][i] != '\0')
        {
            ft_send_bits(pid, argv[2][i]);
            i++;
        }
    }
    else
		ft_putstr_fd("Try: ./client <PID> <MESSAGE>\n", 2);
    return (0);
}
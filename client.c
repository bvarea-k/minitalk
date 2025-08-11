

#include "minitalk.h"

int main(int ac, char **av)
{
    int pid;
    if (ac != 3)
    {
        ft_printf("ERROR, invalid number or params");
        exit(EXIT_FAILURE);
    }
    pid = ft_atoi(av[1]); // o no???????????????????
    return (EXIT_SUCCESS);
}

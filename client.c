/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:25:50 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/12 13:07:56 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void	signal_handler(int signum)
{
	(void)signum;
}

void	send_msg(int pid, char msg_char)
{
	short	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((msg_char >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		printf("voy a pasar el bit %i\n", bit);
		pause();
		bit--;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	char				*msg;
	int					i;
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_printf("ERROR: invalid number of params");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("ERROR: Invalid PID\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
	msg = av[2];
	i = 0;
	while (msg[i])
		send_msg(pid, msg[i++]);
	send_msg(pid, '\0');
	return (EXIT_SUCCESS);
}*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	signal_handler(int signum)
{
	(void)signum;
}

void	send_msg(int pid, char msg_char)
{
	short	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((msg_char >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		bit--;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	char				*msg;
	int					i;
	struct sigaction	sa;

	if (ac != 3)
	{
		write(2, "ERROR: invalid number of params\n", 32);
		exit(EXIT_FAILURE);
	}
	pid = atoi(av[1]);
	if (pid <= 0)
	{
		write(2, "ERROR: Invalid PID\n", 19);
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	msg = av[2];
	i = 0;
	while (msg[i])
		send_msg(pid, msg[i++]);
	send_msg(pid, '\0');
	return (0);
}

/*int	main(int ac, char **av)
{
	int					pid;
	char				*msg;
	int					i;
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_printf("ERROR: invalid number of params\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if ((pid = ft_atoi(av[1])) <= 0)
		exit(EXIT_FAILURE);
	msg = av[2];
	i = -1;
	while (msg[++i])
		send_msg(pid, msg[i]);
	send_msg(pid, '\0');
	return (EXIT_SUCCESS);
}*/

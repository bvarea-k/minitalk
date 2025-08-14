/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:02:18 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/12 12:58:46 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *context)
{
	static int				bit_nbr;
	static unsigned char	c;

	(void)context;
	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;
	bit_nbr++;
	if (bit_nbr == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit_nbr = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	ft_putnbr(int n)
{
	char	buffer[12];
	int		i;
	long	num;

	num = n;
	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	i = 10;
	buffer[11] = '\0';
	while (num > 0)
	{
		buffer[i--] = '0' + (num % 10);
		num /= 10;
	}
	write(1, &buffer[i + 1], 10 - i);
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "SERVER PID = ", 13);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Error setting SIGUSR1 handler\n", 30);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error setting SIGUSR2 handler\n", 30);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}

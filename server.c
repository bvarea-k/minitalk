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
	static int				bit_nbr; //contador de bits recibidos
	static unsigned char	c; // carácter que estamos construyendo

	(void)context;
	c <<= 1; //Desplazo el carácter a la izquierda para añadir el siguiente bit.
	if (sig == SIGUSR2)
		c |= 1;
	bit_nbr++;
	if (bit_nbr == 8)
	{
		if (c == '\0') //si es el final de la cadena, salto de línea.
			write(1, "\n", 1);
		else
			write(1, &c, 1); //si no es el final, escribo el carácter.
		bit_nbr = 0; //reiniciamos para el próximo bit.
		c = 0;
	}
	kill(info->si_pid, SIGUSR1); //Enviamos al cliente una señal de confirmación (SIGUSR1).
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
	sa.sa_flags = SA_SIGINFO; //Activa el uso de sa_sigaction en vez de sa_handler.
	sigemptyset(&sa.sa_mask); //Inicializa el conjunto de señales sa_mask.
	sigaddset(&sa.sa_mask, SIGUSR1); //Añade señales que bloquear mientras se ejecuta handler,
	sigaddset(&sa.sa_mask, SIGUSR2); //así no interrumpimos el handler.
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:25:50 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/12 13:56:44 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Necesito variable global para que cambie en cualquier momento del programa.
//Es volatile para indicar que puede cambiar de forma inesperada, para que el programa la lea cada vez que la use.
//Es sig_atomic_t para garantizar que su lectura y escritura sean atómicas (no se corten por la mitad).
//El cliente usa sa_handler y SA_RESTART, porque solo necesita saber si le llegó una señal para activar un flag.
//El servidor usa sa_sigaction y SA_SIGINFO porque necesita saber quién le envió la señal.

volatile sig_atomic_t	g_ack_received = 0;

static void	signal_handler(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

static void	send_char(int pid, char c)
{
	int			bit;
	int			wait;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		wait = 0;
		while (!g_ack_received && wait++ < 10000)
			usleep(100);
		bit--;
	}
}

static void	validate_argc(int num)
{
	if (num != 3)
	{
		write(2, "Error. Enter: ./client [PID] [MESSAGE]\n", 39);
		exit(EXIT_FAILURE);
	}
}

static void	setup_sigaction(struct sigaction *sa)
{
	sa->sa_handler = signal_handler; //Cuando recibas SIGUSR1, ejecuta el handler. El handler marca que el servidor mandó SIGUSR1.
	sa->sa_flags = SA_RESTART; //Si una señal interrumpe una llamada del sistema, intenta reiniciarla. Es buena práctica.
	sigemptyset(&sa->sa_mask);//Limpia el set de señales bloqueadas durante la ejecución del handler.
	if (sigaction(SIGUSR1, sa, NULL) == -1)
	{
		write(2, "ERROR: sigaction failed\n", 24);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*msg;
	struct sigaction	sa;
	int					i;

	i = 0;
	validate_argc(argc);
	pid = validate_pid(argv[1]);
	msg = argv[2];
	setup_sigaction(&sa);
	while (msg[i])
		send_char(pid, msg[i++]);
	send_char(pid, '\0');
	return (0);
}

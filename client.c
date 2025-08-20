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

//El cliente envía el mensaje al servidor con la señales SIGUSR1(0) y SIGUSR2(1).
//Necesito variable global para que cambie en cualquier momento del programa.
//Es volatile para indicar que puede cambiar de forma inesperada, para que el programa la lea cada vez que la use.
//Es sig_atomic_t para garantizar que su lectura y escritura sean atómicas (no se corten por la mitad).
//El cliente usa sa_handler y SA_RESTART, porque solo necesita saber si le llegó una señal para activar un flag.
//El servidor usa sa_sigaction y SA_SIGINFO porque necesita saber quién le envió la señal.

volatile sig_atomic_t	g_ack_received = 0; //El cliente la usa para verificar que el servidor ha recibido bien cada señal

static void	signal_handler(int signum)
{
	(void)signum;
	g_ack_received = 1; // El servidor ha enviado una confirmación (SIGUSR1)
}


//El cliente envía el mensaje bit a bit.
//Si es 1, manda SIGUSR2 y, si es 0, manda SIGUSR1.
//Después de cada señal, el cliente espera a recibir la confirmación (SIGUSR1)
//de que el servidor ha procesado la señal.**
//La espera está limitada a 10,000 ciclos de espera con usleep(100)
//para evitar que el cliente quede bloqueado indefinidamente.

static void	send_char(int pid, char c)
{
	int			bit;
	int			wait;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2); //Envía SIGUSR2 si el bit es 1
		else
			kill(pid, SIGUSR1); // Envía SIGUSR1 si el bit es 0
		wait = 0;
		while (!g_ack_received && wait++ < 10000)
			usleep(100); // Espera la confirmación del servidor**
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
	validate_argc(argc); //Valido los argumentos.
	pid = validate_pid(argv[1]); //Valido el PID
	msg = argv[2]; //Obtengo el mensaje del cliente.
	setup_sigaction(&sa); //Configuro el handler (manejador)
	while (msg[i])
		send_char(pid, msg[i++]);//Envío cada caracter del mensaje,
	send_char(pid, '\0');//Envío el nulo al final del mensaje.
	return (0);
}

/*								Flujo básico:
		El cliente:
  1. Envía un bit.
  2. Después de mandar cada bit, entra en un bucle de espera hasta que el servidor manda SIGUSR1.
  Este bucle está controlado por la variable global. Si no recibe la confirmación!!!! el contador wait
  se incrementa hasta 10000 intentos (para darle tieeeeeeeempo).
		El servidor:
  1. Espera recibir los bits del cliente. A medida que los va recibiendo, cuenta cuántos bits ha recibido (bit_nbr).
  2. Procesa el carácter completo y lo imprime.
  3. Envía SIGUSR1 al cliente.
- Espera las señales SIGUSR1 y SIGUSR2.
- Recibe los bits.
- Cuando hay 8 bits (el caracter está completo), imprime.
- Envía una señal de confirmación (SIGUSR1, o sea 0 en mi caso) al cliente con cada caracter.
*/

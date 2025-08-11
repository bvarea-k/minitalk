

#include "minitalk.h"

/*sig: SIGUSR1 o SIGUSR2
info:info de la señal, por ejemplo el PID
context: contexto, pero aquí no se usa.
¿De dónde sale esta info? Al usar SA_SIGINFO,
le digo al sistema que la función tendrá el aspecto 
de handler y, cuando llegue la señal, el ordenador
mete directamente la información en la función.
Sigaction es tanto una función como una estructura.

If SA_SIGINFO is specified in sa_flags, then sa_sigaction (instead
of sa_handler) specifies the signal-handling function for signum.
This function receives three arguments, as described below
Signal es antigua, signation más moderna.
sa_flags es un entero en el que cada bit es una flag
int kill(pid_t pid, int sig)
kill(info->si_pid, SIGUSR1)
si_pid es un pid_t de signation.
sigemptyset inicializa un set de señales vacío. ¿¿LO USO??
¿CON SA_MASK? sa_mask specifies a mask of signals which should be blocked.
Si no quiero bloquear señales, mejor lo uso?????
sigaddset añade la señal indicada al set*/


void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		write(1, "0", 1);
	else
		write(1, "1", 1);
	kill(info->si_pid, SIGUSR1);
}

void handler(int sig, siginfo_t *info, void *context)
{
    static int bit_nbr; //bit en el que estoy
    static unsigned char c; //bits recibidos

    bit_nbr = 0;
    c = 0;
    (void)context; //No lo uso, me lo cargo como en el examen.
    if (sig == SIGUSR1)
        c = c | (0 << (7 - bit_nbr)); //Esto no hace nada. Me lo podría comer, creo.
    else if (sig == SIGUSR2)
        c = c | (1 << (7 - bit_nbr));
    bit_nbr++;
    if (bit_nbr == 8) //Cuando ha pasado el caracter entero, bit a bit (nbr = 8), Si he llegado al final del mensaje, hago un salto de línea.
    //Si no, imprimo el caracter. Reinicio c y nbr para la próxima iteraicón.
    {
        if (c == '\0')
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        c = 0;
        bit_nbr = 0;
    }

    kill(info->si_pid, SIGUSR1);
}


int main(void)
{
    ft_printf("SERVER PID = %d\n", getpid());
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    /*sigemptyset(&sa.sa_mask)???????*/

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    return (EXIT_SUCCESS);
}
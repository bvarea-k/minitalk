/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:35:22 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/13 12:35:24 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	validate_pid(char *str)
{
	int	pid;

	pid = atoi(str);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		write(2, "ERROR: Invalid PID\n", 19);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

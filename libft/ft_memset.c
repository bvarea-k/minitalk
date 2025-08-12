/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:59:17 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/22 13:59:20 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*j;

	i = 0;
	j = (char *)s;
	while (i < n)
	{
		j[i] = c;
		i++;
	}
	return (s);
}

/*int	main (void)
{
	char	inicio[] = "Hola mundo";
	int	que_meto = 88;
	size_t	t = 3;
	ft_memset(inicio, que_meto, t);
	
	printf("Impresion: %s", inicio);
	printf("Resultado mio: %p\n", ft_memset(&inicio[4], que_meto, t));
	printf("Resultado normal: %p\n", memset(&inicio[4], que_meto, t));
}*/

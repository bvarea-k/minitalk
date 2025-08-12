/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:03:56 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/23 12:04:01 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *) dest;
	s = (char *) src;
	if (!dest && !src && n > 0)
		return (NULL);
	if (!n || src == dest)
	{
		return (dest);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	src[] = "Hola";
	char	dest[10] = "";

	ft_memcpy(dest, src, 2);
	printf("Imprime: %s", dest);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:59:49 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/24 10:59:51 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dest && !src && n > 0)
		return (NULL);
	d = (char *) dest;
	s = (char *) src;
	if (dest >= src)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

/*int	main(void)
{
	char dst[20] = "Hola Mundo";
	char src[] = "Veamos";
	
	printf("Antes: %s\n", dst);
	ft_memmove(dst, src, 9);
	printf("Después: %s\n", dst);
	return (0);
}*/

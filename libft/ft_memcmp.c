/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:16:55 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/23 13:16:59 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (i < n)
	{
		if (d[i] != s[i])
		{
			return (d[i] - s[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	const char *str1 = "Hola a todos";
	const char *str2 = "Hola A todos";
	const char *str3 = "Hola a todos";
	const char *str4 = "Esto no coincide";

	printf("Mi caso 1: %d\n", ft_memcmp(str1, str3, 10));
	printf("Caso 1: %d\n", memcmp(str1, str3, 10));
	printf("Mi caso 2: %d\n", ft_memcmp(str1, str2, 10));
	printf("Caso 2: %d\n", ft_memcmp(str1, str2, 10));
	printf("Mi caso 3: %d\n", ft_memcmp(str1, str2, 5));
	printf("Caso 3: %d\n", ft_memcmp(str1, str2, 5));
	printf("Mi caso 4: %d\n", ft_memcmp(str1, str4, 2));
	printf("Caso 4: %d\n", ft_memcmp(str1, str4, 2));
	return (0);
}*/

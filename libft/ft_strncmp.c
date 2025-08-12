/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:43:26 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/30 12:43:30 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	unsigned char		*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i]
		!= '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}

/*int	main(void)
{
	const char *str1 = "Hola a todos";
	const char *str2 = "Hola A todos";
	const char *str3 = "Hola a todos";
	const char *str4 = "Esto no coincide";

	printf("Mi caso 1: %d\n", ft_strncmp(str1, str3, 10));
	printf("Caso 1: %d\n", strncmp(str1, str3, 10));
	printf("Mi caso 2: %d\n", ft_strncmp(str1, str2, 10));
	printf("Caso 2: %d\n", strncmp(str1, str2, 10));
	printf("Mi caso 3: %d\n", ft_strncmp(str1, str2, 5));
	printf("Caso 3: %d\n", strncmp(str1, str2, 5));
	printf("Mi caso 4: %d\n", ft_strncmp(str1, str4, 2));
	printf("Caso 4: %d\n", strncmp(str1, str4, 2));
	return (0);
}*/

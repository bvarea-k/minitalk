/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:06:59 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/30 09:07:04 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

/*int	main(void)
{
	const char *text = "Hola Mundo!";
	char search1 = 'M';
	char search2 = 'p';

	char *result1 = ft_strchr(text, search1);
	char *result2 = ft_strchr(text, search2);

	if (result1)
		printf("Encontrado '%c' en: %s\n", search1, result1);
	else
		printf("'%c' no se encontró.\n", search1);

	if (result2)
		printf("Encontrado '%c' en: %s\n", search2, result2);
	else
		printf("'%c' no se encontró.\n", search2);
	return (0);
}*/

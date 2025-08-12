/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:57:04 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/07 16:04:34 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = (char *) malloc(sizeof (char) * (size));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, size);
	ft_strlcat(string, s2, size);
	return (string);
}

/*int main(void)
{
	char str1[] = "Hola ";
	char str2[] = "a todos";
	char *result = ft_strjoin(str1, str2);

	if (result)
	{
		printf("Resultado: %s\n", result);
		free(result);
	}
	else
		printf("No se pudo asignar memoria.\n");
	return (0);
}*/

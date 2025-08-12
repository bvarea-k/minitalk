/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:10:18 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/05 13:10:54 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *) malloc(ft_strlen(s) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int	main(void)
{
	const char	*original = "Hola Mundo!";
	char	*new = ft_strdup(original);

	if (new)
	{
		printf("Cadena original: %s\n", original);
		printf("Nueva cadena: %s\n", new);
		free(new);
	}
	else
	{
		printf("Error: no se pudo duplicar la cadena.\n");
	}
}*/

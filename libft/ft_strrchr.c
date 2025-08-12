/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:16:48 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/30 09:16:51 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = (char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*str = "¡Funciona bien!";
	char	*res = ft_strrchr(str, 'b');
	
	if (res)
		printf("Encontrado: %s\n", res);
	else
		printf("No encontrado.\n");
}*/

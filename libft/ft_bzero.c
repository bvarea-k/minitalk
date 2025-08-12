/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:32:11 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/23 11:32:13 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*j;

	i = 0;
	j = (char *)s;
	while (i < n)
	{
		j[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char	s[60] = "Hola, vamos a probar";
	size_t	n = 5;
	printf("%s\n", s);
	ft_bzero(s, n);
	printf("%s\n", s);
	return(0);
}*/

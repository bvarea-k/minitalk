/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:17:36 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/07 09:17:38 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = (char *) malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*int	main(void)
{
	char	*str;
	int		i;
	
	i = 0;
	str = ft_calloc(1, 4);
	while (i < 4)
	{
		str[i] = 'k';
		i++;
	}
	write(1, str, 4);
	return (0);
}*/

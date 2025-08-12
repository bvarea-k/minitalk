/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:11:45 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/30 10:12:31 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	cc;

	i = 0;
	str = (unsigned char *) s;
	cc = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == cc)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*int    main(void)
{
	char	str[] = "Hola mundo";

	printf("%s", (char *) ft_memchr(str, 'a', 7));
}*/

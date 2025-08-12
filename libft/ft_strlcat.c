/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:25:11 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/05 12:58:52 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = (ft_strlen(dst));
	src_len = (ft_strlen(src));
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	if (size > 0)
	{
		while (((dst_len + i) < (size - 1)) && (src[i] != '\0'))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}

/*int    main(void)
{
	char dst[10]  = "hola";
	char *src = "a todos";
	printf("%zu", ft_strlcat(dst, src, 10));
	return (0);
}*/

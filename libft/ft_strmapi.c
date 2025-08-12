/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:38:27 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/08 16:38:51 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s && s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*char	ft_upper(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
			c -= 32;
	return (c);
}

int	main(void)
{
	char	str[] = "Funciona";
	char	*str_dest;

	printf("Antes: %s\n", str);
	str_dest = ft_strmapi(str, ft_upper);
	printf("Después: %s\n", str_dest);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:32:54 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/05 13:33:12 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub_str = (char *) malloc(sizeof (char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			sub_str[j] = s[i];
			j++;
		}
		i++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}

/*int	main(void)
{
	char str[]= "Hola mundo";
	char *sub_str = ft_substr(str, 0, 4);

	printf("Substr: %s\n", sub_str);
	free(sub_str);
	return (0);
}*/

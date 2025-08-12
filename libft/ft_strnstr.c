/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:52:15 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/02 08:52:20 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*little_ish;
	char	*big_ish;

	i = 0;
	big_ish = (char *) big;
	little_ish = (char *) little;
	if (little_ish[0] == '\0')
		return (big_ish);
	while (big_ish[i] != '\0' && i < len)
	{
		j = 0;
		while (big_ish[i] && ((i + j) < len) && big_ish[i + j] == little_ish[j])
		{
			j++;
			if (little_ish[j] == '\0')
				return (&big_ish[i]);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char big[] = "HOLA QUE TAL";
	char little[] = "QU";
	
	printf("%s", ft_strnstr(big, little, 8));
	return (0);
}*/

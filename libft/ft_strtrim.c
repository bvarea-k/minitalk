/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:58:47 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/08 09:59:23 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_inset(s1[start], set))
		start++;
	while (s1[end] && ft_inset(s1[end], set) && start < end)
		end--;
	result = ft_substr(s1, start, end - start + 1);
	return (result);
}

/*int	main(void)
{
	char	*str = "985217Hola654680";
	char	*set = "0123456789";
	printf("%s", ft_strtrim(str, set));
}*/

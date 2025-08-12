/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgo <bgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:22:14 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/02 19:20:07 by bgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_strjoin_modif(char *s1, char const *s2)
{
	char	*string;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = (char *) ft_calloc(size, sizeof (char));
	if (!string)
		return (NULL);
	while ((s1[i] != '\0') && (i < size -1))
		string[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		string[j++] = s2[i++];
	ft_free(&s1);
	return (string);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

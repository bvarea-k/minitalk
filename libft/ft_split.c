/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgo <bgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:52:22 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/02 18:48:23 by bgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	is_delimiter;
	int	words;
	int	i;

	is_delimiter = 1;
	words = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			is_delimiter = 1;
		else if (s[i] != c && is_delimiter)
		{
			is_delimiter = 0;
			words++;
		}
		i++;
	}
	return (words);
}

static int	ft_w_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (s[size] != '\0' && s[size] != c)
		size++;
	return (size);
}

static char	**ft_free_mem(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		pos;
	int		pos_str;

	pos = 0;
	pos_str = 0;
	str = (char **) ft_calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	while (s && s[pos])
	{
		if (s[pos] == c)
			pos++;
		else if (s[pos] != c)
		{
			str[pos_str] = ft_calloc(ft_w_size(s + pos, c) + 1, sizeof(char));
			if (!str[pos_str])
				return (ft_free_mem(str));
			ft_memcpy(str[pos_str], s + pos, ft_w_size(s + pos, c));
			pos_str++;
			pos = pos + ft_w_size(s + pos, c);
		}
	}
	str[pos_str] = NULL;
	return (str);
}

/*int	main(void)
{
	char const *input = "Hola++a+ver si+funciona";
	char delim = '+';
	char **result = ft_split(input, delim);
	int i = 0;
	
	while (i < 4)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}*/

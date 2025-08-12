/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:07:33 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/12 09:07:35 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	ft_upper(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	char str[] = "Hola Mundo!";

	printf("Antes: %s\n", str);
	ft_striteri(str, ft_upper);
	printf("Después: %s\n", str);

	return 0;
}*/

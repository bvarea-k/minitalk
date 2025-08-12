/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:07:52 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/22 13:07:57 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (16384);
	}
	return (0);
}

/*int	main(void)
{
	int	s = 31;
	int	o = 120;

	printf("%d\n", ft_isprint(s));
	printf("%d\n", isprint(s));
	printf("%d\n", ft_isprint(o));
	printf("%d", isprint(o));
}*/

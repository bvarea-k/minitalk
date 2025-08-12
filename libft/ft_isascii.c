/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:04:34 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/22 12:04:37 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
	{
		return (1024);
	}
	return (0);
}

/*int	main(void)
{
	int	s = 66;
	int	o = 129;

	printf("%d\n", ft_isascii(s));
	printf("%d\n", isalpha(s));
	printf("%d\n", ft_isascii(o));
	printf("%d", isalpha(o));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:41:24 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/22 11:41:28 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (2048);
	}
	else
	{
		return (0);
	}
}

/*int	main(void)
{
	int	c = '9';
	
	printf ("%d\n", ft_isdigit(c));
	printf ("%d", isdigit(c));
}*/

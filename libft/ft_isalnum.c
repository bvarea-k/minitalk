/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:31:33 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/04/22 12:31:44 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57))
		return (8);
	else
		return (0);
}

/*int	main(void)
{
	int	c = '9';
	int	o = 5;
	
	printf ("%d\n", ft_isalnum(c));
	printf ("%d\n", isalnum(c));
	printf ("%d\n", ft_isalnum(o));
	printf ("%d", isalnum(o));
}*/

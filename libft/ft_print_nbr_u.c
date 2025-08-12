/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:55:55 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/16 13:56:01 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_print_nbr_u(unsigned int n)
{
	char	c;
	int		result;

	result = 1;
	if (n > 9)
		result = result + ft_print_nbr_u(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:32:26 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/19 09:32:31 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr_hex(unsigned int n, char upper)
{
	char	*set;
	int		result;

	result = 0;
	if (upper == 'x')
		set = "0123456789abcdef";
	else
		set = "0123456789ABCDEF";
	if (n >= 16)
	{
		result += ft_print_nbr_hex(n / 16, upper);
		result += ft_print_nbr_hex(n % 16, upper);
	}
	else
		result += ft_print_char(set[n]);
	return (result);
}

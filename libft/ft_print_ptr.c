/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:28:20 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/21 12:56:49 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(void *ptr)
{
	char			*set;
	unsigned long	address;
	unsigned long	result;

	result = 0;
	address = (unsigned long)ptr;
	set = "0123456789abcdef";
	if (address >= 16)
	{
		result += ft_print_ptr((void *)(address / 16));
		result += ft_print_ptr((void *)(address % 16));
	}
	else
		result += ft_print_char(set[address]);
	return (result);
}

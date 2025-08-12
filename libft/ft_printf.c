/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgo <bgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:46:57 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/07 20:07:33 by bgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type_print(va_list arg, const char c)
{
	void	*p;

	if (c == 'c')
		return (ft_print_char(va_arg(arg, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (c == '%')
		return (ft_print_percentage());
	else if (c == 'i' || c == 'd')
		return (ft_print_nbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_print_nbr_u(va_arg(arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_nbr_hex(va_arg(arg, unsigned int), c));
	else if (c == 'p')
	{
		p = va_arg(arg, void *);
		if (p == NULL)
			return (write(1, "(nil)", 5));
		write(1, "0x", 2);
		return (ft_print_ptr(p) + 2);
	}
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len = len + ft_type_print(arg, s[i + 1]);
			i++;
		}
		else
			len = len + ft_print_char(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

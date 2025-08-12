/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:12:28 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/05/12 10:31:48 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long num)
{
	int	result;

	result = 0;
	if (num < 0)
	{
		num *= -1;
		result++;
	}
	while (num > 9)
	{
		num = num / 10;
		result++;
	}
	result++;
	return (result);
}

char	*ft_itoa(int num)
{
	int		len;
	int		sign;
	char	*result;

	len = ft_num_len((long)num);
	sign = 1;
	result = (char *) malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		sign = -1;
	}
	while (num != 0)
	{
		result[len - 1] = sign * (num % 10) + '0';
		len--;
		num = num / 10;
	}
	return (result);
}

/*int	main (void)
{
	int	i;
	
	i = 2500;
	printf("%s", ft_itoa(i));
}*/

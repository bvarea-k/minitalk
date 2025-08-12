/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:45:23 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/06/19 12:45:24 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (lst == NULL || f == NULL)
		return ;
	else
	{
		while (lst != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

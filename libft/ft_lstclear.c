/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:54:39 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/07/01 12:57:11 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cursor;
	t_list	*tmp_lst;

	cursor = *lst;
	while (cursor)
	{
		tmp_lst = cursor->next;
		ft_lstdelone(cursor, del);
		cursor = tmp_lst;
	}
	*lst = 0;
}

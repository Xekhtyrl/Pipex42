/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:10:31 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*temp2;

	if (!(*lst) || !del || !lst)
		return ;
	temp = *lst;
	while (temp != 0)
	{
		temp2 = temp->next;
		ft_lstdelone(temp, del);
		temp = temp2;
	}
	*lst = 0;
}

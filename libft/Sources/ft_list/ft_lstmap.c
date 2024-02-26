/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:40:32 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*adr_new;
	t_list	*new;
	void	*temp;

	if (!lst || !f || !del)
		return (0);
	adr_new = NULL;
	while (lst != NULL)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (new == NULL)
		{
			del(temp);
			ft_lstclear(&adr_new, del);
			return (0);
		}
		ft_lstadd_back(&adr_new, new);
		lst = lst->next;
	}
	return (adr_new);
}

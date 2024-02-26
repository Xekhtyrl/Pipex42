/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:05:41 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*temp;
	size_t			i;

	if (!src && !dst)
		return (0);
	i = -1;
	ds = (unsigned char *)dst;
	temp = (unsigned char *)src;
	if (dst >= src)
	{
		while ((int)n-- > 0)
			ds[n] = temp[n];
	}
	else
	{
		while (++i < n)
		{
			ds[i] = (temp)[i];
		}
	}
	return (dst);
}

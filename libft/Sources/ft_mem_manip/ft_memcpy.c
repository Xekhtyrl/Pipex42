/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:08:00 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;

	ds = dst;
	if (!dst && !src)
		return (0);
	while (n-- > 0)
		*ds++ = *(char *)src++;
	return (dst);
}

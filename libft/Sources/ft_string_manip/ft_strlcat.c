/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:02:52 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	n;

	if (!dst)
		i = 0;
	else
		i = ft_strlen(dst);
	n = 0;
	j = ft_strlen((char *)src);
	if (dstsize < i)
		return (j + dstsize);
	while (*src && n + i + 1 < dstsize)
		dst[i + n++] = *src++;
	dst[j + i] = '\0';
	return (i + j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:47:15 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned long	i;
	unsigned long	l;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	l = (int)ft_strlen((char *)s) - start;
	if (l > len)
		l = len;
	dst = malloc((l + 1) * sizeof(char));
	if (!dst)
		return (0);
	i = 0;
	while (*s && i < l)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

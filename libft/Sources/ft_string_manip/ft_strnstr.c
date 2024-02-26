/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:21:48 by lvodak            #+#    #+#             */
/*   Updated: 2024/02/13 19:33:18 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strnstr(const char *str, const char *cmp, size_t len)
{
	int					i;
	unsigned long		j;
	char				*ptr;

	if (!str)
		return (0);
	ptr = (char *)str;
	j = 0;
	if (*cmp == '\0')
		return (ptr);
	while (ptr[j] != '\0' && (j < len))
	{
		i = 0;
		while (ptr[j + i] == cmp[i] && (j + i < len) && ptr[j + i] != '\0')
			i++;
		if (cmp[i] == '\0')
			return (ptr + j);
		j++;
	}
	return (0);
}

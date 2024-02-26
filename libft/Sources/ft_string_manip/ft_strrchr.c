/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:24:14 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = (int)ft_strlen(s);
	ptr = (char *)s;
	while (i >= 0)
	{
		if (s[i] == c && c == '\0')
		{
			ptr = (char *)(s + i);
			return (ptr);
		}
		if (s[i] == (unsigned char)c)
		{
			ptr = (char *)s + i;
			return (ptr);
		}
		i--;
	}
	return (0);
}

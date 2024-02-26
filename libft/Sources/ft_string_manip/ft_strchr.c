/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:08:56 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if ((char)c == 0)
		return (str + ft_strlen(s));
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (0);
}

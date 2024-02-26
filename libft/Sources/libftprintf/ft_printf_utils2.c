/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:53:27 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

char	*strcatx(char *dst, char *src, int dstl, int l)
{
	int		n;

	n = 0;
	if (src == NULL)
		src = "(null)";
	while (*src && dstl + n < l)
	{
		dst[dstl + n] = src[n];
		n++;
	}
	dst[dstl + n] = '\0';
	return (dst);
}

int	strlenx(void *str)
{
	if (str == NULL)
		return (6);
	return (ft_strlen((char *)str));
}

char	*error_free(char *str, char *temp)
{
	if (temp)
		free(temp);
	free(str);
	return (NULL);
}

char	*ft_dup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	if (src == NULL)
		src = "(null)";
	dup = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (0);
	ft_memcpy(dup, src, ft_strlen(src) + 1);
	dup[ft_strlen(src)] = '\0';
	return (dup);
}

t_stringl	final_check(char info, va_list args, char *str, int l)
{
	char		*temp;
	char		t[2];
	t_stringl	update;

	t[1] = 0;
	update.content = NULL;
	if (is_valid(info))
	{
		temp = the_gathering2_5(args, info);
		if (!temp)
		{
			error_free(str, temp);
			return (update);
		}
		update.content = strcatx(str, temp, l, l + ft_strlen(temp));
		update.cont_len = ft_strlen(temp);
		free(temp);
	}
	else if (is_valid(info) == 0)
	{
		t[0] = info;
		update.content = strcatx(str, t, l, l + 2);
		update.cont_len = ft_strlen(temp);
	}
	return (update);
}

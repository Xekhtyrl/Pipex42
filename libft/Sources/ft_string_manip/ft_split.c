/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:04:17 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/28 18:34:57 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int	ft_strnbr(char *str, char c)
{
	int	i;

	i = 0;
	if (str[0] != c && *str)
		i++;
	if (ft_strlen(str) == 0)
		return (i);
	while (*str != '\0')
	{
		if (*str != '\0')
			str++;
		while (*str == c && *str)
			str++;
		if (*str != '\0' && *str != c && *(str - 1) == c)
			i++;
	}
	return (i);
}

static int	ft_free(char **str, int i)
{
	if (!str[i])
	{
		while (i >= 0)
			free(str[i--]);
		free((char **)str);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	int		ls;
	int		ns;

	strs = (char **)malloc(sizeof(char *) * (ft_strnbr((char *)s, c) + 1));
	if (!strs)
		return (0);
	ls = 0;
	ns = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			ls = 1 + i++;
		if (i < ft_strlen(s) && (s[i + 1] == c || i == ft_strlen(s) - 1))
		{
			strs[ns++] = ft_substr(s, ls, i - ls + 1);
			if (ft_free(strs, ns - 1))
				return (0);
		}
		i++;
	}
	strs[ft_strnbr((char *)s, c)] = 0;
	return (strs);
}

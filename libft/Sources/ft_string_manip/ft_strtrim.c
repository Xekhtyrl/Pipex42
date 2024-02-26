/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:48:21 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	n;
	int	start;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	while (ft_strchr(set, s1[start]) != 0)
		start++;
	n = (int)ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[n]) != 0)
		n--;
	return (ft_substr(s1, start, n - start + 1));
}

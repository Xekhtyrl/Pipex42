/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:30:56 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = -1;
	dup = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (0);
	while (src[++i])
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}

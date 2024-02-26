/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:19:07 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		j;

	if (!s2 || !s1)
		return (0);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	j = 0;
	while (*s1 != '\0')
		s3[j++] = *s1++;
	while (*s2 != '\0')
		s3[j++] = *s2++;
	s3[j] = '\0';
	return (s3);
}

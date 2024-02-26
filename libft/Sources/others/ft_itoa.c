/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:17:31 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int	ft_int_siz(long n)
{
	if (n < 10)
		return (1);
	return (1 + ft_int_siz(n / 10));
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		l;

	nb = n;
	if (nb < 0)
		nb *= -1;
	l = ft_int_siz(nb);
	if (n < 0)
		l++;
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (0);
	str[l] = '\0';
	while (--l >= 0)
	{
		str[l] = ((nb % 10) + '0');
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:32:49 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_atoi(const char *str)
{
	int		f;
	long	nbr;

	f = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			f *= -1;
	}
	while (ft_isdigit(*str))
		nbr = nbr * 10 + (*str++ - '0');
	if (nbr > INT32_MAX || (nbr == INT32_MAX && f == -1) || nbr < 0)
		return (0);
	return (nbr * f);
}

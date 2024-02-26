/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:36:06 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

int	is_valid(char c)
{
	if (c == 's')
		return (1);
	else if (c == 'i' || c == 'd')
		return (2);
	else if (c == 'x' || c == 'X' || c == 'p' || c == 'u')
		return (3);
	else if (c == 'c' || c == '%')
		return (4);
	else
		return (0);
}

int	get_length(va_list args, char *info)
{
	int	length;

	length = 0;
	while (*info != '\0')
	{
		if (*info++ == '%')
		{
			if (!is_valid(*info))
				length -= 1;
			if (is_valid(*info) == 1 && *info == 's')
				length += strlenx(va_arg(args, char *));
			else if (is_valid(*info) == 2 || *info == 'u')
				length += ft_int_size(va_arg(args, int), *info);
			else if (is_valid(*info) == 3 && *info == 'p')
				length += (ft_hex_size(va_arg(args, unsigned long), 16) + 2);
			else if (is_valid(*info) == 3 && *info != 'u')
				length += ft_hex_size(va_arg(args, unsigned int), 16);
			else if (is_valid(*info) == 4 && *info == 'c')
				length += 1 + 0 * va_arg(args, int);
			else if (is_valid(*info) == 4 && *info == '%')
				length += 1;
			info++;
		}
	}
	return (length);
}

int	ft_int_size(long n, char info)
{
	if (info != 'u')
	{
		if (n < 0)
			return (1 + ft_int_size(n * -1, info));
		if (n < 10)
			return (1);
		return (1 + (int)ft_int_size(n / 10, info));
	}
	else
	{
		if ((unsigned int)n < 10)
			return (1);
		return (1 + ft_int_size((unsigned int)n / 10, info));
	}
}

int	ft_hex_size(unsigned long n, size_t base)
{
	if (n < base)
		return (1);
	return (1 + ft_hex_size(n / base, base));
}

char	*ft_ltoa_base(unsigned long n, char *base)
{
	char	*str;
	int		size;
	int		s;

	size = ft_hex_size(n, ft_strlen(base));
	s = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	while (--size >= 0)
	{
		str[size] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		s++;
	}
	str[s] = '\0';
	return (str);
}

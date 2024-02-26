/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:06:52 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:23:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

char	*the_gathering2_5(va_list args, char info)
{
	char	*temp;
	char	*tp;

	tp = NULL;
	temp = NULL;
	if (is_valid(info) == 1)
		temp = ft_dup(va_arg(args, char *));
	if (is_valid(info) == 3 && info == 'x')
		temp = ft_ltoa_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (is_valid(info) == 3 && info == 'u')
		temp = ft_ltoa_base(va_arg(args, unsigned int), "0123456789");
	else if (is_valid(info) == 3 && info == 'X')
		temp = ft_ltoa_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (is_valid(info) == 3 && info == 'p')
		temp = ft_strjoin("0x", tp = ft_ltoa_base(va_arg(args, unsigned long),
					"0123456789abcdef"));
	else if (is_valid(info) == 2 && (info == 'i' || info == 'd'))
		temp = ft_itoa(va_arg(args, int));
	else if (info == '%')
		temp = ft_dup("%\0");
	if (temp == NULL)
		return (error_free(temp, tp));
	free(tp);
	return (temp);
}

static char	*the_gathering(char *info, va_list args, char *str)
{
	int			i;
	t_stringl	update;

	i = 0;
	while (*info != '\0' && str)
	{
		while ((*info != '%' && *info != '\0'))
			str[i++] = *info++;
		if (*info != '\0' && (*info++ == '%' && *info != '\0'))
		{
			update.cont_len = 0;
			if (is_valid(*info) == 4 && *info == 'c')
				str[i++] = (char)va_arg(args, int);
			else
			{
				update = final_check(*info, args, str, i);
				str = update.content;
			}
			i += update.cont_len;
			if (*info != '\0')
				info++;
		}
	}
	return (str);
}

static int	count_arg(const char *arg)
{
	int		i;

	i = 0;
	while (*arg != '\0')
	{
		while (*arg != '%' && *arg)
			arg++;
		if (*arg && (*arg++ == '%' && is_valid(*arg)))
			i++;
		if (*arg != '\0')
			arg++;
	}
	return (i);
}

int	ft_printf(const char *info, ...)
{
	int		l;
	int		count;
	char	*str;
	va_list	args;
	va_list	args_cpy;

	va_start(args, info);
	va_copy(args_cpy, args);
	count = count_arg(info);
	l = get_length(args, (char *)info) + ft_strlen(info) - (count * 2);
	va_end(args);
	str = ft_calloc(sizeof(char), l + 1);
	if (!str)
		return (-1);
	va_start(args_cpy, info);
	str = the_gathering((char *)info, args_cpy, str);
	va_end(args_cpy);
	if (!str)
		return (-1);
	if (write(1, str, l) == -1)
		l = -1;
	free(str);
	return (l);
}

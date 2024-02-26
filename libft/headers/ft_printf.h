/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:38:56 by lvodak            #+#    #+#             */
/*   Updated: 2024/01/20 19:39:11 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_strwlen
{
	char	*content;
	int		cont_len;
}	t_stringl;

int			is_valid(char c);
int			get_length(va_list args, char *info);
int			ft_int_size(long n, char info);
int			ft_hex_size(unsigned long n, size_t base);
char		*ft_ltoa_base(unsigned long n, char *base);
int			ft_printf(const char *info, ...);
char		*strcatx(char *dst, char *src, int dstl, int l);
int			strlenx(void *str);
char		*error_free(char *str, char *temp);
char		*ft_dup(char *src);
t_stringl	final_check(char info, va_list args, char *str, int l);
char		*the_gathering2_5(va_list args, char info);

#endif
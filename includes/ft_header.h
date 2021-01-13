/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:29:57 by ameta             #+#    #+#             */
/*   Updated: 2021/01/13 17:33:39 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_params
{
	int			flag_zero;
	int			flag_minus;
	int			width;
	int			precision;
	int			isprecision;
	char		type;
}				t_params;

void			ft_get_flags(const char **fmt, int *flag_zero, int *flag_minus);
void			ft_get_precision(const char **fmt, va_list *ap,
					int *precision, int *isprecision);
char			ft_get_type(const char *fmt);
int				ft_get_width(const char **fmt, va_list *ap);
int				ft_handle(const char **fmt, va_list *ap, int *count);
void			ft_handle_c(t_params *params, va_list *ap, int *count);
void			ft_handle_i(t_params *params, va_list *ap,
					int *count, int sign);
void			ft_handle_p(t_params *params, va_list *ap, int *count);
void			ft_handle_percent(t_params *params, int *count);
void			ft_handle_s(t_params *params, va_list *ap, int *count);
void			ft_handle_x(t_params *params, va_list *ap, int *count);
void			ft_handle_u(t_params *params, va_list *ap, int *count);
void			ft_print_zero(t_params *params, int *count);
char			*ft_itoa_u(unsigned int n);
char			*ft_itoa_hex(unsigned long value);
int				ft_printf(const char *fmt, ...);
void			ft_putchar(char c, int *count);
void			ft_putnbr(int n, int *count);
void			ft_putstr(char *s, int size, int *count);
char			*ft_strtoupper(char *str);

#endif

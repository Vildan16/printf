//
// Created by ameta on 05.01.2021.
//

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_params
{
	int				flag_zero;
	int				flag_minus;
	int				width;
	int 			precision;
	char 			type;
}					t_params;

void	ft_get_flags(const char **fmt, int *flag_zero, int *flag_minus);
int		ft_get_precision(const char **fmt, va_list *ap);
char 	ft_get_type(const char *fmt);
int		ft_get_width(const char **fmt, va_list *ap);
int		ft_handle(const char **fmt, va_list *ap, int *count);
void 	ft_handle_c(t_params *params, va_list *ap, int *count);
void	ft_handle_i(t_params *params, va_list *ap, int *count);
void 	ft_handle_p(t_params *params, va_list *ap, int *count);
void	ft_handle_percent(t_params *params, int *count);
void	ft_handle_s(t_params *params, va_list *ap, int *count);
void	ft_handle_x(t_params *params, va_list *ap, int *count);
void	ft_handle_u(t_params *params, va_list *ap, int *count);
void	ft_print_zero(t_params *params, int *count);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa_hex(unsigned long long value);
void	ft_print_width(t_params params, int *len, int *count, int a);
int		ft_printf(const char *fmt, ...);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
char	*ft_strtolower(char *str);


#endif
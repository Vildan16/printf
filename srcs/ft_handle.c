//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

int		ft_handle(const char **fmt, va_list *ap, int *count)
{
	t_params params;

	ft_get_flags(fmt, &params.flag_zero, &params.flag_minus);
	params.width = ft_get_width(fmt, ap);
	params.precision = ft_get_precision(fmt, ap);
	params.type = ft_get_type(*fmt);
	if (params.type == '0')
		return(0);
	if (params.type == 'i' || params.type == 'd')
		ft_handle_i(params, ap, count);
	else if (params.type == 'c')
		ft_handle_c(params, ap, count);
	else if (params.type == 's')
		ft_handle_s(params, ap, count);
	else if (params.type == 'p')
		ft_handle_p(params, ap, count);
	else if (params.type == 'x' || params.type == 'X')
		ft_handle_xX(params, ap, count);
	else if (params.type == '%')
		ft_handle_percent(params, count);
	return (1);
}
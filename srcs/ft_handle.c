/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:14:38 by ameta             #+#    #+#             */
/*   Updated: 2021/01/14 13:19:11 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static void	ft_get_params(const char **fmt, va_list *ap, t_params *params)
{
	ft_get_flags(fmt, &params->flag_zero, &params->flag_minus);
	params->width = ft_get_width(fmt, ap);
	ft_get_precision(fmt, ap, &params->precision, &params->isprecision);
	params->type = ft_get_type(*fmt);
	params->isprecision = (params->precision < 0) ? 0 : params->isprecision;
	params->precision = (params->precision < 0) ? 0 :
							params->precision;
	params->flag_minus = (params->width < 0) ? 1 : params->flag_minus;
	params->width = params->width < 0 ? (-1 * params->width) : params->width;
}

int			ft_handle(const char **fmt, va_list *ap, int *count)
{
	t_params params;

	ft_get_params(fmt, ap, &params);
	if (params.type == '0')
		return (0);
	if (params.type == 'i' || params.type == 'd')
		ft_handle_i(&params, ap, count, 0);
	else if (params.type == 'c')
		ft_handle_c(&params, ap, count);
	else if (params.type == 's')
		ft_handle_s(&params, ap, count);
	else if (params.type == 'p')
		ft_handle_p(&params, ap, count);
	else if (params.type == 'u')
		ft_handle_u(&params, ap, count);
	else if (params.type == 'x' || params.type == 'X')
		ft_handle_x(&params, ap, count);
	else if (params.type == '%')
		ft_handle_percent(&params, count);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:14:14 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:17:45 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static void	ft_prints_min(t_params *params, va_list *ap, int *count)
{
	char	*string;
	int		len;
	int		i;

	i = 0;
	string = va_arg(*ap, char*);
	len = (!string) ? 6 : ft_strlen(string);
	len = (params->isprecision == 0 || len < params->precision) ?
			len : params->precision;
	if (!string)
		ft_putstr("(null)", len, count);
	else
		ft_putstr(string, len, count);
	while (i < (params->width - len))
	{
		ft_putchar(' ', count);
		i++;
	}
}

static void	ft_prints_nomin(t_params *params, va_list *ap, int *count)
{
	char	*string;
	int		len;
	int		i;

	i = 0;
	string = va_arg(*ap, char*);
	len = (!string) ? 6 : ft_strlen(string);
	len = (params->isprecision == 0 || len < params->precision) ?
			len : params->precision;
	while (i < (params->width - len))
	{
		ft_putchar(' ', count);
		i++;
	}
	if (!string)
		ft_putstr("(null)", len, count);
	else
		ft_putstr(string, len, count);
}

void		ft_handle_s(t_params *params, va_list *ap, int *count)
{
	if (params->isprecision == 1 && params->precision == 0 \
	&& params->width == 0)
	{
		va_arg(*ap, char *);
		return ;
	}
	if (params->flag_minus == 1)
		ft_prints_min(params, ap, count);
	else
		ft_prints_nomin(params, ap, count);
}

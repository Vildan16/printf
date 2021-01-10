/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:13:56 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:20:19 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static void	ft_printp_min(t_params *params, va_list *ap, int *count)
{
	void	*value;
	int		len;
	int		i;

	i = 0;
	value = va_arg(*ap, void*);
	len = (params->isprecision == 1 && params->precision != 0) ? 2 :
			ft_strlen(ft_itoa_hex((unsigned long)value)) + 2;
	len = (params->isprecision == 1 && value == 0) ? 2 :
			ft_strlen(ft_itoa_hex((unsigned long)value)) + 2;
	ft_putstr("0x", 2);
	*count += 2;
	if (params->precision != 1)
	{
		ft_putstr(ft_itoa_hex((unsigned long)value), 10000);
		*count += ft_strlen(ft_itoa_hex((unsigned long)value));
	}
	while (i < (params->width - len))
	{
		ft_putchar(' ');
		*count += 1;
		i++;
	}
}

static void	ft_printp_nomin(t_params *params, va_list *ap, int *count)
{
	void	*value;
	int		len;
	int		i;

	i = 0;
	value = va_arg(*ap, void*);
	len = (params->isprecision == 1 && params->precision != 0) ? 2 :
			ft_strlen(ft_itoa_hex((unsigned long)value)) + 2;
	len = (params->isprecision == 1 && value == 0) ? 2 :
			ft_strlen(ft_itoa_hex((unsigned long)value)) + 2;
	while (i < (params->width - len))
	{
		ft_putchar(' ');
		*count += 1;
		i++;
	}
	ft_putstr("0x", 2);
	*count += 2;
	if ((params->isprecision == 1 && params->precision != 0) || \
	(params->isprecision == 1 && value == 0))
		return ;
	else
	{
		ft_putstr(ft_itoa_hex((unsigned long)value), 10000);
		*count += ft_strlen(ft_itoa_hex((unsigned long)value));
	}
}

void		ft_handle_p(t_params *params, va_list *ap, int *count)
{
	if (params->flag_minus)
		ft_printp_min(params, ap, count);
	else
		ft_printp_nomin(params, ap, count);
}

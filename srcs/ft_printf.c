/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:15:24 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:15:25 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int		count;

	if (!fmt || !fmt[0])
		return (0);
	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (!ft_handle(&fmt, &ap, &count))
				return (-1);
		}
		else
		{
			ft_putchar(*fmt);
			count++;
		}
		fmt++;
	}
	va_end(ap);
	return (count);
}

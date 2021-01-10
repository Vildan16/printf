/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:12:50 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:12:52 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_get_precision(const char **fmt, va_list *ap)
{
	int		result;

	result = -1;
	if (**fmt == '.')
	{
		*fmt += 1;
		if (**fmt >= '0' && **fmt <= '9')
			result = ft_atoi(*fmt);
		else if (**fmt == '*')
			result = va_arg(*ap, int);
		else
			result = -1;
		while ((**fmt >= '0' && **fmt <= '9') || **fmt == '*' || **fmt == '-')
			*fmt += 1;
	}
	return (result);
}

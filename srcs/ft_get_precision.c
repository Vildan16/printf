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

void	ft_get_precision(const char **fmt, va_list *ap, int *precision, int *isprecision)
{
	*precision = 0;
	*isprecision = 0;
	if (**fmt == '.')
	{
		*isprecision = 1;
		*fmt += 1;
		if (**fmt >= '0' && **fmt <= '9')
			*precision = ft_atoi(*fmt);
		else if (**fmt == '*')
			*precision = va_arg(*ap, int);
		while ((**fmt >= '0' && **fmt <= '9') || **fmt == '*' || **fmt == '-')
			*fmt += 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:13:14 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:13:16 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_get_width(const char **fmt, va_list *ap)
{
	int		result;

	result = -1;
	if (**fmt >= '0' && **fmt <= '9')
		result = ft_atoi(*fmt);
	if (**fmt == '*')
		result = va_arg(*ap, int);
	while ((**fmt >= '0' && **fmt <= '9') || **fmt == '*')
		*fmt += 1;
	return (result);
}

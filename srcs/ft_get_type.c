/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:13:04 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:13:05 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	ft_get_type(const char *fmt)
{
	char	result;

	result = '0';
	if (*fmt == 'i' || *fmt == 'd')
		result = 'i';
	else if (*fmt == 'c')
		result = 'c';
	else if (*fmt == 's')
		result = 's';
	else if (*fmt == 'p')
		result = 'p';
	else if (*fmt == 'x')
		result = 'x';
	else if (*fmt == 'X')
		result = 'X';
	else if (*fmt == '%')
		result = '%';
	else if (*fmt == 'u')
		result = 'u';
	return (result);
}

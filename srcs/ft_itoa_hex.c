/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:14:50 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:19:33 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static int	ft_nn(unsigned long value)
{
	int	number;

	if (value == 0)
		return (1);
	number = 0;
	while (value != 0)
	{
		number++;
		value = value / 16;
	}
	return (number);
}

char		*ft_itoa_hex(unsigned long value)
{
	unsigned int	division;
	char			*hex;
	int				number;
	int				nn;

	nn = ft_nn(value);
	hex = (char *)malloc(sizeof(char) * (nn + 1));
	if (value == 0)
		hex[0] = '0';
	number = 0;
	while (value != 0)
	{
		division = value % 16;
		if (division < 10)
			hex[nn - number - 1] = 48 + division;
		else
			hex[nn - number - 1] = 87 + division;
		number++;
		value = value / 16;
	}
	hex[nn] = '\0';
	return (hex);
}

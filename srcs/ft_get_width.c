//
// Created by ameta on 07.01.2021.
//

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

//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

void	ft_get_flags(const char **fmt, int *flag_zero, int *flag_minus)
{
	*flag_zero = 0;
	*flag_minus = 0;
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '0')
			*flag_zero = 1;
		if (**fmt == '-')
			*flag_minus = 1;
		*fmt += 1;
	}
}

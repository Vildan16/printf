//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

char 	ft_get_type(const char *fmt)
{
	char 	result;

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
	return(result);
}
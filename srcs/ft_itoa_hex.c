//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

char	*ft_itoa_hex(unsigned long long value)
{
	char				*str;
	int					size;
	char				*tab;
	unsigned long long	tmp;

	size = 0;
	tab = "0123456789ABCDEF";
	tmp = value;
	while (tmp /= 16)
		size++;
	size++;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[(int)value % 16];
		size--;
		value /= 16;
	}
	return (str);
}

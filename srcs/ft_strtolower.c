//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

char		*ft_strtolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

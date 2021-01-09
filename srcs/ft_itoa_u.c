//
// Created by Anneliese Meta on 1/9/21.
//

#include "ft_header.h"

static int	ft_nn(unsigned int n)
{
	int		nn;

	nn = 0;
	if (n <= 0)
	{
		nn++;
		n = -1 * n;
	}
	while (n != 0)
	{
		n = n / 10;
		nn++;
	}
	return (nn);
}

char		*ft_itoa_u(unsigned int n)
{
	int		nn;
	char	*str;

	nn = ft_nn(n);
	str = (char *)malloc(sizeof(char) * (nn + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[nn - 1] = '0';
	str[nn] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -1 * n;
	}
	while (n != 0)
	{
		str[nn - 1] = n % 10 + '0';
		n = n / 10;
		nn--;
	}
	return (str);
}

//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

static void		ft_putnbr(int n)  //LIBFT - mod
{
	int		i;
	char	a[15];

	i = 0;
	if (n == 0)
		ft_putchar('0');
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -1 * n;
	}
	while (n != 0)
	{
		a[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(a[i]);
}
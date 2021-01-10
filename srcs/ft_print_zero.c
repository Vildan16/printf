
//
//
//

#include "ft_header.h"

void	ft_print_zero(t_params *params, int *count)
{
	int i;

	i = 0;
	while (i < params->width)
	{
		ft_putchar(' ');
		*count += 1;
		i++;
	}
}
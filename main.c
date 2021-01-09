//
// Created by ameta on 07.01.2021.
//

#include "./includes/ft_header.h"
#include <stdio.h>

int 	main(void)
{

	int ac = printf("%5%\n");
	int bc = ft_printf("%5%\n");
	printf("[%i][%i]\n", ac, bc);
	return (0);
}
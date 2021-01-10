//
// Created by ameta on 07.01.2021.
//

#include "./includes/ft_header.h"
#include <stdio.h>

int 	main(void)
{
	int a = 1245634;

	int ac = printf("%30X\n", a);
	int bc = ft_printf("%30X\n", a);
	printf("[%i][%i]\n", ac, bc);
	return (0);
}
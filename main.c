//
// Created by ameta on 07.01.2021.
//

#include "./includes/ft_header.h"
#include <stdio.h>

int 	main(void)
{
	int a = -123;

	int ac = printf("%.10i\n", a);
	int bc = ft_printf("%-.10i\n", a);
	printf("[%i][%i]\n", ac, bc);
	return (0);
}
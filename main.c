//
// Created by ameta on 07.01.2021.
//

#include "./includes/ft_header.h"
#include <stdio.h>

int 	main(void)
{
	int a = -123456;
	int ac = printf("a%2.2x\n", a);
	int bc = ft_printf("b%2.2x\n", a);
	printf("[%i][%i]\n", ac, bc);
	return (0);
}
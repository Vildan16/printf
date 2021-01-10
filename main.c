//
// Created by ameta on 07.01.2021.
//

#include "./includes/ft_header.h"
#include <stdio.h>

int 	main(void)
{
	char *a = "abcdegfhf";

	int ac = printf("%-p\n", a);
	int bc = ft_printf("%-p\n", a);
	printf("[%i][%i]\n", ac, bc);
	return (0);
}
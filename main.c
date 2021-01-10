//
// Created by ameta on 07.01.2021.
//

#include "./includes/ft_header.h"
#include <stdio.h>

int 	main(void)
{
	//int a = 245678;

	int ac = printf("A:%05%\n");
	int bc = ft_printf("B:%05%\n");
	printf("[%i][%i]\n", ac, bc);
	return (0);
}
#include "error.h"
#include <stdio.h> // careful
#include <stdlib.h>

void	die(const char *msg)
{
	printf("Error\n");
	if (msg)
		printf("%s\n", msg);
	exit(1);
}

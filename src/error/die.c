#include "error.h"

#include <stdlib.h>
#include <stdio.h> // careful

void die(const char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

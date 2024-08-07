#include "error/t_error.h"
#include "load.h"

#include <stdbool.h>

#include "deque/t_int_deque.h"
#include "libft/stdlib.h" // bad atoi

t_error stacks_from_strings(const char** numbers, int len, t_stacks* out)
{
	t_stacks	stacks;
	int i;

	if (numbers == NULL || out == NULL)
		return ERROR_NULL_OUT_PARAM;
	stacks.a = deque_new();
	stacks.b = deque_new();
	i = 0;
	while (i < len)
	{
		deque_push_back(&stacks.a, ft_atoi(numbers[i]));
		i++;
	}
	*out = stacks;
	return NO_ERROR;
}

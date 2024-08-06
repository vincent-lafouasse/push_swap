#include "load.h"

#include <stdbool.h>

#include "deque/t_int_deque.h"
#include "libft/stdlib.h"

t_stacks stacks_from_strings(const char** numbers, int len)
{
	t_stacks	stacks;
	int i;

	stacks.a = deque_new();
	stacks.b = deque_new();
	i = 0;
	while (i < len)
	{
		deque_push_back(&stacks.a, ft_atoi(numbers[i]));
		i++;
	}
	return stacks;
}

#include "load.h"

#include "deque/t_int_deque.h"

t_stacks stacks_from_strings(const char** numbers, int len)
{
	t_stacks	stacks;

	(void)numbers;
	(void)len;
	stacks.a = deque_new();
	stacks.b = deque_new();
	return stacks;
}

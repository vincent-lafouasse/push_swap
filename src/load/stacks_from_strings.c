#include "deque/t_int_deque.h"
#include "error/t_error.h"
#include "load.h"
#include "load_internals.h"

t_error	load_stacks(const char **numbers, int len, t_stacks *out)
{
	t_stacks	stacks;
	int			i;

	if (numbers == NULL || out == NULL)
		return (ERROR_NULL_OUT_PARAM);
	stacks.a = deque_new();
	stacks.b = deque_new();
	i = 0;
	while (i < len)
	{
		if (checked_atoi(numbers[i]).is_valid == false)
			return (deque_clear(&stacks.a), ERROR_NOT_A_NUMBER);
		if (deque_push_back(&stacks.a, checked_atoi(numbers[i]).val) == false)
			return (deque_clear(&stacks.a), ERROR_OOM);
		i++;
	}
	*out = stacks;
	return (NO_ERROR);
}

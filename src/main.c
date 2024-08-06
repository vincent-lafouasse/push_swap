#include "sort/sort.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"
#include "error/error.h"

static void clear_and_exit(t_stacks* stacks, t_int_deque* operations);

int	main(int ac, char** av)
{
	t_stacks	stacks;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	log_deque(stacks.a, NULL, false);

	if (simplify_verify(&stacks.a) == false)
		clear_and_exit(&stacks, NULL);
	log_deque(stacks.a, NULL, false);

	t_int_deque operations = radix_sort(&stacks);
	log_deque(stacks.a, NULL, false);

	log_operation_list(operations);
}

static void clear_and_exit(t_stacks* stacks, t_int_deque* operations)
{
	if (stacks)
	{
		deque_clear(&stacks->a);
		deque_clear(&stacks->b);
	}
	deque_clear(operations);
	die("Error");
}

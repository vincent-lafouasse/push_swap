#include "sort/sort.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"
#include "error/error.h"

#define VERBOSE true

static void clear_and_die(t_stacks* stacks, t_int_deque* operations, t_error error);

int	main(int ac, char** av)
{
	t_stacks	stacks;
	t_error err;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	log_deque(stacks.a, NULL, false);

	err = simplify_verify(&stacks.a);
	if (err != OK)
		clear_and_die(&stacks, NULL, err);
	log_deque(stacks.a, NULL, false);

	t_int_deque operations = radix_sort(&stacks);
	log_deque(stacks.a, NULL, false);

	log_operation_list(operations);
}

static void clear_and_die(t_stacks* stacks, t_int_deque* operations, t_error error)
{
	if (stacks)
	{
		deque_clear(&stacks->a);
		deque_clear(&stacks->b);
	}
	deque_clear(operations);
	if (VERBOSE)
		die(error_repr(error));
	else
		die(NULL);
}

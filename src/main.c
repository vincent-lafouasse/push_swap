#include "output/output.h"
#include "sort/sort.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"
#include "error/error.h"
#include "output/output.h"

#define VERBOSE true

static void clear(t_stacks* stacks, t_int_deque* operations);
static void clear_and_die(t_stacks* stacks, t_int_deque* operations, t_error error);

int	main(int ac, char** av)
{
	t_stacks	stacks;
	t_int_deque operations;
	t_error err;

	err = stacks_from_strings((const char**)av + 1, ac - 1, &stacks);
	if (err != NO_ERROR)
		clear_and_die(NULL, NULL, err);
	log_deque(stacks.a, NULL, false);

	err = simplify_verify(&stacks.a);
	if (err != NO_ERROR)
		clear_and_die(&stacks, NULL, err);
	log_deque(stacks.a, NULL, false);

	operations = radix_sort(&stacks);
	log_deque(stacks.a, NULL, false);

	output_operation_list(operations);
	clear(&stacks, &operations);
}

static void clear(t_stacks* stacks, t_int_deque* operations)
{
	if (stacks)
	{
		deque_clear(&stacks->a);
		deque_clear(&stacks->b);
	}
	deque_clear(operations);
}

static void clear_and_die(t_stacks* stacks, t_int_deque* operations, t_error error)
{
	clear(stacks, operations);
	if (VERBOSE)
		die(error_repr(error));
	else
		die(NULL);
}

#include "sort/sort.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "error/error.h"
#include "output/output.h"
#include "optimization/optimize.h"

#define VERBOSE true

static void clear(t_stacks* stacks, t_int_deque* operations);
static void clear_and_die(t_stacks* stacks, t_int_deque* operations, t_error error);

int	main(int ac, char** av)
{
	t_stacks	stacks;
	t_int_deque operations;
	t_error err;

	err = load_stacks((const char**)av + 1, ac - 1, &stacks);
	if (err != NO_ERROR)
		clear_and_die(NULL, NULL, err);
	err = simplify_verify(&stacks.a);
	if (err != NO_ERROR)
		clear_and_die(&stacks, NULL, err);
	operations = sort(&stacks);
	optimize(&operations);
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

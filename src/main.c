#include "sort/sort.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"
#include "error/error.h"

int	main(int ac, char** av)
{
	t_stacks	stacks;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	log_deque(stacks.a, NULL, false);

	if (simplify(&stacks.a) == false)
	{
		deque_clear(&stacks.a);
		die("Error");
	}
	log_deque(stacks.a, NULL, false);

	t_int_deque operations = radix_sort(&stacks);
	log_deque(stacks.a, NULL, false);

	log_operation_list(operations);
}

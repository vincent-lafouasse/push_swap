#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"

int	main(int ac, char** av)
{
	t_stacks	stacks;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	log_stacks_horizontal(stacks);
	deque_sort(&stacks.a);
	log_stacks_horizontal(stacks);
}

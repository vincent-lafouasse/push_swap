#include "deque/t_int_deque.h"
#include "array/array_operations.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"


void simplify(t_int_deque* dq)
{
	int* data = deque_copy_into_array(*dq);
	log_int_array(data, dq->sz);
	sort_array(data, dq->sz);
	log_int_array(data, dq->sz);
}

int	main(int ac, char** av)
{
	t_stacks	stacks;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	log_stacks_horizontal(stacks);
	simplify(&stacks.a);
}

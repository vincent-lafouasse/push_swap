#include "deque/t_int_deque.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"

#include <stdlib.h>
#include <assert.h>

int* copy_into_array(const t_int_deque dq)
{
	int* array = malloc(dq.sz * sizeof(*array));
	if (!array)
		return NULL;

	size_t i = 0;
	t_int_list* current = dq.head;
	while (current && i < dq.sz)
	{
		array[i] = current->val;
		current = current->next;
		i++;
	}

	assert(i == dq.sz);
	assert(current == NULL);
	return array;
}

void simplify(t_int_deque* dq)
{
	int* data = copy_into_array(*dq);
}

int	main(int ac, char** av)
{
	t_stacks	stacks;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	log_stacks_horizontal(stacks);
	deque_sort(&stacks.a);
	log_stacks_horizontal(stacks);
}

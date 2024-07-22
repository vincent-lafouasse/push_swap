#include "deque/t_int_deque.h"
#include "array/array_operations.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"

#include <stdlib.h>
#include <stdio.h> // living dangerously

void simplify(t_int_deque* dq);

size_t n_bits(unsigned int n)
{
	size_t out = 0;

	while (n)
	{
		n /= 2;
		out++;
	}
	return out;
}

void split_binary_buckets(t_stacks* stacks, size_t bit_position)
{
	(void)stacks;
	(void)bit_position;
}

int	main(int ac, char** av)
{
	t_stacks	stacks;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	log_stacks_horizontal(stacks, false);
	simplify(&stacks.a);
	log_stacks_horizontal(stacks, false);
	log_stacks_horizontal(stacks, true);
}

void simplify(t_int_deque* dq)
{
	int* sorted_data = deque_copy_into_array(*dq);
	//log_int_array(sorted_data, dq->sz);
	sort_array(sorted_data, dq->sz);
	//log_int_array(sorted_data, dq->sz);

	t_int_deque out = deque_new();
	int index;
	t_int_list* current = dq->head;
	while (current)
	{
		index = index_of(current->val, sorted_data, dq->sz);
		if (index < 0)
			exit(1);
		deque_push_back(&out, index);
		current = current->next;
	}
	deque_clear(dq);
	*dq = out;
}

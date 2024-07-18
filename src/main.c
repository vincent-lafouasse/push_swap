#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"

#include <stdlib.h>

typedef struct s_ordering_ctx {
	int val;
	size_t original_ordering;
} t_ordering_ctx;

t_int_deque simplify(t_int_deque* dq)
{
	t_ordering_ctx* original_order;
	t_int_list* current;
	size_t i;

	original_order = malloc(dq->sz * sizeof(*original_order));
	if (!original_order)
		return deque_new();
	current = dq->head;
	i = 0;
	while (i < dq->sz)
	{
		original_order[i] = (t_ordering_ctx){current->val, i};
		current = current->next;
		i++;
	}

	return *dq;
}

int	main(int ac, char** av)
{
	t_stacks	stacks;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	log_stacks_horizontal(stacks);
	deque_sort(&stacks.a);
	log_stacks_horizontal(stacks);
}

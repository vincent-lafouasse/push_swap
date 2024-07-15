#include "t_stack.h"

static void swap(t_int_deque* dq);

void swap_a(t_stacks *stacks);
void swap_b(t_stacks *stacks);
void swap_both(t_stacks *stacks);

static void swap(t_int_deque* dq)
{
	if (!dq || dq->sz == 0 || dq->sz == 1)
		return;
}

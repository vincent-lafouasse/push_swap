#include "t_stack.h"


void rotate_a(t_stacks *stacks)
{
	if (!stacks)
		return;
	deque_rotate_pull(&stacks->a);
}

void rotate_b(t_stacks *stacks)
{
	if (!stacks)
		return;
	deque_rotate_pull(&stacks->b);
}

void rotate_both(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}

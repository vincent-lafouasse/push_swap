#include "t_stacks.h"

void	rrotate_a(t_stacks *stacks)
{
	if (!stacks)
		return ;
	deque_rotate_push(&stacks->a);
}

void	rrotate_b(t_stacks *stacks)
{
	if (!stacks)
		return ;
	deque_rotate_push(&stacks->b);
}

void	rrotate_both(t_stacks *stacks)
{
	rrotate_a(stacks);
	rrotate_b(stacks);
}

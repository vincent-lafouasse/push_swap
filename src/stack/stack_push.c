#include "deque/t_int_deque.h"
#include "t_stack.h"

static void	move_top(t_int_deque *from, t_int_deque *to);

void	push_a(t_stacks *stacks)
{
	if (!stacks)
		return ;
	move_top(&stacks->b, &stacks->a);
}

void	push_b(t_stacks *stacks)
{
	if (!stacks)
		return ;
	move_top(&stacks->a, &stacks->b);
}

static void	move_top(t_int_deque *from, t_int_deque *to)
{
	t_int_list	*node;

	if (!from || !to || from->sz == 0)
		return ;
	node = deque_pop_front(from);
	deque_push_front_link(to, node);
}

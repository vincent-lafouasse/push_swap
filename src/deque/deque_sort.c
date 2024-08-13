#include "t_int_deque.h"
#include <stdbool.h>

static void	swap_with_next(t_int_list *node);
static void	swap_int(t_i32 *a, t_i32 *b);

void	deque_sort(t_int_deque *dq)
{
	bool		is_sorted;
	t_int_list	*current;

	if (!dq || dq->sz <= 1)
		return ;
	is_sorted = false;
	while (!is_sorted)
	{
		is_sorted = true;
		current = dq->head;
		while (current->next)
		{
			if (current->val > current->next->val)
			{
				swap_with_next(current);
				is_sorted = false;
			}
			current = current->next;
		}
	}
}

static void	swap_with_next(t_int_list *node)
{
	if (!node || !node->next)
		return ;
	swap_int((t_i32 *)&node->val, (t_i32 *)&node->next->val);
}

static void	swap_int(t_i32 *a, t_i32 *b)
{
	t_i32	buffer;

	if (!a || !b)
		return ;
	buffer = *a;
	*a = *b;
	*b = buffer;
}

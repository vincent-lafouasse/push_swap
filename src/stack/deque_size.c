#include "t_int_deque.h"

bool	deque_is_empty(const t_int_deque dq)
{
	return (deque_size(dq) == 0);
}

size_t	deque_size(const t_int_deque dq)
{
	size_t		sz;
	t_int_list	*current;

	sz = 0;
	current = dq.head;
	while (current)
	{
		sz++;
		current = current->next;
	}
	return (sz);
}

#include "t_int_deque.h"

t_int_deque	deque_deep_copy(const t_int_deque dq)
{
	t_int_deque out;
	t_int_list* current;

	current = dq.head;
	out = deque_new();
	while (current)
	{
		deque_push_back(&out, current->val);
		current = current->next;
	}
	return out;
}

#include "t_int_deque.h"

bool deque_is_sorted(t_int_deque dq)
{
	if (dq.sz <= 1)
		return true;
	while (dq.head->next)
	{
		if (dq.head->val > dq.head->next->val)
			return false;
		dq.head = dq.head->next;
	}
	return true;
}

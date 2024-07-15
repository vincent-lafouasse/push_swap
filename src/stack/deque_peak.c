#include "t_int_deque.h"

const t_int_list	*deque_peek_front(const t_int_deque dq)
{
	return (dq.head);
}

const t_int_list	*deque_peek_back(const t_int_deque dq)
{
	return (dq.tail);
}

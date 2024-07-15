#include "t_int_deque.h"

t_int_list	*deque_pop_front(t_int_deque *dq)
{
	t_int_list* out;

	if (dq->sz == 0)
		return NULL;
	if (dq->sz == 1)
	{
		out = dq->head;
		dq->head = dq->tail = NULL;
		dq->sz = 0;
		return out;
	}
	out = dq->head;
	dq->head = out->next;
	dq->head->prev = NULL;
	return (out);
}

t_int_list	*deque_pop_back(t_int_deque *dq)
{
	t_int_list* out;

	if (dq->sz == 0)
		return NULL;
	if (dq->sz == 1)
	{
		out = dq->tail;
		dq->head = dq->tail = NULL;
		dq->sz = 0;
		return out;
	}
	out = dq->tail;
	dq->tail = out->prev;
	dq->tail->next = NULL;
	return (out);
}

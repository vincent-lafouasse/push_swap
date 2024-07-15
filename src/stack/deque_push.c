#include "t_int_deque.h"

void deque_push_front_link(t_int_deque *dq, t_int_list *link)
{
	if (!link || !dq)
		return;
	if (deque_size(*dq) == 0)
	{
		dq->head = dq->tail = link;
		return;
	}
	link->next = dq->head;
	dq->head->prev = link;
	dq->head = link;
}

void deque_push_back_link(t_int_deque *dq, t_int_list *link)
{
	if (!link || !dq)
		return;
	if (deque_size(*dq) == 0)
	{
		dq->head = dq->tail = link;
		return;
	}
	link->prev = dq->tail;
	dq->tail->next = link;
	dq->tail = link;
}

bool	deque_push_front(t_int_deque *dq, int val)
{
	(void)dq;
	(void)val;
	return (true);
}

bool	deque_push_back(t_int_deque *dq, int val)
{
	(void)dq;
	(void)val;
	return (true);
}

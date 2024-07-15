#include "t_int_deque.h"

void	deque_push_front_link(t_int_deque *dq, t_int_list *link)
{
	if (!link || !dq)
		return ;
	if (dq->sz == 0)
	{
		dq->head = dq->tail = link;
		dq->sz++;
		return ;
	}
	link->next = dq->head;
	dq->head->prev = link;
	dq->head = link;
	dq->sz++;
}

void	deque_push_back_link(t_int_deque *dq, t_int_list *link)
{
	if (!link || !dq)
		return ;
	if (dq->sz == 0)
	{
		dq->head = dq->tail = link;
		dq->sz++;
		return ;
	}
	link->prev = dq->tail;
	dq->tail->next = link;
	dq->tail = link;
	dq->sz++;
}

bool	deque_push_front(t_int_deque *dq, int val)
{
	t_int_list	*link;

	link = list_new(val);
	if (!link)
		return (false);
	deque_push_front_link(dq, link);
	return (true);
}

bool	deque_push_back(t_int_deque *dq, int val)
{
	t_int_list	*link;

	link = list_new(val);
	if (!link)
		return (false);
	deque_push_back_link(dq, link);
	return (true);
}

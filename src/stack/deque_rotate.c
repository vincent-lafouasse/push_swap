#include "t_int_deque.h"

void	deque_rotate_push(t_int_deque *dq)
{
	t_int_list	*node;

	if (!dq || dq->sz == 0 || dq->sz == 1)
		return ;
	node = dq->tail;
	node->prev->next = NULL;
	node->prev = NULL;
	node->next = dq->head;
	dq->head->prev = node;
	dq->head = node;
}

void	deque_rotate_pull(t_int_deque *dq)
{
	t_int_list	*node;

	if (!dq || dq->sz == 0 || dq->sz == 1)
		return ;
	node = dq->head;
	node->next->prev = NULL;
	node->next = NULL;
	node->prev = dq->tail;
	dq->tail->next = node;
	dq->tail = node;
}

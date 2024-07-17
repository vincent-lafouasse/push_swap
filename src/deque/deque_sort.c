#include "t_int_deque.h"

#include <stdbool.h>

static void swap_with_next(t_int_list* node);
static void swap_int(int* a, int* b);

void deque_sort(t_int_deque* dq)
{
	if (!dq || dq->sz <= 1)
		return ;
}

static void swap_with_next(t_int_list* node)
{
	t_int_list* next;

	if (!node || !node->next)
		return;
	next = node->next;
	node->prev->next = next;
	next->prev = node->prev;
	next->next->prev = node;
}

static void swap_int(int* a, int* b)
{
	int buffer;
	
	if (!a || !b)
		return;
	buffer = *a;
	*a = *b;
	*b = buffer;
}

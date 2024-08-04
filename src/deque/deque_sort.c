#include "t_int_deque.h"

#include <stdbool.h>

static void swap_with_next(t_int_list* node);
static void swap_int(int32_t* a, int32_t* b);

void deque_sort(t_int_deque* dq)
{
	bool is_sorted;
	t_int_list* current;

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

static void swap_with_next(t_int_list* node)
{
	if (!node || !node->next)
		return;
	swap_int((int32_t*)&node->val, (int32_t*)&node->next->val);
}

static void swap_int(int32_t* a, int32_t* b)
{
	int32_t buffer;
	
	if (!a || !b)
		return;
	buffer = *a;
	*a = *b;
	*b = buffer;
}

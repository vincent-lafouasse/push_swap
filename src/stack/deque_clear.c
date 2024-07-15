#include "t_int_deque.h"
#include <stdlib.h>

void	deque_clear(t_int_deque *dq)
{
	t_int_list	*current;
	t_int_list	*buffer;

	current = dq->head;
	while (current)
	{
		buffer = current->next;
		free(current);
		current = buffer;
	}
	dq->head = NULL;
	dq->tail = NULL;
}

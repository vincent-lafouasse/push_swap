#include "t_int_deque.h"
#include <assert.h>
#include <stdlib.h>

t_int_deque	deque_deep_copy(const t_int_deque dq)
{
	t_int_deque	out;
	t_int_list	*current;

	current = dq.head;
	out = deque_new();
	while (current)
	{
		deque_push_back(&out, current->val);
		current = current->next;
	}
	return (out);
}

t_i32	*deque_copy_into_array(const t_int_deque dq)
{
	t_i32		*array;
	size_t		i;
	t_int_list	*current;

	array = malloc(dq.sz * sizeof(*array));
	if (!array)
		return (NULL);
	i = 0;
	current = dq.head;
	while (current && i < dq.sz)
	{
		array[i] = current->val;
		current = current->next;
		i++;
	}
	assert(i == dq.sz);
	assert(current == NULL);
	return (array);
}

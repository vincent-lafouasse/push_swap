#include "sort.h"

#include <stdlib.h>
#include "array/array_operations.h"

bool simplify_verify(t_int_deque* dq)
{
	int* sorted_data = deque_copy_into_array(*dq);
	if (sorted_data == NULL)
		return false;
	sort_array(sorted_data, dq->sz);
	if (sorted_array_contains_duplicates(sorted_data, dq->sz))
		return (free(sorted_data), false);

	t_int_deque out = deque_new();
	int index;
	t_int_list* current = dq->head;
	while (current)
	{
		index = index_of(current->val, sorted_data, dq->sz);
		if (index < 0)
			return false;
		deque_push_back(&out, index);
		current = current->next;
	}
	deque_clear(dq);
	*dq = out;
	return true;
}
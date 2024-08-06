#include "sort.h"

#include "array/array_operations.h"

#include <stdlib.h> // careful

void simplify(t_int_deque* dq)
{
	int* sorted_data = deque_copy_into_array(*dq);
	//log_int_array(sorted_data, dq->sz);
	sort_array(sorted_data, dq->sz);
	//log_int_array(sorted_data, dq->sz);

	t_int_deque out = deque_new();
	int index;
	t_int_list* current = dq->head;
	while (current)
	{
		index = index_of(current->val, sorted_data, dq->sz);
		if (index < 0)
			exit(1); // needs better error handling
		deque_push_back(&out, index);
		current = current->next;
	}
	deque_clear(dq);
	*dq = out;
}

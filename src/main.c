#include "deque/t_int_deque.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"

#include <stdbool.h>

void ft_swap(int* a, int* b)
{
	int buffer = *a;
	*a = *b;
	*b = buffer;
}

void sort_array(int* array, size_t len)
{
	bool is_sorted = false;
	size_t i;

	while (!is_sorted)
	{
		is_sorted = true;
		i = 0;
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
			{
				ft_swap(array + i, array + i + 1);
				is_sorted = false;
			}
			i++;
		}
	}
}

void simplify(t_int_deque* dq)
{
	int* data = deque_copy_into_array(*dq);
	log_int_array(data, dq->sz);
	sort_array(data, dq->sz);
	log_int_array(data, dq->sz);
}

int	main(int ac, char** av)
{
	t_stacks	stacks;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	log_stacks_horizontal(stacks);
	simplify(&stacks.a);
}

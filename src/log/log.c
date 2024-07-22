#include "log.h"
#include "deque/t_int_deque.h"

#include <stdio.h> // careful my dude

void log_stacks_horizontal(const t_stacks s, bool binary)
{
	log_deque(s.a, "a", binary);
	log_deque(s.b, "b", binary);
}

void log_int_array(const int* array, size_t len)
{
	size_t i = 0;

	while (i < len)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

void log_deque(const t_int_deque dq, const char* name, bool binary)
{
	t_int_list* current;

	if (name) 
		printf("%s : ", name);
	if (dq.sz == 0)
	{
		printf("\n");
		return;
	}
	current = dq.head;
	if (binary)
		printf("%b", current->val);
	else
		printf("%d", current->val);
	current = current->next;
	while (current)
	{
		printf("->%d", current->val);
		current = current->next;
	}
	printf("\n");
}

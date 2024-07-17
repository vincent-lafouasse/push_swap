#include "log.h"
#include "deque/t_int_deque.h"

#include <stdio.h> // careful my dude

static void log_deque(const t_int_deque dq, const char* name);

void log_stacks_horizontal(const t_stacks s)
{
	log_deque(s.a, "a");
	log_deque(s.b, "b");
}

static void log_deque(const t_int_deque dq, const char* name)
{
	t_int_list* current;

	printf("%s : ", name);
	if (dq.sz == 0)
	{
		printf("\n");
		return;
	}
	current = dq.head;
	printf("%d", current->val);
	current = current->next;
	while (current)
	{
		printf("->%d", current->val);
		current = current->next;
	}
	printf("\n");
}

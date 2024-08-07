#include "log.h"
#include "deque/t_int_deque.h"

#include <stdio.h> // careful my dude

void log_stacks_horizontal(const t_stacks s, bool binary)
{
	log_deque(s.a, "a", binary);
	log_deque(s.b, "b", binary);
}

void log_int_array(const t_i32* array, size_t len)
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
		printf("->");
		if (binary)
			printf("%b", current->val);
		else
			printf("%d", current->val);
		current = current->next;
	}
	printf("\n");
}

void log_operation(t_operation op)
{
	if (op == OP_SWAP_A)
		printf("swap A");
	else if (op == OP_SWAP_B)
		printf("swap B");
	else if (op == OP_SWAP_BOTH)
		printf("swap both");

	else if (op == OP_PUSH_ONTO_A)
		printf("push onto A");
	else if (op == OP_PUSH_ONTO_B)
		printf("push onto B");

	else if (op == OP_ROTATE_A)
		printf("rotate A");
	else if (op == OP_ROTATE_B)
		printf("rotate B");
	else if (op == OP_ROTATE_BOTH)
		printf("rotate both");

	else if (op == OP_RROTATE_A)
		printf("rrotate A");
	else if (op == OP_RROTATE_B)
		printf("rrotate B");
	else if (op == OP_RROTATE_BOTH)
		printf("rrotate both");

	else
		printf("invalid operation");
}

void log_operation_list(const t_int_deque ops)
{
	t_int_list* current = ops.head;

	printf("operations:\n\n");
	while (current)
	{
		log_operation(current->val);
		printf("\n");
		current = current->next;
	}
}

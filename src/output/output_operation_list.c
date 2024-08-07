#include "output.h"

#include "stack/t_stacks.h"
#include <stdio.h> // careful my guy

void output_operation_list(const t_int_deque ops);

static void output_operation(t_operation op)
{
	if (op == OP_SWAP_A)
		printf("sa");
	else if (op == OP_SWAP_B)
		printf("sB");
	else if (op == OP_SWAP_BOTH)
		printf("ss");

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

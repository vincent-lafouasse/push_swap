#include "optimize.h"
#include "stack/t_stacks.h"

static bool			optimize_once(t_int_deque *operations);
static bool can_delete_node(t_int_list* node);
static t_operation	opposite_op(t_operation op);

void	optimize(t_int_deque *operations)
{
	if (operations == NULL || operations->sz <= 1)
		return ;
}

static bool can_delete_node(t_int_list* node)
{
	if (!node || !node->next)
		return false;
	return (t_operation)node->next->val == opposite_op(node->val);
}

static t_operation	opposite_op(t_operation op)
{
	if (op == OP_SWAP_A)
		return (OP_SWAP_A);
	if (op == OP_SWAP_B)
		return (OP_SWAP_B);
	if (op == OP_SWAP_BOTH)
		return (OP_SWAP_BOTH);
	if (op == OP_PUSH_ONTO_A)
		return (OP_PUSH_ONTO_B);
	if (op == OP_PUSH_ONTO_B)
		return (OP_PUSH_ONTO_A);
	if (op == OP_ROTATE_A)
		return (OP_RROTATE_A);
	if (op == OP_ROTATE_B)
		return (OP_RROTATE_B);
	if (op == OP_ROTATE_BOTH)
		return (OP_RROTATE_BOTH);
	if (op == OP_RROTATE_A)
		return (OP_ROTATE_A);
	if (op == OP_RROTATE_B)
		return (OP_ROTATE_B);
	if (op == OP_RROTATE_BOTH)
		return (OP_ROTATE_BOTH);
	return (NULL_OP);
}

#include "libft/ft_io.h"
#include "output.h"
#include "stack/t_stacks.h"

static void	output_operation(t_operation op);

void	output_operation_list(const t_int_deque ops)
{
	t_int_list	*current;

	current = ops.head;
	while (current)
	{
		output_operation(current->val);
		current = current->next;
	}
}

static void	output_operation(t_operation op)
{
	if (op == OP_SWAP_A)
		ft_putstr("sa\n");
	else if (op == OP_SWAP_B)
		ft_putstr("sb\n");
	else if (op == OP_SWAP_BOTH)
		ft_putstr("ss\n");
	else if (op == OP_PUSH_ONTO_A)
		ft_putstr("pa\n");
	else if (op == OP_PUSH_ONTO_B)
		ft_putstr("pb\n");
	else if (op == OP_ROTATE_A)
		ft_putstr("ra\n");
	else if (op == OP_ROTATE_B)
		ft_putstr("rb\n");
	else if (op == OP_ROTATE_BOTH)
		ft_putstr("rr\n");
	else if (op == OP_RROTATE_A)
		ft_putstr("rra\n");
	else if (op == OP_RROTATE_B)
		ft_putstr("rrb\n");
	else if (op == OP_RROTATE_BOTH)
		ft_putstr("rrr\n");
	else
		ft_putstr("invalid operation");
}

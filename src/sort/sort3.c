/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:49:07 by poss              #+#    #+#             */
/*   Updated: 2024/08/14 23:55:01 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_internals.h"

#define NEEDS_ROTATE 1
#define NEEDS_RROTATE -1
#define NOT_SOLVED_BY_ROTATE 0

static int	try_rotate(t_stacks *stacks)
{
	rotate_a(stacks);
	if (deque_is_sorted(stacks->a))
	{
		rrotate_a(stacks);
		return (NEEDS_ROTATE);
	}
	rrotate_a(stacks);
	rrotate_a(stacks);
	if (deque_is_sorted(stacks->a))
	{
		rotate_a(stacks);
		return (NEEDS_RROTATE);
	}
	rotate_a(stacks);
	return (NOT_SOLVED_BY_ROTATE);
}

static t_error	fill_ops(t_operation op1, t_operation op2, t_int_deque *ops_out)
{
	if (!ops_out)
		return (ERROR_NULL_OUT_PARAM);
	if (op1 == NULL_OP)
		return (NO_ERROR);
	if (deque_push_back(ops_out, op1) == false)
		return (ERROR_OOM);
	if (op2 == NULL_OP)
		return (NO_ERROR);
	if (deque_push_back(ops_out, op2) == false)
		return (ERROR_OOM);
	return (NO_ERROR);
}

t_error	sort3(t_stacks *stacks, t_int_deque *ops_out)
{
	if (!stacks || !ops_out)
		return ERROR_NULL_OUT_PARAM;
	*ops_out = deque_new();
	if (deque_is_sorted(stacks->a))
		return (NO_ERROR);
	if (try_rotate(stacks) == NEEDS_ROTATE)
		return (fill_ops(OP_ROTATE_A, NULL_OP, ops_out));
	if (try_rotate(stacks) == NEEDS_RROTATE)
		return (fill_ops(OP_RROTATE_A, NULL_OP, ops_out));
	swap_a(stacks);
	if (deque_is_sorted(stacks->a))
		return (fill_ops(OP_SWAP_A, NULL_OP, ops_out));
	if (try_rotate(stacks) == NEEDS_ROTATE)
		return (fill_ops(OP_SWAP_A, OP_ROTATE_A, ops_out));
	else
		return (fill_ops(OP_SWAP_A, OP_RROTATE_A, ops_out));
}

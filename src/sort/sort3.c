/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:49:07 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 20:18:11 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "sort_internals.h"

static bool		stack_is_like(const char *pattern, const t_stacks *stacks);
static t_error	fill_ops(t_operation op1, t_operation op2,
					t_int_deque *ops_out);

/*
123 -> no op
312 -> ra
231 -> rra
213 -> sa
132 -> sa ra
321 -> sa rra
*/

t_error	sort3(t_stacks *stacks, t_int_deque *ops_out)
{
	if (!stacks || !ops_out)
		return (ERROR_NULL_OUT_PARAM);
	if (stack_is_like("123", stacks))
		return (fill_ops(NULL_OP, NULL_OP, ops_out));
	else if (stack_is_like("312", stacks))
		return (fill_ops(OP_ROTATE_A, NULL_OP, ops_out));
	else if (stack_is_like("231", stacks))
		return (fill_ops(OP_RROTATE_A, NULL_OP, ops_out));
	else if (stack_is_like("213", stacks))
		return (fill_ops(OP_SWAP_A, NULL_OP, ops_out));
	else if (stack_is_like("132", stacks))
		return (fill_ops(OP_SWAP_A, OP_ROTATE_A, ops_out));
	else if (stack_is_like("321", stacks))
		return (fill_ops(OP_SWAP_A, OP_RROTATE_A, ops_out));
	return (ERROR_UNREACHABLE);
}

static bool	stack_is_like(const char *pattern, const t_stacks *stacks)
{
	int	max_index;
	int	min_index;

	if (!stacks || !pattern)
		return (false);
	if (!ft_strchr(pattern, '1') || !ft_strchr(pattern, '3'))
		return (false);
	min_index = ft_strchr(pattern, '1') - pattern;
	max_index = ft_strchr(pattern, '3') - pattern;
	return ((deque_find_max(&stacks->a) == max_index)
		&& (deque_find_min(&stacks->a) == min_index));
}

static t_error	fill_ops(t_operation op1, t_operation op2, t_int_deque *ops_out)
{
	if (!ops_out)
		return (ERROR_NULL_OUT_PARAM);
	*ops_out = deque_new();
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

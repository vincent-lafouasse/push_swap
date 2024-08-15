/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:52:33 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 20:45:09 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_internals.h"

t_error	move_top_elements(t_stacks *stacks, t_int_deque *ops_out)
{
	size_t	n_elements_to_move;

	if (!stacks || !ops_out)
		return (ERROR_NULL_OUT_PARAM);
	n_elements_to_move = stacks->a.sz - 3;
	while (n_elements_to_move)
	{
		move_top_element(stacks, ops_out);
		n_elements_to_move--;
	}
	return (NO_ERROR);
}

t_error	push_all_of_b_onto_a(t_stacks *stacks, t_int_deque *ops_out)
{
	if (!stacks || !ops_out)
		return (ERROR_NULL_OUT_PARAM);
	while (stacks->b.sz)
	{
		push_a(stacks);
		if (deque_push_back(ops_out, OP_PUSH_ONTO_A) == false)
			return (ERROR_OOM);
	}
	return (NO_ERROR);
}

t_error	sort5(t_stacks *stacks, t_int_deque *ops_out)
{
	t_int_deque	sort3_operations;
	t_error		err;

	if (!stacks || !ops_out)
		return (ERROR_NULL_OUT_PARAM);
	*ops_out = deque_new();
	if (deque_is_sorted(stacks->a))
		return (NO_ERROR);
	err = move_top_elements(stacks, ops_out);
	if (err != NO_ERROR)
		return (err);
	err = sort3(stacks, &sort3_operations);
	if (err != NO_ERROR)
		return (err);
	deque_append(ops_out, &sort3_operations);
	return (push_all_of_b_onto_a(stacks, ops_out));
}

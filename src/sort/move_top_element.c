/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:21:47 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 20:33:41 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_internals.h"

static t_error	rotate_n_times(size_t n, t_stacks *stacks, t_int_deque *ops_out);
static t_error	reverse_rotate_n_times(size_t n, t_stacks *stacks,
			t_int_deque *ops_out);


t_error	move_top_element(t_stacks *stacks, t_int_deque *ops_out)
{
	int	index_of_min;
	int	i;
	t_error err;

	index_of_min = deque_find_min(&stacks->a);
	i = 0;
	if (index_of_min == -1)
		return (ERROR_ELEMENT_NOT_FOUND);
	if (index_of_min < (int)stacks->a.sz - index_of_min)
	{
		err = rotate_n_times(index_of_min, stacks, ops_out);
		if (err != NO_ERROR)
			return err;
	}
	else
	{
		err = reverse_rotate_n_times(index_of_min, stacks, ops_out);
		if (err != NO_ERROR)
			return err;
	}
	push_b(stacks);
	if (deque_push_back(ops_out, OP_PUSH_ONTO_B) == false)
		return ERROR_OOM;
	return (NO_ERROR);
}

static t_error	rotate_n_times(size_t n, t_stacks *stacks, t_int_deque *ops_out)
{
	while (n)
	{
		rotate_a(stacks);
		if (deque_push_back(ops_out, OP_ROTATE_A) == false)
			return ERROR_OOM;
		n--;
	}
	return NO_ERROR;
}

static t_error	reverse_rotate_n_times(size_t n, t_stacks *stacks,
			t_int_deque *ops_out)
{
	while (n)
	{
		rrotate_a(stacks);
		if (deque_push_back(ops_out, OP_RROTATE_A) == false)
			return ERROR_OOM;
		n--;
	}
	return NO_ERROR;
}

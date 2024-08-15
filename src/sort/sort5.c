/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:52:33 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 13:01:57 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_internals.h"

void	move_top_element(t_stacks *stacks, t_int_deque *ops_out)
{
	int	index_of_min;
	int	i;

	index_of_min = deque_find_min(&stacks->a);
	i = 0;
	if (index_of_min == -1)
		return ;
	if (index_of_min < (int)stacks->a.sz - index_of_min)
	{
		while (i < index_of_min)
		{
			// either rotate or rrotate
			// and push onto ops
			i++;
		}
	}
	else
	{
		// opposite
	}
	push_b(stacks);
	// signal push b
}

void	move_top_elements(t_stacks *stacks, t_int_deque *ops_out)
{
	size_t	n_elements_to_move;

	if (!stacks || !ops_out)
		return ;
	n_elements_to_move = stacks->a.sz - 3;
	while (n_elements_to_move)
	{
		move_top_element(stacks, ops_out);
		n_elements_to_move--;
	}
}

t_error	sort5(t_stacks *stacks, t_int_deque *ops_out)
{
	t_int_deque	*sort3_operations;

	if (!stacks || !ops_out)
		return (ERROR_NULL_OUT_PARAM);
	*ops_out = deque_new();
	if (deque_is_sorted(stacks->a))
		return (NO_ERROR);
	return (NO_ERROR);
}

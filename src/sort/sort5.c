/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:52:33 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 00:16:06 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_internals.h"
#include <limits.h>

int find_min(const t_int_deque* dq)
{
	int i;
	int min;
	int index_of_min;
	t_int_list* current;

	if (!dq || dq->sz == 0)
		return -1;
	min = INT_MAX;
	i = 0;
	index_of_min = -1;
	current = dq->head;
	while (current)
	{
		if (current->val < min)
		{
			index_of_min = i;
			min = current->val;
		}
		current = current->next;
		i++;
	}
	return index_of_min;
}

void move_top_element(t_stacks *stacks, t_int_deque *ops_out)
{
	int index_of_min = find_min(&stacks->a);
	int i = 0;

	if (index_of_min == -1)
		return;
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

void move_top_elements(t_stacks *stacks, t_int_deque *ops_out)
{
	size_t n_elements_to_move;

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
	t_int_deque* sort3_operations;

	if (!stacks || !ops_out)
		return ERROR_NULL_OUT_PARAM;
	*ops_out = deque_new();
	if (deque_is_sorted(stacks->a))
		return (NO_ERROR);
	return NO_ERROR;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:21:47 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 20:23:26 by poss             ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:29 by poss              #+#    #+#             */
/*   Updated: 2024/08/14 21:48:24 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_internals.h"

t_error	sort2(t_stacks *stacks, t_int_deque *ops_out)
{
	if (!stacks || !ops_out)
		return (ERROR_NULL_OUT_PARAM);
	*ops_out = deque_new();
	if (stacks->a.head->val == 0)
	{
		return (NO_ERROR);
	}
	if (deque_push_front(ops_out, OP_SWAP_A))
		return (NO_ERROR);
	else
		return (ERROR_OOM);
}

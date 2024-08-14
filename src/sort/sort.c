/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:12 by poss              #+#    #+#             */
/*   Updated: 2024/08/14 21:43:41 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_internals.h"

t_error	sort(t_stacks *stacks, t_int_deque *ops_out)
{
	if (!stacks || !ops_out)
		return (ERROR_NULL_OUT_PARAM);
	if (stacks->a.sz <= 1)
	{
		*ops_out = deque_new();
		return (NO_ERROR);
	}
	if (stacks->a.sz == 2)
		return sort2(stacks, ops_out);
	return (radix_sort(stacks, ops_out));
}

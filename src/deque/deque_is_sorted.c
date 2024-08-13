/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:06 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:08 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"

bool	deque_is_sorted(t_int_deque dq)
{
	if (dq.sz <= 1)
		return (true);
	while (dq.head->next)
	{
		if (dq.head->val > dq.head->next->val)
			return (false);
		dq.head = dq.head->next;
	}
	return (true);
}

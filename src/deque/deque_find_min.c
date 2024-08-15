/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_find_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:59:57 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 13:00:31 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"
#include <limits.h>

int	deque_find_min(const t_int_deque *dq)
{
	int			i;
	int			min;
	int			index_of_min;
	t_int_list	*current;

	if (!dq || dq->sz == 0)
		return (-1);
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
	return (index_of_min);
}

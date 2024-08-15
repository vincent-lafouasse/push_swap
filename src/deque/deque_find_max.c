/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_find_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:31:04 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 13:32:00 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"
#include <limits.h>

int	deque_find_max(const t_int_deque *dq)
{
	int			i;
	int			max;
	int			index_of_max;
	t_int_list	*current;

	if (!dq || dq->sz == 0)
		return (-1);
	max = INT_MIN;
	i = 0;
	index_of_max = -1;
	current = dq->head;
	while (current)
	{
		if (current->val > max)
		{
			index_of_max = i;
			max = current->val;
		}
		current = current->next;
		i++;
	}
	return (index_of_max);
}

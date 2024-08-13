/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:21 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:21 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"
#include <stdlib.h>

void	deque_clear(t_int_deque *dq)
{
	t_int_list	*current;
	t_int_list	*buffer;

	if (!dq)
		return ;
	current = dq->head;
	while (current)
	{
		buffer = current->next;
		free(current);
		current = buffer;
	}
	dq->head = NULL;
	dq->tail = NULL;
	dq->sz = 0;
}

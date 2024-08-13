/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:11 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:12 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"

t_int_list	*deque_pop_front(t_int_deque *dq)
{
	t_int_list	*out;

	if (dq->sz == 0)
		return (NULL);
	if (dq->sz == 1)
	{
		out = dq->head;
		dq->head = NULL;
		dq->tail = NULL;
		dq->sz = 0;
	}
	else
	{
		out = dq->head;
		dq->head = out->next;
		dq->head->prev = NULL;
		dq->sz--;
	}
	out->next = NULL;
	out->prev = NULL;
	return (out);
}

t_int_list	*deque_pop_back(t_int_deque *dq)
{
	t_int_list	*out;

	if (dq->sz == 0)
		return (NULL);
	if (dq->sz == 1)
	{
		out = dq->tail;
		dq->head = NULL;
		dq->tail = NULL;
		dq->sz = 0;
	}
	else
	{
		out = dq->tail;
		dq->tail = out->prev;
		dq->tail->next = NULL;
		dq->sz--;
	}
	out->next = NULL;
	out->prev = NULL;
	return (out);
}

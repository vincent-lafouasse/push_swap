/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:30 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:31 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"

void	deque_push_front_link(t_int_deque *dq, t_int_list *link)
{
	if (!link || !dq)
		return ;
	if (dq->sz == 0)
	{
		dq->head = link;
		dq->tail = link;
		dq->sz++;
		return ;
	}
	link->next = dq->head;
	dq->head->prev = link;
	dq->head = link;
	dq->head->prev = NULL;
	dq->sz++;
}

void	deque_push_back_link(t_int_deque *dq, t_int_list *link)
{
	if (!link || !dq)
		return ;
	if (dq->sz == 0)
	{
		dq->head = link;
		dq->tail = link;
		dq->sz++;
		return ;
	}
	link->prev = dq->tail;
	dq->tail->next = link;
	dq->tail = link;
	dq->tail->next = NULL;
	dq->sz++;
}

bool	deque_push_front(t_int_deque *dq, t_i32 val)
{
	t_int_list	*link;

	link = list_new(val);
	if (!link)
		return (false);
	deque_push_front_link(dq, link);
	return (true);
}

bool	deque_push_back(t_int_deque *dq, t_i32 val)
{
	t_int_list	*link;

	link = list_new(val);
	if (!link)
		return (false);
	deque_push_back_link(dq, link);
	return (true);
}

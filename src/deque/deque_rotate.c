/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:43 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:44 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"

void	deque_rotate_push(t_int_deque *dq)
{
	t_int_list	*node;

	if (!dq || dq->sz == 0 || dq->sz == 1)
		return ;
	node = deque_pop_back(dq);
	deque_push_front_link(dq, node);
}

void	deque_rotate_pull(t_int_deque *dq)
{
	t_int_list	*node;

	if (!dq || dq->sz == 0 || dq->sz == 1)
		return ;
	node = deque_pop_front(dq);
	deque_push_back_link(dq, node);
}

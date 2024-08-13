/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:34 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:35 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"

const t_int_list	*deque_peek_front(const t_int_deque dq)
{
	return (dq.head);
}

const t_int_list	*deque_peek_back(const t_int_deque dq)
{
	return (dq.tail);
}

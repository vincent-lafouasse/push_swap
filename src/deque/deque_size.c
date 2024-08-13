/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:15 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:16 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"

bool	deque_is_empty(const t_int_deque dq)
{
	return (dq.sz == 0);
}

size_t	deque_size(const t_int_deque dq)
{
	return (dq.sz);
}
